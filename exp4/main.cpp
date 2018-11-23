#include <iostream>
#include "hashDictionary.h"
using namespace std;

int main()
{
    HashDictionary<int>* h = new HashDictionary<int>();
    h->insert(99);
    h->insert(1);
    h->insert(99);
    h->insert(99);
    h->insert(99);
    h->insert(99);
    h->insert(99);
    h->insert(99);
    h->insert(99);
    h->insert(99);
    h->insert(99);
    h->insert(99);
    h->insert(99);
    h->insert(99);
    h->insert(99);
    h->insert(99);
    h->insert(99);
    h->insert(2);
    h->insert(99);
    h->insert(99);
    h->insert(99);
    h->insert(99);
    h->insert(99);
    h->insert(99);
    h->insert(98);
    h->remove(9);
    cout << h->removeAny() << endl;
    h->print();
    // cout << h->find(98) << endl;
}