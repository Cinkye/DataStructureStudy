// Homework 1 Exercise 4.6&&4.7
// Name:叶子繁 201730684427
// Date:2018/09/26
// The upper part of this header file is copied from the textbook,
// and the last two functions are the answer of the exercises.
#include "list.h"

template <typename E> class LList: public List<E>
{
    Link<E>* head;
    Link<E>* tail;
    Link<E>* curr;
    int cnt;
}

void init()
{
    curr = tail = head = new Link<E>;
    cnt = 0;
}

void removeall()
{
    while(head != NULL)
    {
        curr = head;
        head = head->next;
        delete curr;
    }
}

public:
    LList(int size=defaultSize){ init(); }
    ~LList() { removeall(); }
    void print() const;
    void clear() { removeall();init(); }

    void insert(const E& it)
    {
        curr->next = new Link<E>(it,curr->next);
        if(tail == curr) tail = curr-> next;
        cnt++;
    }

    E remove()
    {
        Assert(curr->next != NULL, "No element");
        E it = curr->next->element;
        Link<E>* ltemp = curr->next;
        if(tail == curr->next) tail = curr;
        curr->next = curr->next->next;
        delete ltemp;
        cnt--;
        return it;
    }

    void moveToStart()
    {
        curr = head;
    }

    void moveToEnd()
    {
        curr = tail;
    }

    void prev()
    {
        if(curr == head) return;
        Link<E>* temp = head;
        while (temp->next!=curr) temp = temp->next;
        curr = temp;
    }

    void next()
    {
        if(curr != tail) curr = curr->next;
    }

    int length()const {return cnt;}

    int currPos const
    {
        Link<E>* temp = head;
        int i;
        for(i = ; curr != temp;i++)
            temp = temp->next;
        return i;
    }

    void moveToPos(int pos)
    {
        Assert((pos>=0)&&(pos<=cnt),"Position out of range");
        curr = head;
        for(int i = 0;i<pos;i++) curr = curr->next;
    }

    const E& getValue()const
    {
        Assert(curr->next != NULL, "No value");
        return curr -> next -> element;
    }

    void reverse()      //Reverse the linked list as exercise 4.6 required
    {
        Assert(head != tail,"Empty list");
        curr = head;        // Equals to moveToStart()
        Link<E>* n = curr->next;        // Define two pointers here
        Link<E>* it = curr->next->next;
        while(n != tail)        // While pointer n doesn't meet the end
        {                               // of the list
            n->next = curr;     // Point the next pointer backward
            curr = n;       // Move curr to n
            n = it;            // Move n to it
            it = it->next;      // Move it to it's next
/* After one time of loop the list should look like this:
    口(head here)->口<=>口(curr here)  口(n here)->口(it here)->口->口(tail here)
    then
    口(head here)->口<=>口<-口(curr here)  口(n here)->口(it here)->口(tail here)
*/
        }
/*
    After the loop the list should look like this:
    口(head here)->口<=>口<-口<-口<-口(curr here)  口(n here)(tail here)(it=NULL)
*/
        tail->next=curr;
        head->next->next=NULL;
/*
    口(head here)->口<-口<-口<-口<-口(curr here)<-口(n here)(tail here)(it=NULL)
*/
        tail=head->next;
        head->next=n;
/*
    口(tail here)<-口<-口<-口<-口(curr here)<-口(n here)(it=NULL)<-口(head here)
    Reverse done.
*/
    }

    LList& merge(LList l1,LList l2)     //Merge the two linked list as exercise 4.7 required
    {
        int c1 = 0;     // Two counters thar counts the nodes that have been merged
        int c2 = 0;
        const int length1 = l1.length(),length2 = l2.length();    // Two constant
        l1.moveToStart();l2.moveToStart();  // Move the curr pointers to the start of the lists
        LList output();
        while(c1<length1&&c2<length2)   //Merge the smaller element
        {
            if(l1.getValue()<l2.getValue())
            {
                output.append(l1.getValue());
                l1.next();
                c1++;
            }
            else if(l2.getValue()<l1.getValue())
            {
                output.append(l2.getValue());
                l2.next();
                c2++;
            }
            else        //If they are equal, append both of them.
            {
                output.append(l1.getValue());
                output.append(l2.getValue());
                l1.next();l2.next();
                c1++;c2++;
            }
        }
        // Merge the rest of the elements
        while(c1<length1)
        {
            output.append(l1.getValue());
            l1.next();
            c1++;
        }
        while(c2<length2)
        {
            output.append(l2.getValue());
            l2.next();
            c2++;
        }
        return output;
    }

