// Cinkye 201730684427 2018.11.1
// This header file is modified on the basis of the resource
// Huffman tree node abstract base class
#ifndef HUFFNODE_H
#define HUFFNODE_H
#include <iostream>
#include <string>
using namespace std;

template <typename E> class HuffNode {
public:
  virtual ~HuffNode() {}                // Base destructor
  virtual int weight() = 0;             // Return frequency
  virtual bool isLeaf() = 0;            // Determine type
  virtual void print() = 0;             // Print the node
  virtual void code(string par, string a) = 0;      // Give the node Huffman code
  virtual string getCode() = 0;
};
template <typename E>   // Internal node subclass
class IntlNode : public HuffNode<E> {
private:
  HuffNode<E>* lc;   // Left child
  HuffNode<E>* rc;   // Right child
  int wgt;              // Subtree weight
  string Huffcode;      // Huffman code
public:
  IntlNode(HuffNode<E>* l, HuffNode<E>* r)      // Constructor
    {
        wgt = l->weight() + r->weight();
        lc = l;
        rc = r;
    }

  int weight()              // Return the weight of the node
  {
      return wgt;
  }

  bool isLeaf()             // An internal is not a leaf node
  {
      return false;
  }

  HuffNode<E>* left() const // Return left child
  {
      return lc;
  }

  void setLeft(HuffNode<E>* b)  // Set left child
    { lc = (HuffNode<E>*)b; }

  HuffNode<E>* right() const { return rc; }     // Return right child

  void setRight(HuffNode<E>* b)     // Set right child
    { rc = (HuffNode<E>*)b; }

  void print()      // Print the subtree
  {
      cout << wgt << " " ;
      lc->print();
      rc->print();
  }

  void code(string par, string a)       // Code the subtree
  {
      Huffcode = par + a;                   // Parent code appended with a "a"
      lc->code(Huffcode,"0");           // give the left child a "0"
      rc->code(Huffcode,"1");           // give the right child a "1"
  }

  string getCode()          // Return the Huffman code of the node
  {
      return Huffcode;
  }

};

template <typename E>   // Leaf node subclass
class LeafNode : public HuffNode<E> {
private:
  E it;			// Value
  int wgt;		// Weight
  string Huffcode;      // Huffcode
public:
  LeafNode(const E& val, int freq)   // Constructor
  {
      it = val;
      wgt = freq;
  }

  int weight()      // Return the weight of the node
  {
      return wgt;
  }

  E val()       // Return the value of the node
  {
      return it;
  }

  bool isLeaf()         // A leaf node is a leaf node
  {
      return true;
  }

  void print()          // Print the information of the node
  {
      cout << it << '(' << wgt << ')' << '[' << Huffcode << ']' << " ";
  }

  void code(string par, string a)       // Code the node
  {
      Huffcode = par + a;
  }

  string getCode()          // Return the Huffman code of the node
  {
      return Huffcode;
  }

};

#endif // HUFFNODE_H
