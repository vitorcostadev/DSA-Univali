#include <iostream>
#include <cstring>

#define DEFAULT_CAPACITY 10

#include "List\List.cpp"
#include "List\DynamicList.cpp"
#include "LinkedList\SingleLinkedList\LinkedList.cpp"
//#include "LinkedList\DoubleLinkedList\DoubleLinkedlist.cpp"

using namespace std;

struct Atleta{
    int numero = -1;
    float tempo = -1;
};

int main(){
    LinkedList<Atleta> list; create(list);
    int qtyAtletas = 0;
    do{
        cout << "Digite a qty de atletas: "; cin>>qtyAtletas;
    }while(qtyAtletas==0);

    int qtyOriginal = qtyAtletas;
    Atleta a;
    do{
        cout << "Digite o numero do atleta: "; cin>>a.numero;
        cout << "Digite o tempo do atleta: "; cin>>a.tempo;
        add(list, a, size(list));
    }while(--qtyAtletas > 0);
    
    float media = 0;
    for(Node<Atleta> *iter = list.head; iter != NULL; iter=iter->next){
        media += iter->element.tempo;
    }

    media /= static_cast<float>(qtyOriginal);

    cout << "Relação de atletas que ficaram abaixo da media " << media << endl;
    for(Node<Atleta> *iter = list.head; iter != NULL; iter=iter->next){
        if(iter->element.tempo < media){
            cout << "Tempo: " << iter->element.tempo << endl;
            cout << "Numero>: " << iter->element.numero << endl;
        }
    }

    destroy(list);
    return 0;

}