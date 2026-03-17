#include <iostream>
#include "List.h"

using namespace std;

template<typename T>
void create(DoubleLinkedList<T> &list){
    list.cardinalidade = 0;
    list.end = NULL;
    list.start = NULL;
}

template<typename T>
int size(DoubleLinkedList<T> list) { return list.cardinalidade; }

template<typename T>
bool isEmpty(DoubleLinkedList<T> list) { return list.cardinalidade == 0; }

template<typename T>
void sort(DoubleLinkedList<T> &list){
    for(DoubleNode<T> *start = list.start; start != NULL; start = start->next){
        for(DoubleNode<T> *end = list.end; end != NULL && end != start; end = end->previous){
            if(start->element > end->element){
                T temp = start->element;
                start->element = end->element;
                end->element = temp;
            }
        }
    }
}

template<typename T>
void add(DoubleLinkedList<T> &list, T element, int index){
    if(index < 0 || index > list.cardinalidade) throw "OVERFLOW";
    DoubleNode<T> *newNode = new DoubleNode<T>();
    newNode->element = element;

    if(list.start == NULL){
        newNode->previous = NULL;
        newNode->next=NULL;

        list.start = newNode;
        list.end = newNode;
    }else if(index == 0){
        DoubleNode<T> *f = list.start;

        f->previous = newNode;
        newNode->next = f;
        newNode->previous = NULL;
        list.start = newNode;
    }else if(index == size(list)){
        DoubleNode<T> *f = list.end;

        f->next = newNode;
        newNode->previous = f;
        newNode->next = NULL;
        list.end = newNode;
    }else{
        int cont = 0;
        DoubleNode<T> *s = list.start;

        while(s != NULL && cont != index){
            s = s->next;
            cont++;
        }

        if(s != NULL){
            s->previous->next = newNode;
            newNode->previous = s;

            s->next->previous = newNode;
            newNode->next = s->next;
        }
    }

    list.cardinalidade++;
}

template<typename T>
void log(DoubleLinkedList<T> list){
    int i = 0;

    cout<<"DoubleLinkedList[";
    for(DoubleNode<T> *aux = list.start; aux != NULL; aux = aux->next){
        cout << aux->element;
        if(i + 1 < size(list)) cout << ", ";
        i++;
    }

    cout << "]" << endl;
}

template <typename T>
void destroy(DoubleLinkedList<T>& list)
{
    DoubleNode<T> *current = list.start;
    while(current != NULL)
    {
        DoubleNode<T> *temp = current;
        current = current->next;
        delete temp;
    }
    list.start = NULL;
    list.end = NULL;
    list.cardinalidade = 0;
}

template <typename T>
void remove(DoubleLinkedList<T> &list, int index){
    if(index < 0 || index >= size(list)) throw "OVERFLOW";

    if(index == 0){
        if(size(list) == 1){
            destroy(list);
        }else{
            DoubleNode<T> *temp = list.start;
            list.start->next->previous=NULL;
            list.start->next=NULL;

            delete temp;
        }
    }else if(index == size(list)){
        DoubleNode<T> *aux = list.end;

        aux->previous->next=NULL;
        delete aux;
    }else{
        int cont = 0;
        DoubleNode<T> *aux = list.start;

        while(aux != NULL && cont != index){
            aux=aux->next;
            cont++;
        }

        if(aux != NULL){
            aux->previous->next = aux->next;
            aux->next->previous = aux->previous;

            delete aux;
        }
    }

    list.cardinalidade--;
}

template <typename T>
int indexOf(DoubleLinkedList<T> list, T element){

    int cont = 0;
    for(DoubleNode<T> *i = list.start; i != NULL; i=i->next){
        if(i->element == element) return cont;

        cont++;
    }

    return -1;
}

template <typename T>
bool contains(DoubleLinkedList<T> list, T element){
    return indexOf(list, element) != -1;
}

template <typename T>
T get(DoubleLinkedList<T> list, int index){
    if(index < 0 || index >= size(list)) throw "OVERFLOW";

    int cont = 0;
    for(DoubleNode<T> *s = list.start; s != NULL; s=s->next){
        if(cont == index) return s->element;
        cont++;
    }
    throw "NOT_FOUND";
}