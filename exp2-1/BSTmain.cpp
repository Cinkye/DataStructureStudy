// Cinkye 201730684427  2018.10.26
// Main.cpp for testing BST.Cpp
// BSTmain.cpp

#include <iostream>
#include "BST.h"
using namespace std;

int main(int argc, char const *argv[])
{
    BST<int,int>* bst = new BST<int,int>();
    int i = 0;
    cout << "Please input number to insert to bst1 (input -1 to end input)" << endl;
    cin >> i;
    while(i>=0 && i<=100)
    {
        bst->insert(i,i);
        cin >> i;
    }
    BST<int,int>* bst2 = new BST<int,int>();
    // cout << "Please input number to insert to bst2 (input -1 to end input)" << endl;
    // i = 0;
    // cin >> i;
    // while(i>=0 && i<=100)
    // {
    //     bst2->insert(i,i);
    //     cin >> i;
    // }
    cout << "BST looks like this:" << endl;
    bst->print();
    cout << endl << endl;
    // cout << "BST2 looks like this:" << endl;
    // bst2->print();
    // cout << endl;
    bst->printSequence();
    cout << endl;
    bst->preorder();
    cout << endl;
    bst->inorder();
    cout << endl;
    bst->posorder();
    cout << endl;
}

