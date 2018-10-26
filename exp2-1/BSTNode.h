// Cinkye 201730684427 2018.10.26
// BSTNode.cpp
// BST Node implementation  

#ifndef BSTNODE_CPP
#define BSTNODE_CPP

#include <iostream>
#include <BinNode.h>
using namespace std;

template <typename E,typename Key> class BSTNode: public BinNode
{
    private:
    Key k;
    E element;
    BSTNode* lc;
    BSTNode* rc;

    public:
    BSTNode()
    {
        lc = NULL;
        rc = NULL;
        element = 0;
    }

    BSTNode(Key key,E it,BSTNode* l = NULL,BSTNode* r = NULL)
    {
        k = key;
        element = it;
        lc = l;
        rc = r;
    }

    ~BSTNode()
    {

    }

    void setKey(Key& key)
    {
        k = key;
    }

    Key& Key()
    {
        return k;
    }

    void setElement(E& e)
    {
        element = e;
    }

    E& element()
    {
        return element;
    }

    void setLeft(BSTNode* l)
    {
        lc = l;
    }

    BSTNode* left()
    {
        return lc;
    }

    void setRight(BSTNode* r)
    {
        rc = r;
    }

    BSTNode* right()
    {
        return rc;
    }

    bool isLeaf()
    {
        return(lc == NULL && rc == NULL);
    }

}
#endif 