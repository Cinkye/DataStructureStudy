// Codes for Exercise 5.8 and 5.11
// Cinkye 2018.10.23

// Headers
#include <iostream>
#include "BSTNode.h"
#include "book.h"
using namespace std;

// Return the height of a tree
int getHeight(BSTNode<int,int>* root ,int height)
{
    if(root == NULL)
        return height;  // If the node is null, return the height of it
    else        // Else traverse to find the height of the tree
    {
        int m = max(getHeight(root->right(),height+1),getHeight(root->left(),height+1));    // Return the bigger height of the two subtree.
        return m;
    }
}

void printSomeGrandparent(BSTNode<int,int>* root)
{
    if((root->left()!=NULL && (root->left()->left()!=NULL|| root->left()->right()!=NULL))   // If the node has at least a grandson.
    || (root->right()!=NULL  && (root->right()->left()!=NULL || root->right()->right()!=NULL)))
    {
        if(root->element()%5==0)    // And if the value of it is a multiple of five
            cout << "Node " << root->key() << " has a value of " << root->element() << endl;    // Output the value of the node
        if(root->left()!=NULL)              // If the left child is not null
            printSomeGrandparent(root->left());     // Check left child
        if(root->right()!=NULL)            // If the right child is not null
            printSomeGrandparent(root->right());        // Check right child
    }
}

int main()
{
    // Build a tree by some nodes without using BST.h
    BSTNode<int,int>* root = new BSTNode<int,int>(8,10);
    root->setLeft(new BSTNode<int,int>(6,5));
    root->setRight(new BSTNode<int,int>(5,5));
    root->right()->setRight(new BSTNode<int,int>(5,5));
    root->left()->setLeft(new BSTNode<int,int>(5,5));
    root->left()->left()->setLeft(new BSTNode<int,int>(5,5));
    /*  The tree should look like this
                            10
                            / \
                           5   5
                          / \  / \
                         5        5
                        /
                       5
    */

    // Testing the function getHeight()
    cout << "The height of the tree is " << getHeight(root,0) << endl << endl;

    // Testing the function printSomeGrandparent()
    printSomeGrandparent(root);

    return 0;
}
