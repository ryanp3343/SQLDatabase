#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <string>

using namespace std;

class Token
{
public:
    Token();
    Token(string str, int type);
    string type_string() const;
    int type() const {return _type;}
    string token_str() const {return _token;}
    void set_string(string str) {_token=str;}
    void set_type(int type) {_type=type;}

    friend ostream& operator<<(ostream& outs, const Token& t)
    {
        return outs<<t._token;
    }
    friend bool operator==(const Token& lhs, string rhs)
    {
        return lhs._token==rhs;
    }
    friend bool operator==(const Token& lhs, const Token& rhs)
    {
        return lhs._token==rhs._token;
    }
    friend bool operator!=(const Token& lhs, string rhs)
    {
        return lhs._token!=rhs;
    }
    friend bool operator!=(const Token& lhs, const Token& rhs)
    {
        return lhs._token==rhs._token;
    }
private:
    string _token;
    int _type;
};

Token::Token(): _token(""),_type(0){}

Token::Token(string str, int type): _token(str), _type(type){}

string Token::type_string() const
{
    switch(_type)
    {
        case 1:
        case 7:
        case 11:
            return "ALPHA";
        case 2:
            return "SPACE";
        case 3:
        case 10:
            return "NUMBER";
        case 5:
        case 6:
            return "PUNCTUATION";
        case 9:
            return "ELLIPSIS";
    default:
        return "UNKNOWN";
    }
}

#endif // TOKEN_H
