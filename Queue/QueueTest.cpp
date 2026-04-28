#include <iostream>
#include "DynamicQueue.h"

using namespace std;

int main(){
    Queue<int> queue;
    create(queue);

    try{
        insert(queue, 1);
        insert(queue, 2);
        insert(queue, 3);

        cout << "Size: " << size(queue) << endl;
        cout << "Is empty? " << (isEmpty(queue) ? "Yes" : "No") << endl;
        imprime(queue);
        cout << "Removed element: " << remove(queue) << endl;
        cout << "Size after removal: " << size(queue) << endl;
        imprime(queue);
        
    } catch (const char* msg) {
        cerr << "Error: " << msg << endl;
        destroy(queue);
        return 1;   
    }
    destroy(queue);
    return 0;
}