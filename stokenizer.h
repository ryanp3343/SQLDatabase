#ifndef STOKENIZER_H
#define STOKENIZER_H
#include "iostream"
#include "cstring"
#include "token.h"
#include "state_machine.h"

using namespace std;

class STokenizer {

public:
    STokenizer();
    STokenizer(const char* str);
    bool done() { return pos >= strlen(buffer); }
    bool fail() { return state = -1; }
    friend STokenizer& operator>>(STokenizer& s,Token& t);
    void set_string(const char* str);
    static const int MAX_BUFFER = 255;

private:
    static const int MAX_COLUMNS = 255;
    static const int NUM_ROWS = 255;
    int state_table[NUM_ROWS][MAX_COLUMNS];
    int state = 0;
    char buffer[MAX_BUFFER] = "";
    size_t pos = 0;
    void make_table(int state_table[][MAX_COLUMNS]);
    bool get_token(int start_state,string& token);

};

STokenizer::STokenizer()
{
    make_table(state_table);
}

STokenizer::STokenizer(const char* str)
{
    make_table(state_table);
    strcpy(buffer,str);
}

void STokenizer::make_table(int state_table[][MAX_COLUMNS])
{
    const char* ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-_";
    const char* NUMBERS = "1234567890";
    const char* PUNCTUATION = ",\\.?!;\"'()[]{}/";
    const char* COMPARISON = "<>";
    const char* WHITESPACE = " \t\n\r";

    //make and mark up for success and fail
    init_table(state_table);
    set_fail(state_table,0);
    set_success(state_table,1);
    set_success(state_table,2);
    set_success(state_table,3);
    set_fail(state_table,4);
    set_success(state_table,5);
    set_fail(state_table,6);
    set_success(state_table,7);
    set_fail(state_table,8);
    set_success(state_table,9);
    set_success(state_table,10);
    set_success(state_table,11);
    set_success(state_table,12);

    //alphabet
    mark_cells(0,state_table,ALPHA,1);
    mark_cells(1,state_table,ALPHA,1);
    mark_cells(2,state_table,ALPHA,-1);
    mark_cells(3,state_table,ALPHA,-1);
    mark_cells(4,state_table,ALPHA,-1);
    mark_cells(5,state_table,ALPHA,-1);
    mark_cells(6,state_table,ALPHA,1);

    //space like tabs and endlines
    mark_cells(0,state_table,WHITESPACE,2);
    mark_cells(1,state_table,WHITESPACE,-1);
    mark_cells(2,state_table,WHITESPACE,2);

    //numbers and punctiation
    mark_cells(0,state_table,NUMBERS,3);
    mark_cells(1,state_table,NUMBERS,1);
    mark_cells(2,state_table,NUMBERS,-1);
    mark_cells(3,state_table,NUMBERS,3);
    mark_cells(4,state_table,NUMBERS,3);
    mark_cells(10,state_table,NUMBERS,10);
    mark_cells(0,state_table,PUNCTUATION,5);
    mark_cell(0,state_table,'.',5);
    mark_cell(1,state_table,'.',-1);
    mark_cell(2,state_table,'.',-1);
    mark_cell(3,state_table,'.',10);
    mark_cell(4,state_table,'.',-1);
    mark_cell(5,state_table,'.',8);
    mark_cell(6,state_table,'.',-1);
    mark_cell(7,state_table,'.',-1);
    mark_cell(8,state_table,'.',9);
    mark_cell(0,state_table,'\'',6);
    mark_cell(1,state_table,'\'',6);
    mark_cells(0,state_table,COMPARISON,11);
    mark_cell(0,state_table,'=',12);
    mark_cell(11,state_table,'=',12);

}

bool STokenizer::get_token(int start_state,std::string& token)
{
    //gets a string that is in success
    size_t last_pos = pos;
    bool has_token = get_token2(buffer,pos,state_table,start_state);
    char _token[MAX_BUFFER] = "";
    strncpy(_token,buffer + last_pos,pos + 1 - last_pos);
    token = _token;
    pos += 1;
    return has_token;
}

void STokenizer::set_string(const char* str)
{
    pos = 0;
    state = 0;
    strcpy(buffer,str);
}

STokenizer& operator>>(STokenizer& s,Token& t)
{
    //extracts a token
    string str;
    s.get_token(s.state,str);
    int _state = 0;
    size_t _pos = 0;
    get_token2(str.c_str(),_pos,s.state_table,_state);
    t.set_type(_state);
    t.set_string(str);
    return s;
}



#endif // STOKENIZER_H
