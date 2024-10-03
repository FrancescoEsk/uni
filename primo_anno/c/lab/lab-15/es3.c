#include <stdio.h>
/*
Si scriva un programma che utilizzando una struttura “timestamp” 
contenente le strutture per momento e data, calcoli il momento successivo (un secondo dopo) i seguenti:
struct timestamp esempiCompleti[5] = { { {31,12,2020},{23,59,59} } ,
{ {01,1,2021},{23,59,59} } ,
{ {28,2,2021},{23,59,59} } ,
{ {30,9,2020},{23,59,59} } ,
{ {26,3,2020},{14,29,58} } };
*/

typedef struct{
    int ora, minuto, secondo;
} miomomento;

typedef struct{
    int g, m, a;
} miadata;

typedef struct{
    miadata d;
    miomomento h;
} timestamp;

int check(int, int, int);

int main(void){
    timestamp esempiCompleti[5] = { 
    { {31,12,2020},{23,59,59} } ,
    { {01,1,2021},{23,59,59} } ,
    { {28,2,2021},{23,59,59} } ,
    { {30,9,2020},{23,59,59} } ,
    { {26,3,2020},{14,29,58} } };

    for(int i=0; i<5; i++){
        // aumento l'ora
        esempiCompleti[i].h.secondo++;
        if (esempiCompleti[i].h.secondo == 60){
            esempiCompleti[i].h.minuto++;
            esempiCompleti[i].h.secondo = 0;
            if(esempiCompleti[i].h.minuto == 60){
                esempiCompleti[i].h.ora++;
                esempiCompleti[i].h.minuto = 0;
            }
        }
        if(esempiCompleti[i].h.ora == 24){
            
            esempiCompleti[i].d.g++;
            
            if(check(esempiCompleti[i].d.g, esempiCompleti[i].d.m, esempiCompleti[i].d.a)){
                esempiCompleti[i].d.g=1;
                esempiCompleti[i].d.m++;
                if(esempiCompleti[i].d.m>12){
                    esempiCompleti[i].d.m=1;
                    esempiCompleti[i].d.a++;
                }
            }
        }
        printf("%d %d %d, %d %d %d\n", esempiCompleti[i].d.g, esempiCompleti[i].d.m, esempiCompleti[i].d.a, 
        esempiCompleti[i].h.ora, esempiCompleti[i].h.minuto, esempiCompleti[i].h.secondo);

    }
    return 0;
}

int check(int g, int m, int a){
    int c=0;
    if (a%4 == 0 && a%100 != 0)
        c=1;

    switch(m){
        case 1:
        case 5:
        case 7:
        case 8:
        case 10: 
        case 12:
            if(g>31)
                return 1;
            break;
        case 2:
            if((g>28 && !c) || (g>29 && c))
                return 1;
            break;
        default:
            if(g>30)
                return 1;
            break;
    }
    return 0;
}
