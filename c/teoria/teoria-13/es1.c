#include <stdio.h>
/*
scrivere un programma c che calcola la radice quadrata intera di un numero 
intero positivo. Il sottoprogramma riceve come parametro il numero intero positivo
e un'altra variabile passsata come indirizzo, in cui memorizzare la radice intera.
Il sottoprogramma ritorna 1 se la radice è precisa oppure 0.
*/

int radiceQ(int, int*);

int main(void){
    int a, rad;
    scanf("%d", &a);
    int x = radiceQ(a, &rad);
    printf("radice intera: %d\nexit code: %d\n", rad, x);
    return 0;
}

int radiceQ(int a, int *r){
    if(a==1){
        *r = 1;
        return 1;
    }
    for(int i=1; i<=a/2; i++){
        if (i*i >= a){
            if(i*i == a){
                *r = i;
                return 1;
            }
            else{
                *r = i-1;
                return 0;
            }
        }
    }
    *r = 0;
    return 0;
}