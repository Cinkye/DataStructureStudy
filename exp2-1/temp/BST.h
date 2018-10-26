// Cinkye 201730684427 2018.10.26
// BST.cpp
// BST implementation   

#ifndef BST_CPP
#define BST_CPP

#include <iostream>
#include "BSTNode.h"
using namespace std;

template <typename E, typename Key> class BST
{
    private:
    BSTNode<E,Key>* root;
    int nodeNumber;

    public:
    BST()
    {
        root = new BSTNode<E,Key>();
        nodeNumber = 1;
    }

    // BST(BSTNode<E,Key> it)
    // {
    //     root = &it;
    //     nodeNumber = 1;
    // }

    ~BST()
    {
        removeall();
    }

    void insert(BSTNode<E,Key>* it,BSTNode<E,Key>* root)
    {
        if(it->getElement()>=root->getElement())
        {
            if(root->right()==NULL)
            {
                root->setRight(it);
                nodeNumber++;
            }
            else
                insert(it,root->right());
        }
        else
        {
            if(root->left()==NULL)
            {
                root->setLeft(it);
                nodeNumber++;
            }  
            else
                insert(it,root->left());
        }
    }

    void removeall(BSTNode<E,Key>* root)
    {
        if(root == NULL)
            return;
        removeall(root->left());
        removeall(root->right());
        delete root;
    }

    void print()
    {
        cout << root->getElement() << " ";
        print(root->left());
        print(root->right());
    }

    void print(BSTNode<E,Key>* root)
    {
        cout << root->getElement() << " ";
        print(root->left());
        print(root->right());
    }
//    E remove()

};

#endif
