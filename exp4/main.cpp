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
     //Testing function insert()
     cout << "Inserting many records......" << endl << endl;
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
     h->print();
     // Testing function remove()
     cout << "Remove the record in slot 9" << endl;
     h->remove(9);
     // Testing function print()
     h->print();
     // Testing function find()
     cout << "Looking for a value 98......" << endl;
     cout << "The position of the value 98 is " << h->find(98) << endl;

     // Below are testbench for class hashdict
     cout << "Testing class hashdict" << endl;
     hashdict<int,char*>* ha = new hashdict<int,char*>(10,-1,-2,"EMPTY");

}
