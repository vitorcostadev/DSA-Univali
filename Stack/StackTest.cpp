#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Stack.h"

using namespace std;

int main(){
    Stack<int> stack;
    create(stack);

    for(int i = 0; i < 10; i++){
        push(stack, i);
    }

    imprime(stack);

    try{
        cout << "Element of pos 1: " << get(stack, 5) << endl;
        cout << "Element of the top: " << top(stack) << endl;
        cout << "Number 3 is in the stack: " << (contains(stack, 3) ? "sim" : "nao") << endl;
    } catch(const char* msg) {
        cerr << "Error: " << msg << endl;
    }

    destroy(stack);
    return 0;
}