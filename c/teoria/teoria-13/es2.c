#include <stdio.h>
/*
scrivere un programma c che riceve in ingresso due numeri interi
e restituisce (attraverso i parametri passati per indirizzo) sia
il massimo che il minimo
*/

void maxmin(int, int, int*, int*);

int main(void){
    int a, b, max, min;
    scanf("%d", &a);
    scanf("%d", &b);
    maxmin(a, b, &min, &max);
    printf("max: %d e min: %d\n", max, min);
    return 0;
}

void maxmin(int a, int b, int *min, int *max){
    if(a>b){
        *min = b;
        *max = a;
    } else {
        *min = a;
        *max = b;
    }
}