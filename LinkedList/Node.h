#ifndef NODE_H
#define NODE_H

template<typename T>
struct Node
{
    T element;
    Node *next;
};

template<typename T>
struct DoubleNode{
    T element;
    DoubleNode<T> *previous;
    DoubleNode<T> *next;
};

#endif 