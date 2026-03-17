#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H

template<typename T>
struct DynamicList
{
    int size;
    int capacity;
    T* _;
};

template<typename T>
DynamicList<T> create();
template<typename T>
void destroy(DynamicList<T> &DynamicList);
template<typename T>
void add(DynamicList<T> &DynamicList, T target, int index);
template<typename T>
void remove(DynamicList<T> &DynamicList, int index);
template<typename T>
T get(const DynamicList<T> &DynamicList, int index);
template<typename T>
int indexOf(const DynamicList<T> &DynamicList, T target);
template<typename T>
bool contains(const DynamicList<T> &DynamicList, T target);
template<typename T>
int size(const DynamicList<T> &DynamicList);
template<typename T>
bool hasSpace(const DynamicList<T> &DynamicList);
template<typename T>
void grow(DynamicList<T> &DynamicList);
template<typename T>
void of(DynamicList<T> &DynamicList, const T* arr, int arrSize);

#endif