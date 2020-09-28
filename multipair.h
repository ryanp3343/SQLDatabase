#ifndef MULTIPAIR_H
#define MULTIPAIR_H

#include <iostream>
#include <vector>
#include "vector_utli.h"


using namespace std;

template <typename K, typename T>
struct MPair
{
    K key;
    vector<T> values;
    MPair(const K& key=K()):key(key){}
    MPair(const K& key, const T& value): key(key)
    {
        values.push_back(value);
    }
    MPair(const K& key, const vector<T>& values):key(key)
    {
            this->values=values;
    }
    void operator +=(const T& item)
    {
        values.push_back(item);
    }
    void operator+=(const MPair& other)
    {
        for(int i=0; i<other.values.size(); i++)
        {
            values.push_back(other.values.at(i));
        }
    }


};

template <typename K, typename T>
ostream& operator<<(ostream& outs, const MPair<K,T>& pair)
{
    outs<<"{ "<<pair.key<<": [ ";
    for(int i=0; i<pair.values.size(); i++)
    {
        outs<<pair.values[i];
        if(i<pair.values.size()-1)
        {
            outs<< ',';
        }
        outs<<" ";
    }
    outs<<"] }";
    return outs;
}

template <typename K, typename T>
bool operator==(const MPair<K, T>& left, const MPair<K, T>& right)
{
    return left.key == right.key;
}

template <typename K, typename T>
bool operator!=(const MPair<K, T>& left, const MPair<K, T>& right)
{
    return left.key != right.key;
}

template <typename K, typename T>
bool operator<(const MPair<K, T>& left, const MPair<K, T>& right)
{
    return left.key < right.key;
}

template <typename K, typename T>
bool operator>(const MPair<K, T>& left, const MPair<K, T>& right)
{
    return left.key > right.key;
}

template <typename K, typename T>
bool operator<=(const MPair<K, T>& left, const MPair<K, T>& right)
{
    return left.key <= right.key;
}

template <typename K, typename T>
bool operator>=(const MPair<K, T>& left, const MPair<K, T>& right)
{
    return left.key >= right.key;
}


#endif // MULTIPAIR_H
