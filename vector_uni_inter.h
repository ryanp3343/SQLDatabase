#ifndef VECTOR_UNI_INTER_H
#define VECTOR_UNI_INTER_H
#include "map.h"
#include <vector>
#include <algorithm>
#include <string>

template <typename T>
bool contains(vector<T> vec, T str) {
   for(int i = 0; i < vec.size(); ++i) {
       if(vec[i] == str) {
           return true;
       }
   }
   return false;
}

template <typename T>
vector<T> intersection(const vector<T>& v1, const vector<T>& v2)
{

    vector<T> vec;
    for(int i = 0; i < v1.size(); ++i)
    {
        if(contains(v2, v1[i]) && !contains(vec, v1[i]))
        {
            vec.push_back(v1[i]);
        }
    }
    return vec;


}

template <typename T>
vector<T> get_union(const vector<T>& v1, const vector<T>& v2)
{
    vector<T> _union;
    BPlusTree<T> tree;
    for(T i: v1)
    {
        tree.insert(i);
    }
    for(T i: v2)
    {
        tree.insert(i);
    }
    for(auto i=tree.begin();i!=nullptr; i++)
    {
        _union.push_back(*i);
    }
    return _union;


}

#endif // VECTOR_UNI_INTER_H
