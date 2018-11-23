// Cinkye 201730684427  Experiment 4
// 2018.11.23
// Dictionary with hashing

#ifndef HASH_DICTIONARY_H
#define HASH_DICTIONARY_H
#define SIZE 17

#include <iostream>
#include <cmath>
#include <ctime>
#include <stdlib.h>
#include "dictionary.h"
using namespace std;

template <typename E>
class HashDictionary
{
private:
    E* hashTable;
    E* overflowTable;
    int* usedTable;
    int size;
    int overflowSize;
public:
    HashDictionary()
    {
        hashTable = new E[SIZE];
        overflowTable = new E[200];
        usedTable = new int[SIZE];
        size = 0;
        overflowSize = 0;
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
        hashTable = new E[SIZE];
        overflowTable = new E[200];
        usedTable = new int[SIZE];
        size = 0;
        overflowSize = 0;
    }

    void insert(const E& e)
    {
        int pos = hash(e);
        int i = 1;
        while(usedTable[pos] == 1)
        {
            if(pos == hash(e) - 1)
            {
                overflowTable[size - SIZE] = e;
                size++;
                overflowSize++;
                return;
            }       
            pos = linearProbe(e,i++);
        }
        usedTable[pos] = 1;
        hashTable[pos] = e;
        size++;
    }

    // E remove(const E& e)    // Remove the record that holds specific value
    // {
    //     int pos = hash(e);
    //     int i = 1;
    //     while(usedTable[pos] != 0 && i < SIZE)
    //     {
    //         if(hashTable[pos] == e)
    //         {
    //             usedTable[pos] = 2;
    //             --size;
    //             return e;
    //         }
    //         pos = linearProbe(e,i++);
    //     }
    //     while(i < size)
    //     {
    //         if(overflowTable[i - SIZE] == e)
    //         {
    //             for(int j = i;j < size-1;++j)
    //                 overflowTable[j] = overflowTable[j+1];
    //             size--;
    //             return e;
    //         }
    //         ++i;
    //     }
    //     return 777;
    // }

    E remove(int i)
    {
        if(i < 0 || i >= SIZE+overflowSize)
        {
            cout << "Invalid input" << endl;
            exit(-1);
        }
        else if(i < SIZE)
        {
            usedTable[i] = 2;
            size--;
            return hashTable[i];
        }
        else
        {
            E tmp = overflowTable[i-SIZE];
            for(int j = i-SIZE;j < overflowSize-1;++j)
                overflowTable[j] = overflowTable[j+1];
            size--;
            overflowSize--;
            return tmp;
        }
    }

    E removeAny()
    {
        srand(time(0));
        int pos = rand() % size;
        if(pos < SIZE)
        {
            E tmp = hashTable[pos];
            remove(pos);
            return tmp;
        }
        else
        {
            E tmp = overflowTable[pos-SIZE];
            remove(pos);
            return tmp;
        }

    }

    int find(const E& e)
    {
        int pos = hash(e);
        int i = 1;
        while(usedTable[pos] != 0)
        {
            if(hashTable[pos] == e && usedTable[pos] == 1)
                return pos;
            pos = linearProbe(e,i);
            ++i;
        }
        i = 0;
        while(i < overflowSize)
        {
            if(overflowTable[i] == e)
                return i+SIZE;
            ++i;
        }
        return -1;
    }

    int hash(long long e)
    {
        return e * e % 17;
    }

    int hash_2(long long e)
    {
        return e * e * e % 17;
    }

    int linearProbe(const E& e,int i)
    {
        return (hash(e) + i) % 17;
    }

    int quadraicProbe(const E& e,int i)
    {
        return (hash_2(e) + 11 * i * i + 13 * i + 19) % 17;
    }

    int pseudoRandomProbe(const E& e,int i)
    {
        //To be finished
    }

    void print()
    {
        cout << "Hash Table" << endl;
        for(int i = 0;i < SIZE;++i)
        {
            if(usedTable[i] == 1)
            cout << i << " " << hashTable[i] << endl;
            else
            cout << i << " " << "Not used" << endl;
        }
        if(size > SIZE)
        cout << endl << "Overflow Table" << endl;
        for(int i = 0;i < overflowSize;++i)
        {
            cout << i << " " << overflowTable[i] << endl;
        }
    }
};
#endif // HASH_DICTIONARY_H
