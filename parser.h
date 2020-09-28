#ifndef PARSER_H
#define PARSER_H

#include "map.h"
#include "multimap.h"
#include "sqlstatemachine.h"
#include "keywords.h"
#include "stokenizer.h"
#include <iostream>
#include <string>
#include "queue.h"
#include "output.h"

class Parser
{
public:
    Parser()
    {
        set_string("");
    }
    Parser(string input)
    {
        set_string(input);
    }

    MultiMap<string,string> parse(string input);

private:
    Queue<Token> tokens;
    STokenizer tokenizer;
    SQLStateMachine SQLState;
    void set_string(string input);

};

void Parser::set_string(string input)
{
    tokens.clear();
    tokenizer.set_string(input.c_str());
    Token t;
    while(!tokenizer.done())
    {
        tokenizer>>t;
        tokens.push(t);
    }

}

MultiMap<string,string> Parser::parse(string input)
{
    MultiMap<string, string> mmap;
    set_string(input);
    SQLState.reset_state();
    int last_state = SQLState.get_state();
    //queue of tokens
    while (!tokens.empty())
    {
        //pop the token
        Token t = tokens.pop();

        while (!tokens.empty() && isspace(t.token_str()[0]))
        {
            t = tokens.pop();
        }
        if (isspace(t.token_str()[0]))
        {
            break;
        }
        string token_string = t.token_str();
        //update the state of the toekn
        last_state =SQLState.fix_state(token_string);
        //grab everything inside the quote
        if (SQLState.is_quote_state(last_state))
        {
            token_string = "";
            while (!tokens.empty() && SQLState.is_quote_state(last_state))
            {
                string temp = tokens.pop().token_str();
                last_state = SQLState.fix_state(temp);
                //add until the end of the quote
                if (temp != "\"")
                {
                    token_string +=temp;
                }
            }
            if (SQLState.is_quote_state(last_state))
            {
                outFile<<"No closing quote"<<endl;
                cout<<"No closing quote"<<endl;
            }
        }

        //make sure the token is valid
        if (SQLState.is_invalid())
        {
            outFile<<"Unexpected Token: "<<token_string<<endl;
            cout<<"Unexpected Token: "<<token_string<<endl;
        }
        else
        {
            //token is a command and put it into multimap
            string key = SQLState.get_key(last_state);
            if (key != "")
            {
                if (key == "command")
                {
                    mmap[key] += to_uppercase(token_string);
                }
                else
                {
                    mmap[key] += token_string;
                }
            }
        }
    }
    //make sure end of input is correct
    if (SQLState.is_invalid() || !SQLState.is_success1())
    {
        outFile<<"Incorrect end of input"<<endl;
        cout<<"Incorrect end of input"<<endl;
    }

    return mmap;
}

#endif // PARSER_H
