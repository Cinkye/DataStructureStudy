// Cinkye 201730684427  2018.10.26
// Main.cpp for testing BST.Cpp
// BSTmain.cpp

#include <iostream>
#include "BST.h"
using namespace std;

int main(int argc, char const *argv[])
{
    BST<int,int>* bst = new BST<int,int>();             // New one BST

    // Insert nodes to the first BST
    int i = 0;
    cout << "Please input number to insert to bst1 (input -1 to end input)" << endl;
    cin >> i;
    while(i>=0 && i<=100)
    {
        bst->insert(i,i);
        cin >> i;
    }

    BST<int,int>* bst2 = new BST<int,int>();            // New another BST

    // Insert nodes to the second BST
    cout << "Please input number to insert to bst2 (input -1 to end input)" << endl;
    i = 0;
    cin >> i;
    while(i>=0 && i<=100)
    {
        bst2->insert(i,i);
        cin >> i;
    }

    // Print the two BSTs
    cout << "BST looks like this:" << endl;
    bst->print();
    cout << endl << endl;
    cout << "BST2 looks like this:" << endl;
    bst2->print();
    cout << endl;

    // Print the first BST as a sequence
    bst->printSequence();
    cout << endl << endl;

    // Testing traverse functions
    cout << "Preorder: ";
    bst->preorder();        // Preorder
    cout << endl << "Inorder: ";
    bst->inorder();         // Inorder
    cout << endl << "Posorder: ";
    bst->posorder();        // Posorder
    cout << endl;

    // Testing leaf node number function
    cout << "The number of leaf nodes is " << bst->leafNodeNum();
}

