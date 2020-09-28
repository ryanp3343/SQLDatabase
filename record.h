#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cstring>
#include "const.h"
using namespace std;

bool file_exists(const char* filename[]);

void open_fileRW(fstream& f, const char* filename[]);
void open_fileW(fstream& f, const char* filename[]);

struct Record
{
    Record()
    {
        clear_record();
        record_num=-1;

    }
    //append block of data to the file
    long append_file(fstream & outs)
    {
        outs.seekp(0,ios::end);
        long pos=outs.tellp()/(row* col);
        for(int i=0; i<row; i++)
        {
            outs.write(buffer[i],col);
        }
        return pos;
    }
    //wirtes data to index in the file
    long write(fstream& outs, long index)
    {
        outs.seekp(row*col* index, ios::beg);
        for(int i=0; i<row; i++)
        {
            outs.write(buffer[i],col);
        }
    }
    //reads in from the index of a file
    long read(fstream & ins, long record_num)
    {
        clear_record();
        this->record_num=record_num;
        ins.seekg(row*col*record_num);
        for(int i=0; i<row; i++)
        {
            ins.read(buffer[i],col);
        }
        return ins.gcount();
    }
    //write to the first row of the buffer
    bool write_row(const char* str)
    {
        for(int i=0; i<row; i++)
        {
            if(buffer[i][0]=='\0')
            {
                strcpy(buffer[i],str);
                return true;
            }
        }
        return false;
    }
    //clears data from buffer
    void clear_record()
    {
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                buffer[i][j]='\0';
            }
        }
    }
    //takes the data and copys to a vector
    vector<string> to_vector()
    {
        vector<string> _row;
        for(int i=0;  i<row && buffer[i][0] != '\0'; i++)
        {
            char temp[col]="";
            strcpy(temp,buffer[i]);
            _row.push_back(temp);
        }
        return _row;
    }

    //makes the buffer for the vector
    void create_vector(const vector<string>& items)
    {
        clear_record();
        if(items.size()>col)
        {

        }
        for(size_t i=0;i<items.size(); i++)
        {
            write_row(items.at(i).c_str());
        }
    }

    friend ostream& operator<<(ostream& outs, const Record& r)
    {
        for(int i=0; i<r.row; i++)
        {
            for(int j=0; j<r.col; j++)
            {
                outs<<r.buffer[i][j];
            }
            outs<<'\n';
        }
        return outs;
    }

    int record_num;
    static const int row=CONST_MAX_ROWS;
    static const int col=CONST_MAX_COLS;
    char buffer[row][col];

};

//true if file exists
bool file_exists(const char* filename)
{
    fstream f;
    f.open(filename, fstream::in | fstream::binary);
    if(f.fail())
    {
        cout<<"file does not exist "<< filename<<endl;
        return false;
    }
    f.close();
    return true;

}
//opens the file for read and write
void open_fileRW(fstream& f, const char* filename)
{
    if(!file_exists(filename))
    {
        f.open(filename,fstream::out | fstream::binary);
        if(f.fail())
        {
            cout << "file open (RW) failed: with out|" << filename << "]"<< endl;
        }
    }
    else
    {
        f.open(filename,fstream::in | fstream::out | fstream::binary);
        if(f.fail())
        {
            cout << "file open (RW) failed. [" << filename << "]" << endl;
        }
    }
}
//opnes the file to write
void open_fileW(fstream& f, const char* filename)
{
    f.open(filename, fstream::out | fstream::binary | ios::app);
    if(f.fail())
    {
        cout << "file open failed: " << filename << endl;
    }
}

#endif // RECORD_H
