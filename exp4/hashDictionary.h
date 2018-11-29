// Cinkye 201730684427  Experiment 4
// 2018.11.23   hashDictionary.h
// Dictionary with hashing. Hashing is functioned directly on the value,
// because there is no KVpair.
// The model also added a overflow table for overflow data

#ifndef HASH_DICTIONARY_H
#define HASH_DICTIONARY_H
#define SIZE 17             // The size of hash table

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
    E* hashTable;       // Hash table
    E* overflowTable;   // Overflow table
    int* usedTable;     // Status of hash table
    int size;               // Current size
    int overflowSize;   // Current size of overflow table
public:
    HashDictionary()    // Initialize hash table, overflow table and status table
    {
        hashTable = new E[SIZE];
        overflowTable = new E[200];
        usedTable = new int[SIZE];
        size = 0;
        overflowSize = 0;
    }

    ~HashDictionary()   // Release the memory
    {
        delete []hashTable;
        delete []overflowTable;
        delete []usedTable;
    }

    void clear()    // Release the memory an re-initialize
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

    void insert(const E& e)     // Insert element e
    {
        int pos = hash(e);      // Use hash function to calculate the position
        int i = 1;      // Probe time
        while(usedTable[pos] == 1)  // If the position is used, probe another place
        {
            if(pos == hash(e) - 1) // If all position are visited, put it in the overflow table
            {
                overflowTable[size - SIZE] = e;
                size++;
                overflowSize++;
                return;
            }
            pos = linearProbe(e,i++);   // Find next place
        }
        // If found, add it to the hash table and set status
        usedTable[pos] = 1;
        hashTable[pos] = e;
        size++;
    }

    E remove(int i) // Remove record at the position
    {
        if(i < 0 || i >= SIZE+overflowSize)     // Not a valid position
        {
            cout << "Invalid input" << endl;
            exit(-1);
        }
        else if(i < SIZE)   // If it is in the hash table
        {
            usedTable[i] = 2;   // Set TOMB
            size--;     // Size decrement
            return hashTable[i];    // Return the value in that position
        }
        else  // If it is in the overflow table
        {
            E tmp = overflowTable[i-SIZE];
            for(int j = i-SIZE;j < overflowSize-1;++j)  // Move forward
                overflowTable[j] = overflowTable[j+1];
            size--;     // Size decrement
            overflowSize--;     // Overflow table size decrement
            return tmp;     // Return the value in that position
        }
    }

    E removeAny()   // Remove a random element in the table
    {
        srand(time(0));
        int pos = rand() % size;    // Generates a random position
        if(pos < SIZE)  // If in the hash table
        {
            E tmp = hashTable[pos];
            remove(pos);
            return tmp;
        }
        else    // In the overflow table
        {
            E tmp = overflowTable[pos-SIZE];
            remove(pos);
            return tmp;
        }

    }

    int find(const E& e)    // Return the position that e is stored in
    {
        int pos = hash(e);  // Trace the element as it is inserted
        int i = 1;
        while(usedTable[pos] != 0)
        {
            if(hashTable[pos] == e && usedTable[pos] == 1)
                return pos;
            pos = linearProbe(e,i);
            ++i;
        }
        i = 0;
        while(i < overflowSize) // Look for it in the overflow table
        {
            if(overflowTable[i] == e)
                return i+SIZE;
            ++i;
        }
        return -1;
    }

    int hash(long long e)   // Hash function
    {
        return e * e % 17;
    }

    int hash_2(long long e)     // Another hash function used for probe
    {
        return e * e * e % 17;
    }

    int linearProbe(const E& e,int i)   // Linear probe function
    {
        return (hash(e) + i) % 17;
    }

    int quadraicProbe(const E& e,int i) // Quadraic Probe Function
    {
        return (hash_2(e) + 11 * i * i + 13 * i + 19) % 17;
    }

    int pseudoRandomProbe(const E& e,int i)     // Pseudo-random Probe Function
    {
        return (hash(e) + rand()) % 17;
    }

    void print()    // Print the hash table and the overflow table
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
