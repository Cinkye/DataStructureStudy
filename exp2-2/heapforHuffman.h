// Cinkye 201730684427 2018.11.1
// A heap implementation for huffman tree       heapforHuffman.h

#ifndef HEAPFORHUFFMAN_H
#define HEAPFORHUFFMAN_H

#include <iostream>
#include "huffnode.h"
#include "hufftree.h"
#include "windows.h"
using namespace std;

class huffmanHeap{
private:
    HuffTree<char>* root;      // Pointer to the array
    int maxsize;                        // Max size of the array
    int n;                                  // Size

    void siftdown(int pos)      // Put the node to the right position
    {
        while(!isLeaf(pos))
        {
            int lc = leftchild(pos);
            int rc = rightchild(pos);
            if((rc < n) && root[rc].weight() <= root[lc].weight())
                lc = rc;            // Select the smaller child
            if(root[pos].weight() <= root[lc].weight()) return;     // If the parent node is smaller than the child nodes, return
            HuffTree<char> tmp = root[pos];             // Else swap
            root[pos] = root[lc];
            root[lc] = tmp;
            pos = lc;
        }
    }

public:
    huffmanHeap(HuffTree<char>* h,int num,int max)      // Constructor
    {
        root = h;
        n = num;
        maxsize = max;
        buildHeap();
    }

    int size() const            // Return the current size of the array
    {
        return n;
    }

    bool isLeaf(int pos) const      // Judge if the node is a leaf node
    {
        return (pos >= n/2) && (pos < n);
    }

    int leftchild(int pos) const        // Return the left child of a node
    {
        return 2*pos+1;
    }

    int rightchild(int pos) const       // Return the right child of a node
    {
        return 2*pos+2;
    }

    int parent(int pos) const       // Return the parent of a node
    {
        return (pos-1)/2;
    }

    void buildHeap()            // Make the heap become a minimum heap
    {
        for(int i = n/2-1; i>=0; i--)
            siftdown(i);
    }

    void insert(const HuffTree<char>& it)       // Insert a new node and put it in the proper position
    {
        if(n > maxsize)     // If the heap is full
        {
            cout << "Heap is full" << endl;
            return;
        }
        int curr = n++;     // Size increment
        root[curr] = it;        // Insert the node to the array
        while((curr!=0) && root[curr].weight() <= root[parent(curr)].weight())      // Put the node in the proper position
        {
            HuffTree<char> tmp = root[curr];
            root[curr] = root[parent(curr)];
            root[parent(curr)] = tmp;
            curr = parent(curr);
        }
    }

    HuffTree<char> removefirst()
    {
        if(n <= 0)          // If the heap is empty
        {
            cout << "Heap is empty" << endl;
            exit(-1);
        }
        HuffTree<char> tmp = root[0];       // Exchange the minimum node with the last one in the heap
        root[0] = root[--n];
        root[n] = tmp;
        if (n != 0)         // Re-organize the minimum heap
            siftdown(0);
        return root[n];     // Return the first node
    }

    HuffTree<char> remove(int pos)      // Remove a node from the heap
    {
        if(pos < 0 || pos >= n)
        {
            cout << "Bad position" << endl;
            exit(-1);
        }
        if(pos == n-1)
            n--;
        else
        {
            HuffTree<char> tmp = root[pos];
            root[pos] = root[--n];
            root[n] = tmp;
            while((pos != 0) && (root[pos].weight() < root[parent(pos)].weight()))
            {
                HuffTree<char> tmp = root[pos];
                root[pos] = root[parent(pos)];
                root[parent(pos)] = tmp;
                pos = parent(pos);
            }
            if(n != 0)
                siftdown(pos);
        }
        return root[n];
    }

    void print()        // Print the heap
    {
        for(int i = 0;i < n;++i)
        {
            root[i].print();
            cout << endl;
        }
        cout << endl;
    }

    void code()     // Code the tree
    {
        root->code();
    }

    string getCode(char c)      // Get the code for specific letter
    {
        return root->getCode(c);
    }
};

#endif // HEAPFORHUFFMAN_H_INCLUDED
