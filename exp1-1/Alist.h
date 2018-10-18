/* Experience 1 2018.10.12
   Alist.h for a array-based Llist
   Ò¶×Ó·± 201730684427 */

#ifndef ALIST_H
#define ALIST_H
#include<iostream>
#include"list.h"
#include <time.h>
#define MAX_SIZE 10
using namespace std;

template <typename E> class Alist: public List<E>
{
    private:
        int maxSize;            // Max size of the list
        int currSize;             // Current size of the list
        int curr;                   // Current position
        E* array;                   // A pointer to the array

    public:

    Alist()                         // Default constructor
    {
        array = new E[MAX_SIZE];            // If size is not given, make it 10
        maxSize = MAX_SIZE;                     // max size is 10
        currSize = 0;                                   // current size 0
        curr = 0;                                           // current position 0
    }

    Alist(int size)             // If size is given
    {
        array = new E[size];            // array size is the number that user gives
        maxSize = size;                     // max size is size
        currSize = 0;                           // current size 0
        curr = 0;                               // current position 0
    }

    ~Alist()
    {
        delete [] array;                    // release memory
    }

    void clear()                            // clear the list by deleting it and reinitialize a new one
    {
        delete [] array;                    // delete the array
        currSize = 0;                       // Set current size to 0
        curr = 0;                               // Ser current position to 0
        array = new E[maxSize];     // new array
    }

    void insert(const E& num)           // Insert a new node to the list
    {
        if(currSize<maxSize)                // If not full
        {
            for(int i = currSize-1;i>=curr;--i)         // Shift the existed data
                array[i+1] = array[i];
            array[curr] = num;                              // Insert new data
            currSize++;                                         // size increment
        }
        else                                // If full, output note
            cout << "List is already full." << endl;
    }

    void append(const E& num)           // Insert a record at end
    {
        if(currSize < maxSize)          // if not full
        {
            array[currSize] = num;      // Put the record at end
            currSize++;                         // size increment

        }
        else                                        // If full, output note
            cout << "List is already full." << endl;
    }

    E remove()              // Remove some specific record
    {
        if(currSize!=0)         // If not empty
        {
            E it = array[curr];                     // temporary data for return value
            for(int i = curr;i <currSize-1;++i)                 // Shift the data
                array[i] = array[i+1];
            currSize--;                     // Size decrement
            return it;
        }
        else                    // If empty, output note
        {
            cout << "List is empty." << endl;
        }

    }

    void moveToStart()              // Move curr to start
    {
        curr = 0;
    }

    void moveToEnd()
    {
        curr = currSize-1;              // Move curr to end
    }

    bool isEmpty()                      // Judge if the list is empty
    {
        return !(bool)currSize;
    }

    void prev()                     // Move curr one step left
    {
        if(curr != 0)               // If not at head
            curr--;     // curr decrement
        else        // If curr at head, output note
            cout << "Already at head." << endl;
    }

    void next()                     // Move curr one step right
    {
        if(curr != currSize-1)          // If not at end
            curr++;         // curr increment
        else                        // If curr at head, output note
            cout << "Already at end." << endl;
    }

    int length() const              // Return current size of the list
    {
        return currSize;
    }

    int currPos() const             // Return current position
    {
        return curr;
    }

    void moveToPos(int p)       // Move curr to some specific position
    {
        if(p>=0 && p<currSize)      // Judge if the input is valid
            curr = p;
        else
            cout << "Position exceed." << endl;
    }

    const E& getValue() const       // Return the value of current position
    {
        if(currSize != 0)           // If the list is not empty
            return array[curr];             // Return the value of current position
        else                    // If the list is empty, output note
            cout << "List is empty." << endl;
    }
};
#endif
