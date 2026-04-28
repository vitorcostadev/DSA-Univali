#include <iostream>
#include "List.h"
#include <algorithm>

template<typename T, size_t MAX>
void create(List<T, MAX> &list){
    list.cardinalidade = 0;
}

template<typename T, size_t MAX>
int size(List<T, MAX> list) { return list.cardinalidade; }

template<typename T, size_t MAX>
bool hasSpace(List<T, MAX> list) { return list.cardinalidade < (int)MAX; }

template<typename T, size_t MAX>
bool isEmpty(List<T, MAX> list) { return list.cardinalidade == 0; }

template<typename T, size_t MAX>
int indexOf(List<T, MAX> list, T target){
    for(int i = 0; i < size(list); i++){
        if(get(list, i) == target) return i;
    }
    return -1;
}

template<typename T, size_t MAX>
bool contains(List<T, MAX> list, T target){
    return indexOf(list, target) != -1;
}

template<typename T, size_t MAX>
bool exists(List<T, MAX> list, int index){
    return ((index >= 0) && (index < list.cardinalidade));
}

template<typename T, size_t MAX>
T get(List<T, MAX> list, int index){
    if(index < 0 || index > list.cardinalidade) throw "OVERFLOW";

    return list.elements[index];
}

template<typename T, size_t MAX>
void add(List<T, MAX> &list, T element, int index){
    if(index < 0 || index > list.cardinalidade) throw "OVERFLOW";

    for(int i = size(list); i > index; i--){
        list.elements[i] = list.elements[i-1];
    }
    list.elements[index] = element;
    list.cardinalidade++;
}

template<typename T, size_t MAX>
void remove(List<T, MAX> &list, int index){
    if(index < 0 || index >= list.cardinalidade) throw "OVERFLOW";

    for(int i = index + 1; i < size(list); i++){
        list.elements[i - 1] = list.elements[i];
    }
    list.cardinalidade--;
}

template<typename T, size_t MAX>
void log(List<T, MAX> list){
    std::cout << "[";
    for(int i = 0; i < size(list); i++){
        std::cout << get(list, i);
        if(i + 1 < size(list)) std::cout << ",";
    }
    std::cout << "]";
}

template<typename T, size_t MAX>
void inverterVet(List<T, MAX> &list){
    for(int i = 0; i < size(list) / 2; i++){
        int j = size(list) - 1 - i;
        std::swap(list.elements[i], list.elements[j]);
    }
}
