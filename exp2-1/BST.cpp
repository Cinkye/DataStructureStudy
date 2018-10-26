// Cinkye 201730684427 2018.10.26
// BST.cpp
// BST implementation   

#ifndef BST_CPP
#define BST_CPP

#include <iostream>
#include "BinNode.h"
#include "BSTNode.h"
using namespace std;

template <typename E, typename Key> class BST
{
    private:
    BSTNode* root;
    int nodeNumber;

    public:
    BST()
    {
        root = new BSTNode();
        nodeNumber = 1;
    }

    BST(BSTNode it)
    {
        root = &it;
        nodeNumber = 1;
    }

    ~BST()
    {
        removeAll();
    }

    void insert()

}

#endif
