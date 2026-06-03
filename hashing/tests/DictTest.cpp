#include <iostream>
#include "../domain/Dictionary.h"

using namespace std;

int h1(int key){
    return key % 10;
}

int main(){
    Dictionary<string, 10> dict(h1);
    
    int k;
    string v;

    do{
        cout << "Digite uma chave: ";
        cin >> k;
        cin.ignore();
        
        do{
            cout << "Digite o valor da chave " << dict.hashPos(k) << ": ";
            getline(cin, v);
        }while(v.empty());

        dict.update(k, v);
        cout << " Dict " << endl;
        dict.print();
    }while(k != -1);

    return 0;
}