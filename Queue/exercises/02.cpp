/*
1. Desenvolva uma rotina para verificar se todos os elementos de uma fila se encontram em outra fila (não
necessariamente na mesma posição).
*/

#include <iostream>
#include "../DynamicQueue.h"

using namespace std;

template<typename T>
bool elementsIsPresent(Queue<T> firstQueue, const Queue<T> secondQueue)
{
    while(!isEmpty(firstQueue)){
        if(indexOf(secondQueue, remove(firstQueue)) == -1) return false;
    }

    return true;
}

int main(){
    Queue<int> firstQ, secondQ; create(firstQ); create(secondQ);

    insert(firstQ, 1);
    insert(firstQ, 2);
    insert(firstQ, 3);

    insert(secondQ, 1);
    insert(secondQ, 3);
    insert(secondQ, 3);

    cout << elementsIsPresent(firstQ, secondQ) << endl;
    destroy(firstQ); destroy(secondQ);
}