#include <stdio.h>
/*
Si scriva un programma che utilizzando una struttura per l’ora,
il minuto ed il secondo,chiamata “miomomento”, calcoli il momento 
successivo (un secondo dopo) i seguenti:
struct miomomento esempi[6] =
{ {11,59,58}, {11,59,59}, {23,59,59}, {0,0,58}, {0,0,59}, {12,0,0} };
*/

typedef struct{
    int ora, minuto, secondo;
} miomomento;

int main(void){
    miomomento esempi[6] =
    { {11,59,58}, {11,59,59}, {23,59,59}, {0,0,58}, {0,0,59}, {12,0,0} };

    for(int i=0; i<6; i++){
        esempi[i].secondo++;
        if (esempi[i].secondo == 60){
            esempi[i].minuto++;
            esempi[i].secondo = 0;
            if(esempi[i].minuto == 60){
                esempi[i].ora++;
                esempi[i].minuto = 0;
            }
        }

        printf("%d,%d,%d\n", esempi[i].ora, esempi[i].minuto, esempi[i].secondo);
    }

    return 0;
}