#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

template<typename T, size_t MAX>
struct Queue{
    int cardinalidade, start, end;
    T elements[MAX];
};

template<typename T, size_t MAX>
void create(Queue<T, MAX> &queue)
{
    queue.cardinalidade = queue.start  = queue.end = 0;
}

template<typename T, size_t MAX>
int size(Queue<T, MAX> queue) { return queue.cardinalidade; }

template<typename T, size_t MAX>
bool isEmpty(Queue<T, MAX> queue)
{
    return (size(queue) == 0);
}

template<typename T, size_t MAX>
bool hasSpace(Queue<T, MAX> queue)
{
    return (size_t)queue.cardinalidade < MAX;
}

template<typename T, size_t MAX>
bool exists(Queue<T, MAX> queue, int index){
    return ((index >= 1) && (index <= size(queue)));
}

template<typename T, size_t MAX>
T get(Queue<T, MAX> queue, int index){
    if(exists(queue, index)){
        return queue.elements[index-1];
    }

    throw "OVERFLOW";
}

template<typename T, size_t MAX>
int indexOf(Queue<T, MAX> queue, T element){
    for(int i = 1; i<=size(queue); i++){
        if(get(queue, i) == element) return i;
    }

    return -1;
}

template<typename T, size_t MAX>
void insert(Queue<T, MAX> &queue, T element){
    if(hasSpace(queue)){
        if(queue.end == MAX){
            queue.end = 1;
        }else{
            queue.end += 1;
        }
        queue.elements[queue.end-1] = element;
        queue.cardinalidade += 1;
    }else{
        throw "OVERFLOW";
    }
}

template<typename T, size_t MAX>
T remove(Queue<T, MAX> &queue){

    T element;

    if(!isEmpty(queue)){
        element = get(queue, queue.start+1);

        if(queue.start == MAX){
            queue.start = 1;
        }else{
            queue.start += 1;
        }
        queue.cardinalidade -= 1;
        
    }else{
        throw "UNDERFLOW";
    }

    return element;
}

template<typename T, size_t MAX>
void imprime(Queue<T, MAX> queue){
    for(int i = 1; i <= size(queue); i++){
        std::cout << get(queue, i) << " ";
    }
    std::cout << std::endl;
}

#endif 