#ifndef DYNAMICQUEUE_H
#define DYNAMICQUEUE_H

template<typename T>
struct Node{
    T element;
    Node<T> *next;
};

template<typename T>
struct Queue{
    Node<T> *ini, *end;
    int cardinalidade;
};

template<typename T>
void create(Queue<T> &queue)
{
    queue.cardinalidade = 0;
    queue.ini = queue.end = NULL;
}

template<typename T>
int size(Queue<T> queue) { return queue.cardinalidade; }

template<typename T>
bool isEmpty(Queue<T> queue) { return size(queue) == 0; }

template<typename T>
void insert(Queue<T> &queue, T element)
{
    Node<T> *newNode = new Node<T>();
    newNode->element = element;
    newNode->next = NULL;

    if(queue.end == NULL){
        queue.ini = queue.end = newNode;
    } else {
        queue.end->next = newNode; 
        queue.end = newNode;
    }

    queue.cardinalidade++;
}

template<typename T>
T remove(Queue<T> &queue)
{
    if(!isEmpty(queue)){
        T element = queue.ini->element; 
        Node<T> *aux = queue.ini;
        queue.ini = queue.ini->next;
        
        if(queue.ini == NULL){
            queue.end = NULL;
        }
        
        delete aux;
        queue.cardinalidade--;
        return element;
    }
    throw "UNDERFLOW";
}

template<typename T>
void destroy(Queue<T> &queue)
{
    Node<T> *aux = queue.ini, *prev;
    while(aux != NULL){
        prev = aux;
        aux = aux->next;
        delete prev;
    }
    create(queue);
}

template<typename T>
void imprime(Queue<T> queue)
{
    Node<T> *aux = queue.ini;
    while(aux != NULL){
        std::cout << aux->element << " ";
        aux = aux->next;
    }
    std::cout << std::endl;
}

template<typename T>
T getFirst(Queue<T> queue)
{
    if(!isEmpty(queue)){
        return queue.ini->element;
    }
    throw "UNDERFLOW";
}

template<typename T>
bool contains(Queue<T> queue, T element)
{
    Node<T> *aux = queue.ini;
    while(aux != NULL){
        if(aux->element == element){
            return true;
        }
        aux = aux->next;
    }
    return false;
}

template<typename T>
int indexOf(Queue<T> queue, T element)
{
    Node<T> *aux = queue.ini;
    int index = 0;
    while(aux != NULL){
        if(aux->element == element){
            return index;
        }
        aux = aux->next;
        index++;
    }
    return -1;
}

template<typename T>
T get(Queue<T> queue, int index)
{
    if(index >= 0 && index < size(queue)){
        Node<T> *aux = queue.ini;
        int i = 0;
        while(i++ < index){
            aux = aux->next;
        }
        return aux->element;
    }
    throw "INDEX_OUT_OF_BOUNDS";
}
#endif 
