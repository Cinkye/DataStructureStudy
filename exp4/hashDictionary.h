// Cinkye 201730684427  Experiment 4
// 2018.11.23
// Dictionary with hashing

#ifndef HASH_DICTIONARY_H
#define HASH_DICTIONARY_H
#define SIZE 17

#include <iostream>
#include <cmath>
#include "dictionary.h"

template <typename E>
class HashDictionary
{
private:
    E* hashTable;
    E* overflowTable;
    int* usedTable;
    int size;
public:
    HashDictionary()
    {
        hashTable = new E[SIZE];
        overflowTable = new E[200];
        usedTable = new int[SIZE];
        size = 0;
    }

    ~HashDictionary()
    {
        delete []hashTable;
        delete []overflowTable;
        delete []usedTable;
    }

    void clear()
    {
        delete []hashTable;
        delete []overflowTable;
        delete []usedTable;
        hashTable = new E[size];
        size = 0;
    }

    void insert(const E& e)
    {
        int pos = hash(e);
        int i = 1;
        while(usedTable[pos] == 1)
        {
            if(pos == hash(e) - 1)
                overflowTable[size - SIZE] = e;
            pos = probe(e,i++);
        }
        usedTable[pos] = 1;
        hashTable[pos] = e;
        size++;
    }

    E remove(const E& e)
    {
        int pos = hash(e);
        int i = 1;
        while(usedTable[pos] != 0 && i < SIZE)
        {
            if(hashTable[pos] == e)
            {
                usedTable[pos] = 2;
                --size;
                return e;
            }
            pos = probe(e,i++);
        }
        while(i < size)
        {
            if(overflowTable[i - SIZE] == e)
            {
                for(int j = i;j < size-1;++j)
                    overflowTable[j] = overflowTable[j+1];
                size--;
                return e;
            }
            ++i;
        }
        return NULL;
    }

    E removeAny()
    {
        int pos = rand() % size;
        if(pos < SIZE)
        {

        }

    }

    int hash(long long e)
    {
        return e * e % 17;
    }

    int probe(const E& e,int i)
    {
        return (hash(e) + 11 * i * i + 13 * i + 19) % 17;
    }
};
#endif // HASH_DICTIONARY_H
