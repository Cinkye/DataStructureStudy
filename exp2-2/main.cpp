// Cinkye 201730684427 2018.10.26
// A test program for Huffman coding tree
// HuffmanTreeMain.cpp

#include <iostream>
#include "huffnode.h"
#include "hufftree.h"
#include "heapforHuffman.h"

using namespace std;

string readCode(int n,huffmanHeap* heap)
{

}

int main()
{
    HuffTree<char>* t = new HuffTree<char>[6]
        {HuffTree<char> ('A',7),
        HuffTree<char> ('B',9),
        HuffTree<char> ('C',2),
        HuffTree<char> ('D',6),
        HuffTree<char> ('E',32),
        HuffTree<char> ('F',3)};
    huffmanHeap* heap = new huffmanHeap(t,6,6);         // Initializing a minimum heap

    cout << "Building the Huffman tree from a heap" << endl;
    cout << "Heap size: " << heap->size() << endl;
    heap->print();          // Print the heap
    while(heap->size()!=1)      // Build the tree
    {
        HuffTree<char> child1 = heap->removefirst();
        HuffTree<char>* cptr1 = &child1;
        HuffTree<char> child2 = heap->removefirst();
        HuffTree<char>* cptr2 = &child2;                // Deque two smallest trees
        HuffTree<char>* par = new HuffTree<char>(cptr1,cptr2);      // Build a new tree with the two smallest trees
        heap->insert(*par);             // Enque the new tree into the heap
        cout << "Heap size: " << heap->size() << endl;
        heap->code();           // Give the nodes Huffman codes
        heap->print();          // Print the heap
    }

}
