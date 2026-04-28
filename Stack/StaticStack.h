#ifndef STATIC_STACK_H_INCLUDED
#define STATIC_STACK_H_INCLUDED
#include <iostream>

using namespace std;

template<typename T, size_t MAX>
struct StaticStack{
    T elements[MAX];
    int topo;
};

template<typename T, size_t MAX>
void create(StaticStack<T, MAX> &stack){ stack.topo = 0; }

template<typename T, size_t MAX>
int size(StaticStack<T, MAX> stack) { return stack.topo; }

template<typename T, size_t MAX>
bool hasSpace(StaticStack<T, MAX> stack) { return stack.topo < MAX; }

template<typename T, size_t MAX>
T get(StaticStack<T, MAX> stack, int index){
    if(!isValidPosition(stack, index)) throw "OVERFLOW";

    return stack.elements[index];
}

template<typename T, size_t MAX>
int indexOf(StaticStack<T, MAX> stack, T element){
    for(i = 0; i<size(stack); i++){
        if(get(stack, i) == element) return i;
    }

    return -1;
}
template<typename T, size_t MAX>
bool contains(StaticStack<T, MAX> stack, T element){
    return indexOf(stack, element) != -1;
}

template<typename T, size_t MAX>
bool isValidPosition(StaticStack<T, MAX> stack, int index){
    return (index < 0 || index > size(stack));
}
#endif