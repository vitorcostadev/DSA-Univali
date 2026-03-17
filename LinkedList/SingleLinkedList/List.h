#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "../Node.h"

template<typename T>
struct LinkedList{
    int cardinalidade;
    Node<T> *head;
};

template<typename T>
void create(LinkedList<T> &list);
template<typename T>
void destroy(LinkedList<T> &list);
template<typename T>
bool isEmpty(LinkedList<T> list);
template<typename T>
int size(LinkedList<T> list);
template<typename T>
void add(LinkedList<T> &list, T element, int index);
template<typename T>
void remove(LinkedList<T> &list, int index);
template<typename T>
T get(LinkedList<T> list, int index);
template<typename T>
int indexOf(LinkedList<T> list, T element);
template<typename T>
bool contains(LinkedList<T> list, T element);
template<typename T>
LinkedList<T> of(T* arr, int arrLength);
template<typename T>
void log(LinkedList<T> list);
#endif