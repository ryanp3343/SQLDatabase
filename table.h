#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <string>
#include "map.h"
#include "multimap.h"
#include "const.h"
#include "shuntingyard.h"
#include "record.h"
#include <fstream>
#include <vector>
#include <iomanip>
#include "vector_uni_inter.h"
#include "cassert"
#include "output.h"

using namespace std;

class Table
{
public:

    Table();
    Table(string name);
    Table(string name,const vector<string>& columns);

    void insert_into(const vector<string>& fields);
    Table select(const vector<string>& fields, const vector<string>& where);
    void init_file();
    string get_file() const;

    friend ostream& operator<<(ostream& outs, const Table& table)
    {
        outs<<&table;
        return outs;
    }
    ostream& print_table(ostream& outs=cout);
    static const char* NUMBER;

private:

    string name;
    vector<string> columns;
    Map<string,size_t>  field_map;
    Map<string,MultiMap<string,long>> index;
    void reindex();
    bool read();
    vector<long> where(Queue<string>& where);
    vector<long> less(string s1, string s2);
    vector<long> greater(string s1, string s2);
    vector<long> equal(string s1, string s2);
    vector<long> greater_equal(string s1, string s2);
    vector<long> less_equal(string s1, string s2);

};

const char* Table::NUMBER= "num";

Table::Table(): name(""){}

Table::Table(string name, const vector<string>& columns)
{
    this->name=name;
    this->columns=columns;
    init_file();
    read();
}

Table::Table(string name): name(name)
{

    read();
    reindex();
}

void Table::insert_into(const vector<string> &fields)
{

    fstream f;
    open_fileW(f,get_file().c_str());
    Record r;
    //open the file and make a vector
    r.create_vector(fields);
    long record_num=r.append_file(f);
    //append to file and reindex it
    for(size_t i=0; i<columns.size(); i++)
    {
        index[columns[i]][r.buffer[i]] += record_num;
    }
    f.close();

}

bool Table::read()
{
    fstream f;
    open_fileRW(f,get_file().c_str());
    //open file read it in and create a vector
    if(f.peek() != ifstream::traits_type::eof())
    {
        Record r;
        r.read(f,0);
        columns=r.to_vector();
    }
    //put columns in a mmap
    for(size_t i=0; i<columns.size(); i++)
    {
        field_map[columns[i]]=i;
    }
    f.close();
    return !f.fail();
}

void Table::init_file()
{
    remove(get_file().c_str());
    fstream f;
    open_fileW(f,get_file().c_str());
    Record r;
    r.create_vector(columns);
    r.write(f,0);
    f.close();
}

string Table::get_file() const
{
    return (name + ".db");
}

void Table::reindex()
{
    fstream f;
    f.open(get_file());
    Record r;
    //open file and reindex
    for(long i=1; r.read(f,i)>0; i++)
    {
        r.read(f,i);
        auto rows=r.to_vector();
        MultiMap<string,long> mmap;
        for(size_t j=0; j<columns.size(); j++)
        {
            index[columns[j]].insert(rows[j],i);
        }
    }

    f.close();
}

vector<long> Table::less(string s1, string s2)
{
    //vector where s1 is less than s2
    vector<long> results;
    MultiMap<string,long> _index=index[s1];
    for(auto i=_index.begin(); i != _index.lower_bound(s2); i++)
    {
        for (size_t j=0; j<i->size(); j++)
        {
            results.push_back(i->at(j));
        }
    }
    return results;
}

vector<long> Table::greater(string s1, string s2)
{
    //vector where s1 is greater than s2
    vector<long> results;
    for(auto i=index[s1].upper_bound(s2); i!=nullptr; i++)
    {
        for(size_t j=0; j<i->size(); j++)
        {
            results.push_back(i->at(j));
        }
    }
    return results;
}

vector<long> Table::equal(string s1, string s2)
{
    //vector where s1 is equal than s2
    vector<long> results;
    if(index[s1].contains(s2))
    {
        for(size_t i=0; i<index[s1][s2].size(); i++)
        {
            results.push_back(index[s1][s2][i]);
        }
    }
    return results;
}

vector<long> Table::less_equal(string s1, string s2)
{
    //vector where s1 is less than or equal s2
    vector<long> results;
    MultiMap<string,long> _index=index[s1];
    for(auto i=_index.begin(); i != _index.upper_bound(s2); i++)
    {
        for(size_t j=0; j<i->size(); j++)
        {
            results.push_back(i->at(j));
        }
    }
    return results;
}

vector<long> Table::greater_equal(string s1, string s2)
{
    //vector where s1 is greater than or equal s2
    vector<long> results;
    for(auto i=index[s1].lower_bound(s2); i!= nullptr; i++)
    {
        for(size_t j=0; j<i->size(); j++)
        {
            results.push_back(i->at(j));
        }
    }
    return results;
}

vector<long> Table::where(Queue<string> &where)
{
    Stack<vector<long>> results;
    while(!where.empty())
    {
        //push operator and where to evaluate in stack and return it
        if(to_uppercase(where.front())!="AND" && to_uppercase(where.front()) != "OR")
        {
            string s1=where.pop();
            string s2=where.pop();
            string oper=where.pop();
            if(oper=="=")
            {
                results.push(equal(s1,s2));
            }
            else if(oper== "<")
            {
                results.push(less(s1,s2));
            }
            else if(oper==">")
            {
                results.push(greater(s1,s2));
            }
            else if(oper=="<=")
            {
                results.push(less_equal(s1,s2));
            }
            else if(oper==">=")
            {
                results.push(greater_equal(s1,s2));
            }
        }
        else
        {
            string word=where.pop();
            if(to_uppercase(word)=="AND")
            {
                results.push(intersection(results.pop(),results.pop()));
            }
            else if(to_uppercase(word)=="OR")
            {
                results.push(get_union(results.pop(),results.pop()));
            }
        }
    }
    if(!results.empty())
    {
        return results.pop();
    }
    else
    {
        return vector<long>();
    }

}

Table Table::select(const vector<string> &fields, const vector<string> &at)
{
    if(!file_exists(get_file().c_str()))
    {
        cout<<"no table"<<endl;
    }
    fstream f;
    open_fileRW(f,get_file().c_str());
    vector<long> indx;
    Queue<string> queue=infix_to_postfix(at);
    indx=where(queue);

    if(fields[0]=="*")
    {
        Table temp(NUMBER,columns);
        Record r;
        //insert resluts to .db
        if(indx.size()>0 || at.size()>0)
        {
            for(size_t i=0; i<indx.size(); i++)
            {
                r.read(f,indx[i]);
                temp.insert_into(r.to_vector());
            }
        }
        else
        {
            //inserts results to. db
            for(int i=1; r.read(f,i)>0; i++)
            {
                r.read(f,i);
                temp.insert_into(r.to_vector());
            }
        }
        f.close();
        return temp;
    }
    else
    {
        Table temp(NUMBER,fields);
        Record r;
        if(indx.size()>0 || at.size()>0)
        {
            for(size_t i=0; i<indx.size(); i++)
            {
                //inserts the row to file
                vector<string> row;
                r.read(f,indx[i]);
                for(size_t j=0; j<fields.size(); j++)
                {
                    row.push_back(r.buffer[field_map[fields[j]]]);
                }
                temp.insert_into(row);
            }
        }
        else
        {
            for(long i=1; r.read(f,i)>0; i++)
            {
                //inserts the row to file
                vector<string> row;
                r.read(f,i);
                for(size_t j=0; j<fields.size(); j++)
                {
                    row.push_back(r.buffer[field_map[fields[j]]]);
                }
                temp.insert_into(row);
            }
        }
        f.close();
        return temp;
    }

}

ostream& Table::print_table(ostream &outs)
{
    fstream file_stream;
    Record t;
    open_fileRW(file_stream, get_file().c_str());
    outFile<<setw(8)<<left<<"record";
    outs <<setw(8)<<left<<"record";
    for (auto e : columns)
    {
        outFile<<setw(8)<<left;
        outFile<<e;
        outs << setw(20)<<left;
        outs << e;
    }
    outFile<<'\n';
    outFile<<'\n';
    outs<<'\n';
    outs << '\n';


    Record r;
    MultiMap<string, long> sorted = index[columns[0]];
    int num = 0;
    for (auto i = sorted.begin(); i != nullptr; ++i)
    {
        for (size_t j = 0; j < i->size(); ++j, ++num)
        {
            outFile<<setw(8)<<left<<num;
            outs<<setw(8)<<left << num;
            r.read(file_stream, i->at(j));
            auto row = r.to_vector();
            for (size_t z = 0; z < row.size(); ++z)
            {
                outFile<<setw(20)<<left;
                outFile<<row[z];
                outs << setw(20) << left;
                outs << row[z];
            }
            outFile<<'\n';
            outs << '\n';
        }
    }
    outs<<"SQL: DONE."<<'\n';
    file_stream.close();
    return outs;
}


#endif // TABLE_H
