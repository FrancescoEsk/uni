#include <stdio.h>
/*
Scrivere una funzione ricorsiva che calcola ricorsivamente la somma
di tutti i numeri compresi fra 0 e x
*/

int ricorsiva(int);

int main(void){
    int a;
    scanf("%d", &a);
    printf("%d\n", ricorsiva(a));
    return 0;
}

int ricorsiva(int x){
    if(x==0) // caso base
        return 0;
    else // passo ricorsivo
        return x + ricorsiva(x-1);
}