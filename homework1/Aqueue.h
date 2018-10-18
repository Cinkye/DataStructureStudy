// Homework 1 Exercise 4.14
// Name:Ò¶×Ó·± 201730684427
// Date:2018/09/26


#include "queue.h"

template <typename E> class AQueue:public Queue<E>
{
private:
    int maxSize;
    int front;
    int rear;
    E* listArray;
    int cnt;    // Number of element saved

public:
    AQueue(int size = defaultSize)
    {
        maxSize = size;     // No need for one empty position anymore
        rear = 0;front = 1;
        cnt = 0;
        listArray = new E[maxSize];
    }

    ~AQueue() { delete [] listArray; }

    void clear() { rear = 0; front = 1; cnt = 0;} // Reinitialize

    void enqueue(const E& it)
    {
        Assert(!this->isFull(), "Queue is full");
        rear = (rear + 1) % maxSize;
        listArray[rear] = it;
        cnt++;
    }

    E dequeue()
    {
        Assert(cnt != 0,"Queue is empty");
        E it = listArray[front];
        front = (front + 1) % maxSize;
        cnt--;
        return it;
    }

    const E& frontValue()const
    {
        Assert(cnt != 0, "Queue is empty");
        return listArray[front];
    }

    virtual int length() const      //Return length
        return cnt;

    bool isFull()
    {
        return cnt==maxSize;
    }
}
