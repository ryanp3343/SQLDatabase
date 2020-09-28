#ifndef SQL_H
#define SQL_H
#include "parser.h"
#include "table.h"
#include <iostream>
#include <string>
#include <exception>

using namespace std;

class SQL
{
public:
    SQL();
    void interative();
    void exec_file(string filename);
    bool exec_string(string str, bool NUMBER=false);

private:
    const char* TABLES_FILE="tables.txt";
    Parser parser;
    Map<string, Table> tables;
    void get_table();
    void print_tables();


};

SQL::SQL()
{
    get_table();
    if(tables.contains(Table::NUMBER))
    {
        exec_string("DROP TABLE " +string(Table::NUMBER));
    }
}

void SQL::interative()
{

    string command;
    while(true)
    {
        outFile<<"SQL>";
        cout<<"SQL>";
        getline(cin,command);
        outFile<<command<<endl;
        exec_string(command);
    }
}

void SQL::exec_file(string filename)
{
    //opens the file and takes commands
    ifstream f;
    f.open(filename);
    string command;
    int j=0;
    for(int i=0; getline(f,command);)
    {
        if(command.size()>0 && (command.substr(0,2)=="//" || command.at(0)=='#'))
        {
            outFile<<command<<'\n';
            cout<<command<<'\n';
        }
        else if(command.size()==0 || blank_space(command))
        {

        }
        else
        {

            cout<<i++<<": "<<command<<endl;
            outFile<<j++<<": "<<command<<endl;
            exec_string(command,true);
        }
    }
    f.close();
}

void SQL::get_table()
{
    //creates a new file
    ofstream f;
    f.open(TABLES_FILE, ios::app);
    f.close();

    ifstream g;
    g.open(TABLES_FILE);
    string name;
    while(g>>name)
    {
        tables[name]=Table(name);
    }
    g.close();
}

void SQL::print_tables()
{
    //prints the tables
    int num=0;
    for(auto i=tables.begin(); i!=nullptr; i++, num++)
    {
        outFile<<setw(20)<<left<<i.key();
        cout<<setw(20)<<left<<i.key();
        if(num>0 && num%4==0)
        {
            outFile<<endl;
            cout<<endl;
        }
    }
    outFile<<endl;
    cout<<endl;
}


//takes in a command
bool SQL::exec_string(string command, bool temp)
{
    try
    {
        auto parse_tree = parser.parse(command);
        string cmd;
        string table_name;
        vector<string> fields;
        //put command in the parser and parse it
        if (parse_tree["command"].size() > 0)
        {
            cmd = parse_tree["command"][0];
        }
          //put command in the parser and parse it
        if (parse_tree["table_name"].size() > 0)
        {
            table_name = parse_tree["table_name"][0];
        }
          //put command in the parser and parse it
        if (parse_tree["fields"].size() > 0)
        {
            fields = parse_tree["fields"];
        }
        //select from table
        if (cmd == "SELECT")
        {
            if (!tables.contains(table_name))
            {
                outFile<<"Unknown Table"<<endl;
               cout<<"Unknown Table"<<endl;
            }
            else
            {
                tables[Table::NUMBER] = tables[table_name].select(fields, parse_tree["where"]);
                tables[Table::NUMBER].print_table() << '\n';
            }
        }
        //create a new table of fields
        else if (cmd == "CREATE" || cmd == "MAKE")
        {
            if (!tables.contains(table_name))
            {
                ofstream fout;
                fout.open(TABLES_FILE, ios::app);
                fout << '\n' << table_name;
                fout.close();
            }
            tables[table_name] = Table(table_name, fields);
            if (temp)
            {
                tables[table_name].print_table() << '\n';
            }
        }
        //insert into the table
        else if (cmd == "INSERT")
        {
            if (!tables.contains(table_name))
            {
                outFile<<"Unknown table"<<endl;
                cout<<"Unknown table"<<endl;
            }
            else
            {
                tables[table_name].insert_into(fields);
                if (temp)
                {
                    tables[table_name].print_table() << '\n';
                }
            }
        }
        //erase a table
        else if (cmd == "DROP")
        {
            if (tables.contains(table_name))
            {
                remove(tables[table_name].get_file().c_str());
                tables.erase(table_name);
                ofstream fout;
                fout.open(TABLES_FILE);
                for (auto it = tables.begin(); it != nullptr; ++it)
                {
                    fout << it.key() << '\n';
                }
                fout.close();
            }
            else
            {
               outFile<<"Unknown table"<<endl;
               cout<<"Unknown table"<<endl;
            }
        }
        //print the tables
        else if (cmd == "TABLES")
        {
            print_tables();
        }
        //exit the program
        else if (cmd == "EXIT")
        {
            if (tables.contains(Table::NUMBER))
            {
                exec_string("DROP TABLE " + string(Table::NUMBER));
            }

            exit(0);

        }
        //executes a file
        else if (cmd == "EXEC")
        {
            string filename = "";
            for (size_t i = 0; i < fields.size(); ++i)
            {
                if (fields[i] != "\"")
                {
                    filename += fields[i];
                }
            }
            exec_file(filename);
        }
        return true;
    } catch (runtime_error& e)
        {
            cerr << e.what() << '\n';
            return false;
        }

}
#endif // SQL_H
