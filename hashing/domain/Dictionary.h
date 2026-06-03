#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <list>
#include "Association.h"

typedef int (hashFunc) (int);

template<typename T, size_t sizeOfTable>
class Dictionary{
    private:
        size_t size, tableSize;
        hashFunc* hashFunction;
        std::list<Association<T>> table[sizeOfTable];
    
    public:
        Dictionary(hashFunc* _f) : size(0), tableSize(sizeOfTable), hashFunction(_f) {};
        
        void update(int key, T value){
            Association<T> as(key, value);
            this->table[this->hashFunction(key)].push_back(as);
            this->size++;
        }

        void remove(int key){
            int index = this->hashFunction(key);
            for(auto it = this->table[index].begin();
                it != this->table[index].end(); ++it)
                {
                    if(it->getKey() == key){
                        this->table[index].erase(it);
                        this->size--;
                        break;
                    }
                }
        }

        size_t sizeOfDict() {return this->size;}

        bool contains(int key){
            int index = this->hashFunction(key);
            for(auto it = this->table[index].begin();
                it != this->table[index].end(); ++it){
                    if(it->getKey() == key) return true;
                }
            return false;
        }

        int hashPos(int key){
            return this->hashFunction(key);
        }

        void print(){
            for(size_t i = 0; i < this->tableSize; i++){
                if(!this->table[i].empty()){
                    std::cout << i << " -> ";
                    for(auto it = this->table[i].begin();
                        it != this->table[i].end(); ++it){
                            std::cout << it->getKey() << " " << it->getValue();
                            std::cout << std::endl;
                        }
                }
            }
        }

        ~Dictionary(){
            for(size_t i = 0; i<this->tableSize; i++){
                this->table[i].clear();
            }

            this->size = 0;
        }
};
#endif