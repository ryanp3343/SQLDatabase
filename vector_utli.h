#ifndef VECTOR_UTLI_H
#define VECTOR_UTLI_H
#include <iostream>
#include <vector>

using namespace std;
template <typename T>
ostream& operator<<(ostream& outs, const vector<T>& list)
{
    outs << '[' << ' ';
    for (size_t i = 0; i < list.size(); ++i)
    {
        outs << list[i];
        if (i < list.size() - 1)
        {
            outs << ',';
        }
        outs << ' ';
    }
    outs << ']';
    return outs;
}

template <typename T>
vector<T>& operator+=(vector<T>& list, const T& item)
{
    list.push_back(item);
    return list;
}


#endif // VECTOR_UTLI_H
