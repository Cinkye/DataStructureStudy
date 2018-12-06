// Cinkye 201730684427  Experiment 4
// 2018.11.23   hashDictionary2.h
// Dictionary implemented with a hash table.
// Hashing is functioned on the key instead of the value
// No overflow table added

#ifndef HASH_DICTIONARY_2_H
#define HASH_DICTIONARY_2_H
#include <iostream>
#include "dictionary.h"
#include "KVpair.h"
#include <ctime>
#include <stdlib.h>
using namespace std;

template <typename Key, typename E>
class hashdict : public Dictionary<Key,E>
{
    private:
        KVpair<Key,E>* HT;      // Pointer to the hash table
        int M;      // Max size of the table
        int currcnt;    // Current size of the table
        Key EMPTYKEY;       // User-defined empty key
        Key TOMBKEY;        // User-defined tomb key
        E EMPTYVALUE;       // User-defined empty value

        int p(Key k,int i) const    // Probe using linear probing
        {
            return i;
        }

        int h(int x) const      // Hash function for int
        {
            return x % M;
        }

        int h(char* x) const    // Hash function for string and char arrays
        {
            int i,sum;
            for(sum = 0,i = 0; x[i] != '\0'; i++)   // Add the ASCII of each character
                sum += (int) x[i];
            return sum % M;     // Mod M
        }
        int hash_2(int e)       // Hash function for int used in probing
        {
            return e * e * e % M;
        }

        int hash_2(char* x) const   // Hash function for string and char arrays used in probing
        {
            int i,sum;
            for(sum = 0,i = 0; x[i] != '\0'; i++)
                sum += (int) x[i];
            return sum * sum * sum % M;
        }

        int linearProbe(const Key& k,int i)     // Linear probe function
        {
            return (h(k) + i) % M;
        }

        int quadraicProbe(const Key& k,int i)       // Quadraic probe function
        {
            return (hash_2(k) + 11 * i * i + 13 * i + 19) % M;
        }

        int pseudoRandomProbe(const Key& k,int i)   // Pseudo random probe function
        {
            return (h(k) + rand()) % M;
        }

        void hashInsert(const Key& k, const E& e)   // Insert a record using hashing
        {
            int pos = h(k);     // Initial position
            int i = 1;      // Probe time
            while(HT[pos].key() != EMPTYKEY && HT[pos].key() != TOMBKEY)        // If not empty or tomb, it is used
            {
                if(i == M)      // Probe M time, no proper position found
                    return;
                pos = linearProbe(k,i);     // Find next position
                i++;    // Update probe time
            }
            if(HT[pos].key() == EMPTYKEY)       // If found a position, insert it
            {
                    KVpair<Key,E> tmp(k,e);
                    HT[pos] = tmp;
                    currcnt++;
                    return;
            }
        }

        E hashSearch(const Key& k)      // Search record with specific key k
        {
            int pos = h(k);     // Search it as how it is inserted
            int i = 1;
            while(HT[pos].key() != EMPTYKEY && i <= M)     // If not empty key and probe time less than current size
            {
                if(HT[pos].key() == k)      // If matched, return the value
                {
                    return HT[pos].value();
                }
                pos = linearProbe(k,i);     // Find next position
                i++;        // Update probe time
            }
            return NULL;        // Not found
        }

    public:
        hashdict(int sz,Key k,Key t,E e)        // Constructor
        {
            M = sz;
            EMPTYKEY = k;
            TOMBKEY = t;
            EMPTYVALUE = e;
            currcnt = 0;
            HT = new KVpair<Key,E>[sz];
            for(int i = 0;i < M;i++)
            {
                KVpair<Key,E> tmp(EMPTYKEY,EMPTYVALUE);
                HT[i] = tmp;
            }
        }

        ~hashdict()     // Destructor
        {
            delete HT;      // Release memory
        }

        void clear()    // Release the memory and re-initialize
        {
            delete HT;
            HT = new KVpair<Key,E>[M];
            currcnt = 0;
            for(int i = 0;i < M;i++)
            {
                KVpair<Key,E> tmp(EMPTYKEY,EMPTYVALUE);
                HT[i] = tmp;
            }
        }

        void insert(const Key& k,const E& it)       // Interface for insert
        {
            if(currcnt == M)        // If full, prompt the user
            {
                cout << "Hash table is full" << endl;
                exit(-1);
            }
            hashInsert(k,it);       // Not full, try to insert
        }

        E remove(const Key& k)      // Remove the record with specific record k
        {
            int pos = h(k);
            int i = 1;
            while(HT[pos].key() != EMPTYKEY && i <= size()) // Look for the position first
            {
                if(HT[pos].key() == k)      // If found, remove it
                {
                    E tmp = HT[pos].value();
                    KVpair<Key,E> p(TOMBKEY,EMPTYVALUE);
                    HT[pos] = p;    // Set a tomb at the position
                    currcnt--;
                    return tmp;     // Return the value
                }
                pos = linearProbe(k,i);     //  Calculate next position
                i++;        // Update probe time
            }
            return NULL;
        }

        E removeAny()       // Remove random record in the hash table
        {
            if(currcnt != 0)      // If empty, nothing to remove
            {
                srand(time(0));
                int pos = rand() % currcnt;     // Generate random position
                E tmp = HT[pos].value();
                if(HT[pos].key() != EMPTYKEY)       // If not empty postion, mark it as tomb
                {
                    KVpair<Key,E> tmp(TOMBKEY,EMPTYVALUE);
                    HT[pos] = tmp;
                }
                return HT[pos].value();     // return the value
            }
        }

        E find(const Key& k)        // Interface for search
        {
            return hashSearch(k);
        }

        int size()      // Return current size
        {
            return currcnt;
        }

        void print()    // Print the hash table
        {
            for(int i = 0;i < M;++i)
                cout << HT[i].key() << " " << HT[i].value() << endl;
        }
};

#endif
