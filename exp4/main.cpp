// Cinkye 201730684427  Experiment 4
// 2018.11.23   main.cpp
// Dictionary testbench
#include <iostream>
#include "hashDictionary.h"
#include "hashDictionary2.h"
using namespace std;

int main()
{
     // Testbench for class HashDictionary
     cout << "Testing class HashDictionary" << endl;
     HashDictionary<int>* h = new HashDictionary<int>();
     int i = 4;
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
     h->print();

     // Below are testbench for class hashdict
     cout << "Testing class hashdict" << endl;
     hashdict<int,char*>* ha = new hashdict<int,char*>(10,-1,-2,"EMPTY");
     ha->insert(10,"��");
     ha->insert(10,"��");
     ha->insert(10,"��");
     ha->insert(10,"��");
     ha->insert(10,"��");
     ha->insert(10,"��");
     ha->insert(10,"��");
     ha->insert(10," ");
     ha->insert(10,"������");
     ha->insert(10,"��ɵ��");
     ha->print();
}
