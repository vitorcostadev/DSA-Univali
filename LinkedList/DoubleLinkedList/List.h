#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include "../Node.h"

template<typename T>
struct DoubleLinkedList{
    int cardinalidade;
    DoubleNode<T> *start;
    DoubleNode<T> *end;
};

template<typename T>
void create(DoubleLinkedList<T> &list);
template<typename T>
void destroy(DoubleLinkedList<T> &list);
template<typename T>
bool isEmpty(DoubleLinkedList<T> list);
template<typename T>
int size(DoubleLinkedList<T> list);
template<typename T>
void add(DoubleLinkedList<T> &list, T element, int index);
template<typename T>
void remove(DoubleLinkedList<T> &list, int index);
template<typename T>
T get(DoubleLinkedList<T> list, int index);
template<typename T>
int indexOf(DoubleLinkedList<T> list, T element);
template<typename T>
bool contains(DoubleLinkedList<T> list, T element);
template<typename T>
DoubleLinkedList<T> of(T* arr, int arrLength);
template<typename T>
void log(DoubleLinkedList<T> list);
#endif