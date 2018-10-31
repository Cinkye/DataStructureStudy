#ifndef HEAPFORHUFFMAN_H_INCLUDED
#define HEAPFORHUFFMAN_H_INCLUDED

#include <iostream>
#include "huffnode.h"
#include "hufftree.h"
#include "windows.h"
using namespace std;

class huffmanHeap{
private:
    HuffTree<char>* root;
    int maxsize;
    int n;

    void siftdown(int pos)
    {
        while(!isLeaf(pos))
        {
            int lc = leftchild(pos);
            int rc = rightchild(pos);
            if((rc < n) && root[rc].weight() <= root[lc].weight())
                lc = rc;
            if(root[pos].weight() <= root[lc].weight())
            {
                HuffTree<char> tmp = root[pos];
                root[pos] = root[lc];
                root[lc] = tmp;
            }
            pos = lc;
        }
    }

public:
    huffmanHeap(HuffTree<char>* h,int num,int max)
    {
        root = h;
        n = num;
        maxsize = max;
        buildHeap();
    }

    int size() const
    {
        return n;
    }

    bool isLeaf(int pos) const
    {
        return (pos >= n/2) && (pos < n);
    }

    int leftchild(int pos) const
    {
        return 2*pos+1;
    }

    int rightchild(int pos) const
    {
        return 2*pos+2;
    }

    int parent(int pos) const
    {
        return (pos-1)/2;
    }

    void buildHeap()
    {
        for(int i = n/2-1; i>=0; i--)
            siftdown(i);
    }

    void insert(const HuffTree<char>& it)
    {
        if(n > maxsize)
        {
            cout << "Heap is full" << endl;
            return;
        }
        int curr = n++;
        root[curr] = it;
        while((curr!=0) && root[curr].weight() <= root[parent(curr)].weight())
        {
            HuffTree<char> tmp = root[curr];
            root[curr] = root[parent(curr)];
            root[parent(curr)] = tmp;
            curr = parent(curr);
        }
    }

    HuffTree<char> removefirst()
    {
        if(n <= 0)
        {
            cout << "Heap is empty" << endl;
            exit(-1);
        }
        HuffTree<char> tmp = root[0];
        root[0] = root[--n];
        root[n] = tmp;
        if (n != 0)
            siftdown(0);
        return root[n];
    }

    HuffTree<char> remove(int pos)
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

    void print()
    {
        root->print();
    }
};

#endif // HEAPFORHUFFMAN_H_INCLUDED
