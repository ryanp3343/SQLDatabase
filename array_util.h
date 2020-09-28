#ifndef ARRAY_UTIL_H
#define ARRAY_UTIL_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
//larger of two items
T maximal(const T& a, const T& b)
{
    if(a>b)
    {
        return a;
    }
    else {
        return b;
    }

}
//swap two items
template <typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    a = temp;
}
//index of the larger item
template <typename T>
int index_of_maximal(T data[], int size)
{
    int max = 0;
    for (int i = 0; i < size; i++)
    {
        if (data[i] > data[max])
        {
            max = i;
        }
    }
    return max;
}

//insert item at index
template <typename T>
void insert_item(T data[], int pos, int& size, const T& entry)
{
    for (int i = size++; i > pos; i--)
    {
        data[i] = data[i - 1];
    }
    data[pos] = entry;
}

//insert into a sorted array
template <typename T>
void ordered_insert(T data[], int& size, const T& entry)
{
    int pos = 0;
    for (int i = 0; i < size; i++)
    {
        if (entry > data[i])
        {
            pos = i + 1;
        }
    }
    insert_item(data, pos, size, entry);
}

//first element that is greater than entry
template <typename T>
int first_ge(const T data[], int size, const T& entry)
{
    for (int i = 0; i < size; i++)
    {
        if (data[i] >= entry)
        {
            return i;
        }
    }
    return size;
}

//attach to end of data
template <typename T>
void attach_item(T data[], int& size, const T& entry)
{
    data[size++] = entry;
}

//remove last element of data
template <typename T>
T detach_item(T data[], int& size)
{
    T item = data[size - 1];
    data[size] = T();
    data[--size] = T();
    return item;
}

//deletes and shifts array
template <typename T>
T delete_item(T data[], int index, int& size)
{
    T item = data[index];
    for (int i = index; i < size - 1; i++)
    {
        data[i] = data[i + 1];
    }
    data[size] = T();
    data[--size] = T();
    return item;
}

//merge data1 to the end of data2
template <typename T>
void merge(T data1[], T data2[], int& size1, int& size2)
{
    for (int i = 0; i < size2; i++)
    {
        attach_item(data1, size1, data2[i]);
    }
}

//split data of data1 and move it to data2
template <typename T>
void split(T data1[], int& size1, T data2[], int& size2)
{
    int size = size1;
    for (int i = ((size + 1) / 2); i < size; i++)
    {
        data2[i - ((size + 1) / 2)] = data1[i];
    }
    size1 = (size + 1) / 2;
    size2 = size - size1;
}

//copy array to another
template <typename T>
void copy_array(const T src[], T dest[], int src_size, int& dest_size)
{
    for (int i = 0; i < src_size; i++)
    {
        dest[i] = src[i];
    }
    dest_size = src_size;
}

//print the array
template <typename T>
void print_array(const T data[], int size, int level = 0, ostream& outs = cout)
{
    int SPACING = 8;
    outs << string(level * SPACING, ' ');
    outs << '[' << ' ';
    for (int i = 0; i < size; i++) {
        outs << data[i] << " ";
    }
    outs << ']';
}

//item is greater that data
template <typename T>
bool is_gt(const T data[], int size, const T& item)
{
    for (int i = 0; i < size; i++)
    {
        if (item<data[i] || item==data[i])
        {
            return false;
        }
    }
    return true;
}

//item is less than the data
template <typename T>
bool is_le(const T data[], int size, const T& item)
{
    for (int i = 0; i < size; i++) {
        if (item>data[i])
        {
            return false;
        }
    }
    return true;
}

#endif // ARRAY_UTIL_H
