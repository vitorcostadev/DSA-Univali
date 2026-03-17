#ifndef LIST_H
#define LIST_H
// Lista estática generica

template<typename T, size_t MAX>
struct List
{
    int cardinalidade;
    T elements[MAX];
};

template<typename T, size_t MAX>
List<T, MAX> create();
template<typename T, size_t MAX>
void add(List<T, MAX> &list, T target, int index);
template<typename T, size_t MAX>
void remove(List<T, MAX> &list, int index);
template<typename T, size_t MAX>
T get(List<T, MAX> list, int index);
template<typename T, size_t MAX>
int indexOf(List<T, MAX> list, T target);
template<typename T, size_t MAX>
bool contains(List<T, MAX> list, T target);
template<typename T, size_t MAX>
int size(List<T, MAX> list);
template<typename T, size_t MAX>
bool hasSpace(List<T, MAX> list);
#endif 