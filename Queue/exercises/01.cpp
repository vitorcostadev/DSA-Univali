/*
Faça um programa para simular a chegada dos carros em um posto de combustível das 08:00h as
12:00h de um dia qualquer. Das 08:00h as 10:30h chegam de 1 a 4 carros, a cada 7 minutos, e das
10:31h as 12:00h chegam de 0 a 2 carros, a cada 4 minutos. Existe um único frentista para fazer o
abastecimento e que demora 2 minutos para abastecer um carro. Cada carro coloca aleatoriamente
de 1 a 40 litros e que são informados quando o carro é disposto na fila de espera. Escreva o número
de carros que aguardavam na fila para serem atendidos pelo frentista as 09:00h e as 11:00h e ao
final da simulação escreva a quantidade de combustível que cada carro atendido colocou. 
*/

#include <iostream>
#include "../DynamicQueue.h"
#include <time.h>

using namespace std;

struct Time{
    int hour;
    int minute;
};

struct RelatoryFuel
{
    Time t;
    int qtyLitros;
};

int carAmountInTime(Time &timef)
{
    int minutes = timef.hour * 60 + timef.minute;

    if(minutes >= 630 && minutes <= 720)
    {
        return (rand()%3);
    }
    if(minutes >= 480 && minutes <= 630)
    {
        return 1 + rand() % (4);
    }

    return -1;
}

void changeTime(Time &t, int hour=-1, int minute=-1)
{
    if(hour > -1 && minute > -1){
        t.hour = hour;
        t.minute = minute;
    }else if(hour > -1) { t.hour = hour; }
    else { t.minute = minute; }
}

void changeQtyLitros(RelatoryFuel &r, int qtyL) { r.qtyLitros = qtyL; }

Time getTime(RelatoryFuel r) { return r.t; }
int getQtyLitros(RelatoryFuel r) {return r.qtyLitros;}
int getHour(Time t) { return t.hour; }
int getMinute(Time t) { return t.minute; }

int main(){
    srand(time(NULL) + clock());
    Time t = {0,0};
    Queue<RelatoryFuel> queue, processedCars; create(queue); create(processedCars);
    bool frentistaOcupado = false;
    RelatoryFuel current;

    try{
        for(int i = 480; i < 720; i++)
        {
            changeTime(t, i / 60, i % 60);
            Queue<RelatoryFuel>* currentQueue = &queue;

            if(i == 540 || i == 660)
            {
                cout << "Hora: " << i / 60 << ":0" << i % 60 << "\nCarros em espera: " << size(queue) << endl;
            }
            if(i % 4 == 0 || i % 7 == 0)
            {
                if(!frentistaOcupado)
                {
                    currentQueue = &processedCars;
                    frentistaOcupado = true;
                }
                else {
                    currentQueue = &queue;
                }

                for(int i = 0; i<carAmountInTime(t); i++){
                    RelatoryFuel r = {t, 0};
                    changeQtyLitros(r, (1 + rand()% (41)));

                    insert(*currentQueue, r);
                }
            }else{
                if(i % 2 == 0 && frentistaOcupado && !isEmpty(queue))
                {
                    insert(processedCars, remove(queue));
                    frentistaOcupado = false;
                }
            }
        }
    }catch(const char *err){
        cerr << err << endl;
    }

    cout << "=============================================" << endl;
    while(!isEmpty(processedCars)){
        RelatoryFuel r = remove(processedCars);
        cout << "Hora: " << getHour(getTime(r)) << ":0" << getMinute(getTime(r)) << "\nLitros: " << getQtyLitros(r) << "L" << endl;
        cout << "-----------------------------------------------" << endl; 
    }

    destroy(queue); destroy(processedCars);
}