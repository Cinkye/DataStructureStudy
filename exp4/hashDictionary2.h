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
        KVpair<Key,E>* HT;
        int M;
        int currcnt;
        Key EMPTYKEY;
        Key TOMBKEY;
        E EMPTYVALUE;

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

        int linearProbe(const Key& k,int i)
        {
            return (h(k) + i) % M;
        }

        int quadraicProbe(const Key& k,int i)
        {
            return (hash_2(k) + 11 * i * i + 13 * i + 19) % M;
        }

        int pseudoRandomProbe(const Key& k,int i)
        {
            return (h(k) + rand()) % M;
        }

        void hashInsert(const Key& k, const E& e)
        {
            int pos = h(k);
            int i = 1;
            while(HT[pos].key() != EMPTYKEY && HT[pos].key() != TOMBKEY)
            {
                if(i == M)
                    return;
                pos = linearProbe(k,i);
                i++;
            }
            if(HT[pos].key() == EMPTYKEY)
            {
                    KVpair<Key,E> tmp(k,e);
                    HT[pos] = tmp;
                    currcnt++;
                    return;
            }
        }

        E hashSearch(const Key& k)
        {
            int pos = h(k);
            int i = 1;
            while(HT[pos].key() != EMPTYKEY && i < currcnt)
            {
                if(HT[pos].key() == k)
                {
                    return HT[pos].value();
                }
                pos = linearProbe(k,i);
                i++;
            }
            return NULL;
        }

    public:
        hashdict(int sz,Key k,Key t,E e)
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

        ~hashdict()
        {
            delete HT;
        }

        void clear()
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

        void insert(const Key& k,const E& it)
        {
            if(currcnt == M)
            {
                cout << "Hash table is full" << endl;
                exit(-1);
            }
            hashInsert(k,it);
        }

        E remove(const Key& k)
        {
            int pos = h(k);
            int i = 1;
            while(HT[pos].key() != EMPTYKEY && i <= size())
            {
                if(HT[pos].key() == k)
                {
                    E tmp = HT[pos].value();
                    KVpair<Key,E> p(TOMBKEY,EMPTYVALUE);
                    HT[pos] = p;
                    currcnt--;
                    return tmp;
                }
                pos = linearProbe(k,i);
                i++;
            }
            return NULL;
        }

        E removeAny()
        {
            if(currcnt != 0)
            {
                srand(time(0));
                int pos = rand() % currcnt;
                if(HT[pos].key() != EMPTYKEY)
                {
                    KVpair<Key,E> tmp(TOMBKEY,EMPTYVALUE);
                    HT[pos] = tmp;
                }
                return HT[pos].value();
            }
        }

        E find(const Key& k)
        {
            return hashSearch(k);
        }

        int size()
        {
            return currcnt;
        }

        void print()
        {
            for(int i = 0;i < M;++i)
                cout << HT[i].key() << " " << HT[i].value() << endl;
        }
};

#endif
