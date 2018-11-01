// Cinkye 201730684427 2018.11.1
// This header file is modified on the basis of the resource
// Huffman tree implementation hufftree.h
#ifndef HUFFTREE_H
#define HUFFTREE_H
#include <iostream>

using namespace std;

template <typename E>
class HuffTree {
private:
  HuffNode<E>* Root;         // Tree root
public:
  HuffTree(E val, int freq) // Leaf constructor
  {
      Root = new LeafNode<E>(val, freq);
  }

  // Internal node constructor
  HuffTree(HuffTree<E>* l, HuffTree<E>* r)
  {
      Root = new IntlNode<E>(l->root(), r->root());
  }

  ~HuffTree() // Destructor
  {

  }

  HuffNode<E>* root() { return Root; }    // Get root

  int weight() { return Root->weight(); } // Root weight

  void print()      // Print the tree
  {
      Root->print();
  }

  void code()       // Code the tree
  {
      Root->code("","");        // Root node has no code
  }
};

#endif // HUFFTREE_H
