#ifndef SQLSTATEMACHINE_H
#define SQLSTATEMACHINE_H

#include "state_machine.h"
#include "token.h"
#include "keywords.h"
#include "map.h"
#include "string_util.h"
#include <iostream>


class SQLStateMachine {

public:
    SQLStateMachine();
    int fix_state(string token);
    int get_state() { return last_state; }
    void reset_state(){last_state=0;}
    bool is_success1(){return is_success(state_table,last_state);}
    bool is_fail(){return !is_success(state_table,last_state);}
    bool is_invalid(){ return last_state == -1; }
    bool is_quote_state(int state){return quote_states.search(state) != nullptr;}
    bool is_parse_state(int state){return parse_states.contains(state);}
    string get_key(int state)
    {
        if (parse_states.contains(state))
        {
            return parse_states[state];
        }
        else
        {
            return "";
        }
    }
private:
    Map<string,Keywords> keywords;
    int state_table[MAX_ROWS][MAX_COLUMNS];
    int last_state = 0;
    Map<int,string> parse_states;
    BPlusTree<int> quote_states;

};

int SQLStateMachine::fix_state(string token) {
    Keywords type = STRING;
    //make the token uppercase
    token = to_uppercase(token);
    //add to map
    if (keywords.contains(token))
    {
        type = keywords[token];
    }
    last_state = state_table[last_state][type];
    return last_state;
}

SQLStateMachine::SQLStateMachine() {

    //map of the keywords that are enumerated
    keywords["*"] = ASTERISK;
    keywords[","] = COMMA;
    keywords["("] = OPEN_PARENTH;
    keywords[")"] = CLOSED_PARENTH;
    keywords["="] = RELATIONAL_OPERATOR;
    keywords[">"] = RELATIONAL_OPERATOR;
    keywords["<"] = RELATIONAL_OPERATOR;
    keywords["<="] = RELATIONAL_OPERATOR;
    keywords[">="] = RELATIONAL_OPERATOR;
    keywords["AND"] = LOGICAL_OPERATOR;
    keywords["OR"] = LOGICAL_OPERATOR;
    keywords["MAKE"] = CREATE;
    keywords["CREATE"] = CREATE;
    keywords["FIELDS"] = FIELDS;
    keywords["INSERT"] = INSERT;
    keywords["SELECT"] = SELECT;  
    keywords["INTO"] = INTO;
    keywords["FROM"] = FROM;
    keywords["WHERE"] = WHERE;  
    keywords["VALUES"] = VALUES;
    keywords["DROP"] = DROP;
    keywords["TABLES"] = LIST_TABLES;
    keywords["TABLE"] = TABLE;
    keywords["EXIT"] = EXIT;
    keywords["EXEC"] = EXEC;
    keywords["\""] = QUOTE;


    //make and mark up the table
    init_table(state_table);
    set_fail(state_table,0);
    set_fail(state_table,1);
    set_fail(state_table,2);
    set_fail(state_table,3);
    set_fail(state_table,4);
    set_fail(state_table,5);
    set_success(state_table,6);
    set_fail(state_table,7);
    set_fail(state_table,8);
    set_fail(state_table,9);
    set_fail(state_table,10);
    set_success(state_table,11);
    set_fail(state_table,12);
    set_fail(state_table,13);
    set_fail(state_table,14);
    set_fail(state_table,15);
    set_fail(state_table,16);
    set_fail(state_table,17);
    set_success(state_table,17);
    set_fail(state_table,18);
    set_success(state_table,19);
    set_fail(state_table,20);
    set_fail(state_table,21);
    set_fail(state_table,22);
    set_fail(state_table,23);
    set_fail(state_table,24);
    set_fail(state_table,25);
    set_success(state_table,25);
    set_fail(state_table,26);
    set_success(state_table,27);
    set_fail(state_table,28);
    set_fail(state_table,29);
    set_fail(state_table,30);
    set_success(state_table,31);
    set_success(state_table,32);
    set_fail(state_table,33);
    set_fail(state_table,50);
    set_success(state_table,51);

    //map of commands
    parse_states[1] ="command";
    parse_states[2] = "fields";
    parse_states[3] = "fields";
    parse_states[6] = "table_name";
    parse_states[9] = "where";
    parse_states[10] = "where";
    parse_states[11] = "where";
    parse_states[12] = "where";
    parse_states[13] = "command";
    parse_states[15] = "table_name";
    parse_states[17] = "fields";
    parse_states[20] = "command";
    parse_states[22] = "table_name";
    parse_states[25] = "fields";
    parse_states[29] = "command";
    parse_states[31] = "table_name";
    parse_states[32] = "command";
    parse_states[50] = "command";
    parse_states[51] = "fields";

    //tree of quotations
    quote_states.insert(33);
    quote_states.insert(34);
    quote_states.insert(35);
    quote_states.insert(36);
    quote_states.insert(37);
    quote_states.insert(38);
    quote_states.insert(39);
    quote_states.insert(40);
    quote_states.insert(41);
    quote_states.insert(42);
    quote_states.insert(43);
    quote_states.insert(44);
    quote_states.insert(45);
    quote_states.insert(46);
    quote_states.insert(47);
    quote_states.insert(48);
    quote_states.insert(49);


    //mark the cells needed for the key words
    mark_cell(0,state_table,SELECT,1);
    mark_cell(0,state_table,CREATE,13);
    mark_cell(0,state_table,INSERT,20);
    mark_cell(0,state_table,DROP,29);
    mark_cell(0,state_table,LIST_TABLES,32);
    mark_cell(0,state_table,EXIT,32);
    mark_cell(0,state_table,EXEC,50);
    mark_cell(1,state_table,ASTERISK,2);
    mark_cell(1,state_table,STRING,3);
    mark_cell(2,state_table,FROM,5);
    mark_cell(3,state_table,FROM,5);
    mark_cell(3,state_table,COMMA,4);
    mark_cell(4,state_table,STRING,3);
    mark_cell(5,state_table,STRING,6);
    mark_cell(5,state_table,QUOTE,33);
    mark_cell(6,state_table,WHERE,8);
    mark_cell(8,state_table,STRING,9);
    mark_cell(8,state_table,QUOTE,35);
    mark_cell(9,state_table,RELATIONAL_OPERATOR,10);
    mark_cell(10,state_table,STRING,11);
    mark_cell(10,state_table,QUOTE,37);
    mark_cell(11,state_table,LOGICAL_OPERATOR,12);
    mark_cell(12,state_table,STRING,9);
    mark_cell(12,state_table,QUOTE,35);
    mark_cell(13,state_table,TABLE,14);
    mark_cell(13,state_table,QUOTE,40);
    mark_cell(14,state_table,STRING,15);
    mark_cell(15,state_table,OPEN_PARENTH,16);
    mark_cell(15,state_table,QUOTE,42);
    mark_cell(15,state_table,FIELDS,28);
    mark_cell(16,state_table,QUOTE,42);
    mark_cell(16,state_table,STRING,17);
    mark_cell(17,state_table,CLOSED_PARENTH,19);
    mark_cell(17,state_table,COMMA,18);
    mark_cell(18,state_table,STRING,17);
    mark_cell(18,state_table,QUOTE,42);
    mark_cell(20,state_table,INTO,21);
    mark_cell(20,state_table,QUOTE,48);
    mark_cell(20,state_table,QUOTE,44);
    mark_cell(21,state_table,STRING,22);
    mark_cell(22,state_table,VALUES,23);
    mark_cell(23,state_table,OPEN_PARENTH,24);
    mark_cell(23,state_table,QUOTE,46);
    mark_cell(23,state_table,STRING,25);
    mark_cell(24,state_table,STRING,25);
    mark_cell(24,state_table,QUOTE,46);
    mark_cell(24,state_table,CLOSED_PARENTH,27);
    mark_cell(25,state_table,CLOSED_PARENTH,27);
    mark_cell(25,state_table,COMMA,26);
    mark_cell(26,state_table,STRING,25);
    mark_cell(26,state_table,QUOTE,46);
    mark_cell(28,state_table,STRING,17);
    mark_cell(29,state_table,TABLE,30);
    mark_cell(30,state_table,STRING,31);
    mark_all(33,state_table,34);
    unmark_cell(33,state_table,QUOTE);
    mark_all(34,state_table,34);
    unmark_cell(34,state_table,QUOTE);
    mark_cell(34,state_table,QUOTE,6);
    mark_all(35,state_table,36);
    unmark_cell(35,state_table,QUOTE);
    mark_all(36,state_table,36);
    unmark_cell(36,state_table,QUOTE);
    mark_cell(36,state_table,QUOTE,9);
    mark_all(37,state_table,38);
    unmark_cell(37,state_table,QUOTE);
    mark_all(38,state_table,38);
    unmark_cell(38,state_table,QUOTE);
    mark_cell(38,state_table,QUOTE,11);
    mark_all(40,state_table,41);
    unmark_cell(40,state_table,QUOTE);
    mark_all(41,state_table,41);
    unmark_cell(41,state_table,QUOTE);
    mark_cell(41,state_table,QUOTE,15);
    mark_all(42,state_table,43);
    unmark_cell(42,state_table,QUOTE);
    mark_all(43,state_table,43);
    unmark_cell(43,state_table,QUOTE);
    mark_cell(43,state_table,QUOTE,17);
    mark_all(44,state_table,45);
    unmark_cell(44,state_table,QUOTE);
    mark_all(45,state_table,45);
    unmark_cell(45,state_table,QUOTE);
    mark_cell(45,state_table,QUOTE,22);
    mark_all(46,state_table,47);
    unmark_cell(46,state_table,QUOTE);
    mark_all(47,state_table,47);
    unmark_cell(47,state_table,QUOTE);
    mark_cell(47,state_table,QUOTE,25);
    mark_all(48,state_table,49);
    unmark_cell(48,state_table,QUOTE);
    mark_all(49,state_table,49);
    unmark_cell(49,state_table,QUOTE);
    mark_cell(49,state_table,QUOTE,31);
    mark_all(50,state_table,51);
    mark_all(51,state_table,51);



}


#endif // SQLSTATEMACHINE_H
