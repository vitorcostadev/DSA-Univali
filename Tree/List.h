#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <algorithm>
#include <utility>
#include <stdexcept>

template<typename T>
class Compare {
    virtual int compareTo(T first, T second) = 0;
};


template<typename T>
class List{
    private:
        int initialCapacity, cardinalidade;
        T* elements = NULL;

        void increaseSize(){
            if(cardinalidade == initialCapacity){
                T* newArray = new T[initialCapacity * 2];
                std::copy(elements, elements + cardinalidade, newArray);
                delete[] elements;
                elements = newArray;
                initialCapacity *= 2;
            }

            cardinalidade++;
        }
    public:
        List(){
            cardinalidade = 0;
            initialCapacity = 16;
            elements = new T[initialCapacity];
        }

        List(int capacity){
            this->initialCapacity = capacity;
            cardinalidade = 0;
            elements = new T[this->initialCapacity];
        }

        void add(T element){
            increaseSize();
            this->elements[cardinalidade-1] = element;
        }

        bool isEmpty(){return cardinalidade == 0;}
        int indexOf(T element){
            for(int i = 0; i<cardinalidade; i++){
                if(elements[i] == element) return i;
            }

            return -1;
        }
        T remove(int index){
            if(index < 0 || index >= cardinalidade) throw std::runtime_error("Invalid index");
            T element = elements[index];
            for(int i = index; i < cardinalidade - 1; i++){
                elements[i] = elements[i + 1];
            }
            cardinalidade--;
            return element;
        }

        T get(int index){
            if(index < 0 || index > cardinalidade) throw std::runtime_error("Invalid index");
            return elements[index];
        }

        int size(){return this->cardinalidade;}
        void sort(){
            for(int i = 0; i < size() - 1; i++){
                for(int j = 0; j < size() - 1 - i; j++){
                    if(elements[j] > elements[j + 1]){
                        std::swap(elements[j], elements[j + 1]);
                    }
                }
            }
        }
        ~List(){
            delete[] elements;
            cardinalidade = 0;
        }
};

#endif 