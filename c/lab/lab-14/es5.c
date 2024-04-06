#include <stdio.h>
/*
Scrivere una funzione ricorsiva che calcola il resto della divisione 
tra due interi positivi (avendo a disposizione solo somme e sottrazioni).
Scrivere la funzione main() per testare la funzione realizzata.
*/

void leggi(int*);
int resto(int, int);

int main(void){
    int x, y;
    leggi(&x);
    leggi(&y);
    printf("%d\n", resto(x, y));
    return 0;
}

int resto(int x, int y){
    if(x>=y)
        return x-y;
    else
        return (x-y) + resto(x-y, y);
}

void leggi (int *x){
    do{
        scanf("%d", x);
    } while(*x<0);
}