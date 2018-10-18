/* Experience 1 2018.10.12
   Llist.h for a linked Llist
   Ò¶×Ó·± 201730684427 */

#ifndef LLIST_H
#define LLIST_H
#include <iostream>
#include "Node.h"
#include "list.h"
using namespace std;

template <typename E> class Llist :public List<E>
{
    private:
    Node<E>* head;                      // head pointer
    Node<E>* tail;                          // tail pointer
    Node<E>* curr;                         // current pointer
    Node<E> headNode;               // a head node
    int nodeCnt;                              // number of nodes

    public:
    Llist()                                         // initialize the list
    {
        nodeCnt = 0;
        head = &headNode;
        tail = &headNode;
        curr = &headNode;
        headNode.next = NULL;
    }

    ~Llist()                        // release all the memory occupied
    {
        clear();
        delete head;
        delete tail;
    }

    void clear()                // reverse and remove all the nodes
    {
        moveToStart();
        while(curr != tail)
            remove();
    }

    void insert(const E& num)       // Insert a node and point curr->next to the new node
    {
        curr->next = new Node<E>(num,curr->next);
        if(curr == tail)        // If the new node is the last one
            tail = curr->next;      // point tail to the new node
        nodeCnt++;
    }

    void append(const E& num)       // Insert a node at the end of the list
    {
        Node<E>* tmp = curr;        // Record the place of curr
        moveToEnd();            // Move curr to end
        insert(num);              // Insert a node
        curr = tmp;                 // Point back
    }

    E remove()          // Remove a node
    {
        if(!isEmpty())      // If the list is not empty
        {
            Node<E>* it = curr->next;           // Point to the node to be removed
            if(curr -> next == tail)            // If at tail
                tail = curr;                            // tail point to new end
            E tmp = curr->next->element;    // Read the data from the node to be removed
            curr->next = it -> next;        // Point curr->next 1 node farther
            delete it;                                  // Delete the node
            nodeCnt--;                              // Count--
            return tmp;                             // Return the data of the removed node
        }
        else                // If the list is empty
        {
            cout << "List is empty" << endl;
        }
        return curr->element;
    }

    void moveToStart()              // Move curr to head
    {
        curr = head;
    }

    void moveToEnd()                // Move curr to tail
    {
        curr = tail;
    }

    bool isEmpty()
    {
        return !(bool)nodeCnt;              // If nodeCnt ==0 return true, else return false
    }

    void next()
    {
        if(curr != tail)
            curr = curr->next;                  // Point curr to next node
        else
            cout << "Already at tail" << endl;      // If at tail, output note
    }

    void prev()
    {
        if(curr != head)
        {
            Node<E>* tmp = head;
            while(tmp->next != curr)        // Traverse the list to find a node
                tmp = tmp->next;                // whose next pointer point to the same thing as curr
            curr = tmp;             // Point curr to that node
        }
        else
        {
            cout << "Already at head" << endl;      // If at head, output node
        }
    }

    int length() const
    {
        return nodeCnt;         // return the number of the nodes
    }

    int currPos() const
    {
        Node<E>* tmp = head;
        int count = 0;              // Position of tmp
        while(tmp!=curr)        // Traverse the list to find the position of curr
        {
            count++;                // If tmp does not equal to curr, count ++
            tmp = tmp->next;    // Point tmp to the next node
        }
        return count;
    }

    void moveToPos(int pos)
    {
        Node<E>* tmp = head;
        for(int i = 0;i<pos;++i)        // Loop pos times to find the position
        {
            tmp = tmp->next;
        }
        curr = tmp;
    }

    const E& getValue() const
    {
        return curr->next->element;     // Return the value of the node
    }
};
#endif // LLIST_H
