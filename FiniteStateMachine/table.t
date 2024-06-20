#pragma once
#include <iostream>
#include <string>
using namespace std;




template < class Key, typename T >
void  Table<Key,T>::print() {
    for (int i = 0; i < tableSize; i++)
    {
        cout << the_table[i].first << " " << the_table[i].second << endl;;
        
    }
}



template < class Key, typename T >
Table<Key, T>::Table(int n, int (*map)(Key k)) {

    tableSize = n;

    the_table = new Pair<Key, T>[tableSize];
    Mapping = map;
}



template < class Key, typename T >
bool Table<Key,T>::insert(Pair<  Key, T >  kvpair) {

    if (Mapping(kvpair.first) > tableSize || the_table[Mapping(kvpair.first)].second == T())
    {
        the_table[Mapping(kvpair.first)] = kvpair;
        return true;
    }
    else
    {
        cout << "Could not be added.";
        return  false;
    }

}



template < class Key, typename T >
bool Table<Key, T>::remove(const Key  aKey) {

    if (Mapping(aKey) > tableSize || Mapping(aKey) < 0 || the_table[Mapping(aKey)].second == T())
    {
        return false;
    }
    else
    {
        the_table[Mapping(aKey)].second = T();
        the_table[Mapping(aKey)].first= Key();
        return true;
    }
}




template < class Key, typename T >
T  Table<Key, T>::lookUp(const Key aKey) {

    if (Mapping(aKey) > tableSize || the_table[Mapping(aKey)].second == T())
    {
        return T();
    }
    else
    {
        return  the_table[Mapping(aKey)].second;
    }
}



template < class Key, typename T >
Table<Key, T>::Table(const Table<  Key, T   >& initTable) {


    Mapping = initTable.Mapping;
    
    tableSize = initTable.tableSize;
    the_table = new Pair<Key, T>[tableSize];
    for (int i = 0; i < tableSize; i++)
    {
        the_table[i].first = initTable.the_table[i].first;
        the_table[i].second = initTable.the_table[i].second;

    }
}



template < class Key, typename T >
Table<Key, T>::~Table() {
    delete[] the_table;
}




template < class Key, typename T >
Table< Key, T >&
Table<Key, T>::operator= (const Table<  Key, T   >& initTable) {
    delete[] the_table;

    tableSize = initTable.tableSize;
    the_table = new Pair<Key, T>[tableSize];
    Mapping = initTable.Mapping;

    for (int i = 0; i < tableSize; i++)
    {
        the_table[i].first = initTable[i].first;
        the_table[i].second = initTable[i].second;

    }


}




