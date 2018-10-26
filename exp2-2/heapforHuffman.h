#ifndef HEAPFORHUFFMAN_H_INCLUDED
#define HEAPFORHUFFMAN_H_INCLUDED

#include <iostream>
#include "huffnode.h"
using namespace std;

class huffmanHeap{
private:
    HuffNode<char>** root;
    int maxsize;
    int n;

    void siftdown(int pos)
    {
        while(!isLeaf(pos))
        {
            int lc = leftchild(pos);
            int rc = rightchild(pos);
            if((rc < n) && (**root[rc] < **root[lc]))
               lc = rc;
            if(*(*root[pos]) < **root[lc])
                return;
            swap(*root,pos,lc);
            pos = lc;
        }
    }

public:
    huffmanHeap(HuffNode<char>** h,int num,int max)
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

    void insert(const HuffNode<char>& it)
    {
        if(n > maxsize)
        {
            cout << "Heap is full" << endl;
            return;
        }
        int curr = n++;
        **root[curr] = it;
        while ((curr!=0) && (**root[curr] < **root[parent(curr)]))
        {
            swap(*root,curr,parent(curr));
            curr = parent(curr);
        }
    }

    HuffNode<char> removefirst()
    {
        if(n <= 0)
        {
            cout << "Heap is empty" << endl;
            return;
        }
        swap(*root,0,--n);
        if (n != 0)
            siftdown(0)
        return **root[n];
    }

    HuffNode<char> remove(int pos)
    {
        if(pos < 0 || pos >= n)
        {
            cout << "Bad position" << endl;
            return NULL;
        }
        if(pos == n-1)
            n--;
        else
        {
            swap(*root,pos,--n)
            while((pos != 0) && (**root[pos] < **root[parent(pos])))
            {
                swap(*root,pos,parent(pos));
                pos = parent(pos);
            }
            if(n != 0)
                siftdown(pos);
        }
        return **root[n];
    }
};

#endif // HEAPFORHUFFMAN_H_INCLUDED
