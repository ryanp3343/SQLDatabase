#ifndef PAIR_H
#define PAIR_H

#include <iostream>
using namespace std;

template <typename K, typename V>
struct Pair {
    K key;
    V value;
    Pair(const K& key = K(), const V& value = V()) : key(key), value(value) {}
    void operator+=(const Pair& other);
};

template <typename K, typename V>
ostream& operator<<(ostream& outs, const Pair<K, V>& pair) {
    outs << "{ " << pair.key << ": " << pair.value << " }";
    return outs;
}

template <typename K, typename V>
bool operator==(const Pair<K, V>& left, const Pair<K, V>& right) {
    return left.key == right.key;
}

template <typename K, typename V>
bool operator!=(const Pair<K, V>& left, const Pair<K, V>& right) {
    return left.key != right.key;
}

template <typename K, typename V>
bool operator<(const Pair<K, V>& left, const Pair<K, V>& right) {
    return left.key < right.key;
}

template <typename K, typename V>
bool operator>(const Pair<K, V>& left, const Pair<K, V>& right) {
    return left.key > right.key;
}

template <typename K, typename V>
bool operator<=(const Pair<K, V>& left, const Pair<K, V>& right) {
    return left.key <= right.key;
}

template <typename K, typename V>
bool operator>=(const Pair<K, V>& left, const Pair<K, V>& right) {
    return left.key >= right.key;
}

template <typename K, typename V>
void Pair<K, V>::operator+=(const Pair&)
{

}

#endif // PAIR_H
