#include <stdio.h>
/*
scrivere un programma che dato un numero n calcola la somma
dei primi n numeri pari positivi in maniera ricorsiva
*/

int somma(int);

int main(void){
    int a;
    scanf("%d", &a),
    printf("%d\n", somma(a));
    return 0;
}

int somma(int n){
    if(n==0)
        return 0;
    else
        return n*2 + somma(n-1);
}