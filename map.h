#ifndef MAP_H
#define MAP_H

#include "bptree.h"
#include "pair.h"

template <typename K, typename T>
class Map
{
public:

    class Iterator
    {
    public:
        friend class Map;
        Iterator(typename BPlusTree<Pair<K,T>>::Iterator it): iter(it) {}
        Iterator operator++(int unused)
        {
            Iterator tmp=iter;
            iter++;
            return tmp;
        }
        Iterator operator++()
        {
            iter++;
            return *this;
        }

        const T& operator*() { return iter->value; }
        T* operator->() { return &iter.operator->()->value; }

        friend bool operator==(const Iterator& left, const Iterator& right)
        {
            return left.iter == right.iter;
        }
        friend bool operator!=(const Iterator& left, const Iterator& right)
        {
            return left.iter != right.iter;
        }
        friend bool operator==(const Iterator& left, const T& right)
        {
              return *(left.iter) == right;
        }
        friend bool operator!=(const Iterator& left, const T& right)
        {
          return *(left.iter) != right;
        }
        friend bool operator==(const Iterator& left, nullptr_t)
        {
          return left.iter == nullptr;
        }
        friend bool operator!=(const Iterator& left, nullptr_t)
        {
          return left.iter != nullptr;
        }
        bool is_null() { return !iter; }

        K key() { return iter->key; }

    private:
        typename BPlusTree<Pair<K,T> >::Iterator iter;

    };

     Map();
     T get(const K& key) const;
     T& at(const K& key);
     T& operator[](const K& key);
     const T& operator[](const K& key) const;
     const T& at(const K& key) const;

     void set(const K& key, const T& value);
     void erase(const K& key);
     void clear() { map.clear_tree(); }

     Iterator begin() const;
     Iterator end() const;
     Iterator lower_bound(const K& entry) const;
     Iterator upper_bound(const K& entry) const;

     bool contains(const K& key, const T& value);
     bool contains(const K& key);
     int size(){return key_count;}

     friend ostream& operator<<(ostream& outs, const Map<K,T>& _map) {
         outs<<_map.map;
         return outs;
     }

private:
    int key_count=0;
    BPlusTree<Pair<K, T> > map;
};

template <typename K, typename T>
Map<K, T>::Map() {}

template <typename K, typename T>
void Map<K, T>::set(const K& key, const T& value)
{
    map.insert(Pair<K, T>(key, value));
    key_count++;
}

template <typename K, typename T>
T& Map<K, T>::operator[](const K& key)
{
    if (map.search(Pair<K, T>(key, T())) == nullptr)
    {
        map.insert(Pair<K, T>(key, T()));
        key_count++;
    }
    return map.search(Pair<K, T>(key, T()))->value;
}

template <typename K, typename T>
const T& Map<K, T>::operator[](const K& key) const
{
    return map.search(Pair<K, T>(key, T()))->value;
}

template <typename K, typename T>
T& Map<K, T>::at(const K& key)
{
    return map.search(Pair<K, T>(key, T()))->value;
}

template <typename K, typename T>
T Map<K, T>::get(const K& key) const
{
    return map.search(Pair<K, T>(key, T()))->value;
}

template <typename K, typename T>
const T& Map<K, T>::at(const K& key) const
{
   return map.search(key);
}

template <typename K, typename T>
void Map<K, T>::erase(const K& key)
{
    map.remove(key);
}
template <typename K, typename T>
bool Map<K, T>::contains(const K& key, const T& value)
{
    auto search = map.search(key);
    return search != nullptr && search->value == value;
}

template <typename K, typename T>
bool Map<K, T>::contains(const K& key)
{
    auto search = map.search(key);
    return search != nullptr;
}

template <typename K, typename T>
typename Map<K, T>::Iterator Map<K, T>::begin() const
{
   return Iterator(map.begin());
}

template <typename K, typename T>
typename Map<K, T>::Iterator Map<K, T>::end() const
{
   return Iterator(map.end());
}

template <typename K, typename T>
typename Map<K, T>::Iterator
Map<K, T>::lower_bound(const K& entry) const
{
   return Iterator(map.lower_bound(entry));
}

template <typename K, typename T>
typename Map<K, T>::Iterator Map<K, T>::upper_bound(const K& entry) const
{
    return Iterator(map.upper_bound(entry));
}

#endif // MAP_H
