// Cinkye 201730684427 2018.10.26
// A test program for Huffman coding tree
// HuffmanTreeMain.cpp

#include <iostream>
#include "huffnode.h"
#include "hufftree.h"
#include "heapforHuffman.h"

using namespace std;

int main()
{
    HuffTree<char> ta('A',7);
    HuffTree<char> tb('B',9);
    HuffTree<char> tc('C',2);
    HuffTree<char> td('D',6);
    HuffTree<char> te('E',32);
    HuffTree<char> tf('F',3);
    HuffTree<char>* t = new HuffTree<char>[6]
        {HuffTree<char> ('A',7),
        HuffTree<char> ('B',9),
        HuffTree<char> ('C',2),
        HuffTree<char> ('D',6),
        HuffTree<char> ('E',32),
        HuffTree<char> ('F',3)};
    huffmanHeap* heap = new huffmanHeap(t,6,6);
    while(heap->size()!=1)
    {
        HuffTree<char> child1 = heap->removefirst();
        HuffTree<char>* cptr1 = &child1;
        HuffTree<char> child2 = heap->removefirst();
        HuffTree<char>* cptr2 = &child2;
        HuffTree<char>* par = new HuffTree<char>(cptr1,cptr2);
        heap->insert(*par);
        cout << heap->size() << endl;
        heap->print();
    }

}
