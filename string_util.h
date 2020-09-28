#ifndef STRING_UTIL_H
#define STRING_UTIL_H
#include <string>
#include <vector>

using namespace std;


//convert stirng to uppercase
string to_uppercase(string str)
{
    for(size_t i=0; i<str.size(); i++)
    {
        str[i]=toupper(str[i]);
    }
    return str;
}

//true if there is whitespace
bool blank_space(string str)
{
    for(char c: str)
    {
        if(!isspace(c))
        {
            return false;
        }
    }
    return true;
}


#endif // STRING_UTIL_H
