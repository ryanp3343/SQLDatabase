#ifndef SHUNTINGYARD_H
#define SHUNTINGYARD_H
#include <string>
#include <vector>
#include "queue.h"
#include "stack.h"
#include "string_util.h"
#include "map.h"

using namespace std;

Queue<string> infix_to_postfix(const vector<string>& infix)
{
    //operators in order of precedence
    Map<string,int> operators;
    operators["OR"] = 0;
    operators["AND"] = 1;
    operators[">"] = 2;
    operators[">="] = 2;
    operators["<"] = 2;
    operators["<="] = 2;
    operators["="] = 2;
    Stack<string> stack;
    Queue<string> queue;
    for(auto tokens : infix)
    {
        //push tokens to queue
        if(!operators.contains(to_uppercase(tokens)))
        {
            queue.push(tokens);
        }
        else
        {
            //comapare precedence
            while(!stack.empty() && operators[to_uppercase(stack.top())] >=operators[to_uppercase(tokens)])
            {
                queue.push(stack.pop());
            }
            stack.push(tokens);
        }
    }
    //take the rest of the stack to the queue
    while(!stack.empty())
    {
        queue.push(stack.pop());
    }
    return queue;
}



#endif // SHUNTINGYARD_H
