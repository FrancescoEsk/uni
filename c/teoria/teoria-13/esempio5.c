#include <stdio.h>
/*
come restituire più di un risultato da una funzione

scivere un programma c che calcola il risultato della divisione intera tra due numeri
*/

void divIntera(int, int, int*, int*);

int main(void){
    int a, b, quoziente, resto;
    a = 10;
    b = 5;
    divIntera(a, b, &quoziente, &resto);
    printf("quoziente: %d e resto: %d\n", quoziente, resto);
    return 0;
}

void divIntera(int a, int b, int *q, int *r){
    *q = a/b; // quoziente
    *r = a%b; // resto
}