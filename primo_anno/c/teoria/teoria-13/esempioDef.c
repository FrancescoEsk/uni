#include <stdio.h>
/*
SOTTOPROGRAMMI CON PUNTATORI
paramtetri:
- passaggio per valore (classico)
- passagio per RIFERIMENTO (con puntatori)

*/

int main(void){
    int a, b;
    a = 3;
    b = 7;
    swap(a, b); // non fa nulla siccome quando termina, le variabili della funzione vengono perse
    // quindi passaggio per valore NON FUNZIONA

    swap2(&a, &b); // questo swap FUNZIONA
    return 0;
}

void swap(int p, int q){ // per valore
    int temp = p;
    p = q;
    q = temp;
}

void swap2(int *p, int *q){ // per RIFERIMENTO
    int temp = *p;
    *p = *q;
    *q = temp;
}