#include <iostream>
#include "List.h"

using namespace std;

template<typename T>
void create(LinkedList<T> &list){
    list.cardinalidade = 0;
    list.head = NULL;
}
template <typename T>
void destroy(LinkedList<T>& list)
{
    Node<T> *current = list.head;
    while(current != NULL)
    {
        Node<T> *temp = current;
        current = current->next;
        delete temp;
    }
    list.head = NULL;
    list.cardinalidade = 0;
}
template<typename T>
int size(LinkedList<T> list) { return list.cardinalidade; }

template<typename T>
bool isEmpty(LinkedList<T> list) { return list.cardinalidade == 0; }

template<typename T>
void add(LinkedList<T> &list, T element, int index){
    if(index < 0 || index > size(list)) throw "OVERFLOW";
    Node<T> *newNode = new Node<T>();
    newNode->element = element;
    
    if(list.head == NULL){
        newNode->next = NULL;
        list.head = newNode;
    }else if(index == 0){
        newNode->next = list.head;
        list.head = newNode;
    }else if(index == size(list)){
        newNode->next = NULL;
        Node<T> *aux = list.head;

        while(aux->next != NULL) aux = aux->next;
        aux->next = newNode;
    }else{
        Node<T> *aux = list.head, *prev = NULL;

        int cont = 0;
        while(aux != NULL && cont != index){
            prev = aux;
            aux = aux->next;
            cont++;
        }

        if(aux != NULL){
            prev->next = newNode;
            newNode->next = aux;
        }

    }

    list.cardinalidade++;
}

template<typename T>
void remove(LinkedList<T> &list, int index){
    if(index < 0 || index > size(list)) throw "OVERFLOW";
    if(list.head == NULL) throw "EMPTY_LIST";

    if(index == 0){
        if(size(list) == 1){
            destroy(list);
        }else{
            Node<T> *temp = list.head;
            list.head = list.head->next;
            delete temp;
        }
    }else if(index == size(list)){
        Node<T> *aux = list.head ,*prev=NULL;
        while(aux->next != NULL){
            prev = aux;
            aux = aux->next;
        }

        prev->next=NULL;
        delete aux;
    }else{
        Node<T> *aux = list.head ,*prev=NULL;
        int cont = 0;
        while(aux != NULL && cont != index){
            prev = aux;
            aux = aux->next;
            cont++;
        }

        if(aux != NULL){
            prev->next = aux->next;
            delete aux;
        }
    }

    list.cardinalidade--;
}

template<typename T>
int indexOf(LinkedList<T> list, T element){

    int i = 0;
    for(Node<T> *aux = list.head; aux != NULL; aux = aux->next){
        if(aux->element == element) return i;
        i++;
    }

    return -1;
}

template<typename T>
bool contains(LinkedList<T> list, T element){
    return indexOf(list, element) != -1;
}

template<typename T>
T get(LinkedList<T> list, int index){
    if(index < 0 || index >= size(list)) throw "OVERFLOW";

    int i = 0;
    for(Node<T> *aux = list.head; aux != NULL; aux = aux->next){
        if(index == i) return aux->element;
        i++;
    }
    throw "NOT_FOUND";
}

template<typename T>
LinkedList<T> of(T* arr, int arrLength){
    LinkedList<T> newLl;
    create(newLl);

    for(int i = 0; i<arrLength; i++){
        add(newLl, arr[i], i);
    }

    return newLl;
}

template<typename T>
void log(LinkedList<T> list){
    int i = 0;

    cout<<"LinkedList[";
    for(Node<T> *aux = list.head; aux != NULL; aux = aux->next){
        cout << aux->element;
        if(i + 1 < size(list)) cout << ", ";
        i++;
    }

    cout << "]" << endl;
}