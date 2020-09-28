#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H
#include "iostream"

using namespace std;

const int MAX_COLUMNS=255;
const int MAX_ROWS=255;

//make the table
void init_table(int _table[][MAX_COLUMNS])
{
    for(int i=0; i<MAX_ROWS; i++)
    {
        for(int j=0; j<MAX_COLUMNS; j++)
        {
            _table[i][j]=-1;
        }
    }
}

//set the row to 1
void set_success(int _table[][MAX_COLUMNS],int state)
{
    _table[state][0]=1;
}

//set the row to 0
void set_fail(int _table[][MAX_COLUMNS],int state)
{
    _table[state][0]=0;
}

//true if that state is in success
bool is_success(int _table[][MAX_COLUMNS],int state)
{
    return _table[state][0]==1;
}

//marks up a range of cells
void mark_cells(int row, int _table[][MAX_COLUMNS], int from, int to, int state)
{
    for(int i=from; i<=to; i++)
    {
        _table[row][i]=state;
    }
}

//marks up by a string
void mark_cells(int row, int _table[][MAX_COLUMNS], const char columns[], int state)
{
    for(int i=0; columns[i]!= '\0'; i++)
    {
        _table[row][static_cast<int>(columns[i])]=state;
    }
}

//marks specific row and coloumn
void mark_cell(int row, int _table[][MAX_COLUMNS], int column, int state)
{
    _table[row][column]=state;
}

//mark the whole row
void mark_all(int row, int _table[][MAX_COLUMNS], int state)
{
    for(int i=1; i<MAX_COLUMNS; i++)
    {
        _table[row][i]=state;
    }
}
//
void unmark_cell(int row, int _table[][MAX_COLUMNS], int column)
{
    _table[row][column]=-1;
}

void print_table(int _table[][MAX_COLUMNS])
{
    for(int i=0; i<MAX_ROWS; i++)
    {
        for(int j=0; j<MAX_COLUMNS; j++)
        {
            cout<<_table[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool get_token2(const char* str, size_t& pos, int table[][MAX_COLUMNS], int& state)
{
    int _pos=pos;
    bool found=false;
    //true if token is valid and goes until token is not valid
    while (str[_pos] != '\0' && state != -1)
    {
        state=table[state][static_cast<int>(str[_pos])];
        if(is_success(table,state))
        {
            pos=_pos;
            found=true;
        }
        ++_pos;
    }
    return found;
}

#endif // STATE_MACHINE_H
