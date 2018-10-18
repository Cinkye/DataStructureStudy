/* Experience 1 2018.10.12
   Node.cpp for a linked Llist
   Ò¶×Ó·± 201730684427 */

template <typename E> class Node
{
    public:
    Node<E>* next;
    E element;
    Node(const E& num,Node<E>* ptr)
    {
        element = num;
        next = ptr;
    }
    Node()
    {
        //do nothing
    }
};
