// Cinkye 201730684427  Experiment 4
// 2018.11.23   hashDictionary2.h
// Dictionary implemented with a hash table

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
        KVpair<Key,E>* HT;
        int M;
        int currcnt;
        Key EMPTYKEY;

        int p(Key k,int i) const
        {
            return i;
        }

        int h(int x) const
        {
            return x % M;
        }

        int h(char* x) const
        {
            int i,sum;
            for(sum = 0,i = 0; x[i] != '\0'; i++)
                sum += (int) x[i];
            return sum % M;
        }
        int hash_2(int e)
        {
            return e * e * e % M;
        }

        int hash_2(char* x) const
        {
            int i,sum;
            for(sum = 0,i = 0; x[i] != '\0'; i++)
                sum += (int) x[i];
            return sum * sum * sum % M;
        }

        int linearProbe(const E& e,int i)
        {
            return (h(e) + i) % M;
        }

        int quadraicProbe(const E& e,int i)
        {
            return (hash_2(e) + 11 * i * i + 13 * i + 19) % M;
        }

        int pseudoRandomProbe(const E& e,int i)
        {
            return (h(e) + rand()) % M;
        }

        void hashInsert(const Key& k, const E& e);
        {
            int pos = h(e);
            int i = 1;
            while(HT[pos].key() != EMPTYKEY)
            {
                if(HT[pos].key() == EMPTYKEY)
                {
                    KVpair<Key,E> tmp(k,e);
                    HT[pos] = tmp;
                    currcnt++;
                    return;
                }
                else if(i = M-1) 
                    return;
                pos = linearProbe(e,i++);
            }
            return;
        }
        E hashSearch(const Key&) const;
    
    public:
        hashdict(int sz,Key k)
        {
            M = sz;
            EMPTYKEY = k;
            currcnt = 0;
            HT = new KVpair<Key,E>[sz];
            for(int i = 0;i < M;i++)
                HT[i].setKey(EMPTYKEY);
        }

        ~hashdict()
        {
            delete HT;
        }

        E find(const Key& k)
        {
            return hashSearch(k);
        }

        int size()
        {
            return currcnt;
        }

        void insert(const Key& k,const E& it)
        {
            if(currcnt >= M)
            {
                cout << "Hash table is full" << endl;
                exit(-1);
            }
            hashInsert(k,it);
            currcnt++;
        }
};

#endif