#ifndef MULTIMAP_H
#define MULTIMAP_H

#include "bptree.h"
#include "multipair.h"

template <typename K, typename T>
class MultiMap
{
public:
    class Iterator
    {
    public:
        friend class MultiMap;
        Iterator(typename BPlusTree<MPair<K,T>>::Iterator it): _it(it) {}
        vector<T> operator*(){return _it->values;}
        vector<T>* operator->(){return &_it.operator->()->values;}

        Iterator operator++(int unused)
        {
            Iterator temp=_it;
            _it++;
            return temp;
        }

        Iterator operator++()
        {
            _it++;
            return *this;
        }

        friend bool operator==(const Iterator& left, const Iterator& right)
        {
            return left._it==right._it;
        }
        friend bool operator!=(const Iterator& left, const Iterator& right)
        {
            return left._it!=right._it;
        }
        friend bool operator==(const Iterator& left, const T& right)
        {
            return *(left._it) == right;
        }
        friend bool operator!=(const Iterator& left, const T& right)
        {
            return *(left._it) != right;
        }
        friend bool operator==(const Iterator& left, nullptr_t)
        {
            return left._it == nullptr;
        }
        friend bool operator!=(const Iterator& left, nullptr_t)
        {
            return left._it != nullptr;
        }
        bool is_null() { return !_it; }

        K key() { return _it->key; }


    private:
        typename BPlusTree<MPair<K,T>>::Iterator _it;
    };

    MultiMap();

    vector<T>& at(const K& key);
    const vector<T>& at(const K& key)const;
    vector<T>& operator[](const K& key);
    const vector<T>& operator[](const K& key)const;

    void insert(const K& key, const T& value);
    void erase(const K& key);
    void clear(){mmap.clear_tree();}

    Iterator begin() const;
    Iterator end() const;
    Iterator lower_bound(const K& key) const;
    Iterator upper_bound(const K& key) const;

    bool contains(const K& key);
    vector<T>& get(const K& key);

    friend ostream& operator<<(ostream& outs, const MultiMap<K,T>& map)
    {
        map.mmap.print_as_list();
        return outs;
    }


private:
    BPlusTree<MPair<K,T> > mmap;

};

template <typename K, typename T>
MultiMap<K,T>::MultiMap(): mmap(true){}

template <typename K, typename T>
void MultiMap<K,T>::insert(const K& key, const T& value)
{
    mmap.insert(MPair<K,T>(key,value));
}

template <typename K, typename T>
vector<T>& MultiMap<K,T>::operator[](const K& key)
{
    return at(key);
}

template <typename K, typename T>
const vector<T>& MultiMap<K,T>::operator[](const K& key) const
{
    return mmap.search(key);

}

template <typename K, typename T>
vector<T>& MultiMap<K,T>::at(const K& key)
{
    if(mmap.search(MPair<K,T>(key,T()))==nullptr)
    {
        mmap.insert(MPair<K,T>(key));
    }
    return mmap.search(MPair<K,T>(key,T()))->values;
}

template <typename K, typename T>
const vector<T>& MultiMap<K,T>::at(const K& key) const
{
     return mmap.search(key);
}

template <typename K, typename T>
bool MultiMap<K,T>::contains(const K& key)
{
    return mmap.search(MPair<K,T>(key)) !=nullptr;
}

template <typename K, typename T>
vector<T>& MultiMap<K,T>::get(const K& key)
{
    return mmap.search(MPair<K,T>(key,T()))->values;
}

template <typename K, typename T>
void MultiMap<K,T>::erase(const K& key)
{
   mmap.remove(key);
}

template <typename K, typename T>
typename MultiMap<K,T>::Iterator MultiMap<K,T>::begin() const
{
    return Iterator(mmap.begin());
}

template <typename K, typename T>
typename MultiMap<K,T>::Iterator MultiMap<K,T>::end() const
{
   return Iterator(mmap.end());
}

template <typename K, typename T>
typename MultiMap<K,T>::Iterator MultiMap<K,T>::lower_bound(const K& entry) const
{
    return Iterator(mmap.lower_bound(entry));
}

template <typename K, typename T>
typename MultiMap<K,T>::Iterator MultiMap<K,T>::upper_bound(const K& entry) const
{
    return Iterator(mmap.upper_bound(entry));
}


#endif // MULTIMAP_H
