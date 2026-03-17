#include <iostream>
#include "DynamicList.h"

template<typename T>
DynamicList<T> create()
{
    DynamicList<T> list;
    list.size = 0;
    list.capacity = DEFAULT_CAPACITY;
    list._ = new T[list.capacity];
    return list;
}

template<typename T>
void destroy(DynamicList<T> &list)
{
    delete[] list._;
    list._ = 0;
    list.size = 0;
    list.capacity = 0;
}

template<typename T>
void add(
    DynamicList<T> &list,
    T target,
    int index
){
    if(index < 0 || index > list.size) throw "INVALID_INDEX";
    if(list.size == list.capacity) grow(list);

    for(int i = list.size; i > index; i--){
        list._[i] = list._[i - 1];
    }

    list._[index] = target;
    list.size++;
}

template<typename T>
int size(DynamicList<T> &list) { return list.size; }

template<typename T>
T get(DynamicList<T> &list, int index)
{
    if(index < 0 || index >= list.size) throw "INVALID_INDEX";

    return list._[index];
}

template<typename T>
void grow(DynamicList<T> &list){
    int newCapacity = list.capacity == 0 ? DEFAULT_CAPACITY : list.capacity * 2;
    T* grown = new T[newCapacity];

    for(int i = 0; i < list.size; i++){
        grown[i] = list._[i];
    }

    delete[] list._;
    list._ = grown;
    list.capacity = newCapacity;
}

template<typename T>
void remove(DynamicList<T> &list, int index)
{
    if(index < 0 || index >= list.size) throw "INVALID_INDEX";

    for(int i = index; i < list.size - 1; i++){
        list._[i] = list._[i + 1];
    }
    list.size--;
}

template<typename T>
bool hasSpace(DynamicList<T> &list)
{
    return list.size < list.capacity;
}

template<typename T>
int indexOf(DynamicList<T> &list, T target)
{
    if(size(list) == 0) return -1;

    int esq = 0, dir = list.size, meio = (esq + dir) / 2;

    while(esq < dir){
        if(list._[meio] == target) return meio;
        else if(list._[meio] < target) esq = meio + 1;
        else dir = meio;

        meio = (esq + dir) / 2;
    }

    return -1;
}

template<typename T>
bool contains(DynamicList<T> &list, T target)
{
    return indexOf(list, target) != -1;
}

template<typename T>
void of(DynamicList<T> &list, T* arr, int arrSize)
{
    for(int i = 0; i < arrSize; i++){
        add(list, arr[i], list.size);
    }
}
