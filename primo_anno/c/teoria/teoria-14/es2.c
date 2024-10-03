#include <stdio.h>
/*
scrivere un sottoprogramma che riceve due interi positivi e calcola l'elevamento
a potenza del primo rispetto al secondo restituendo il risultato.

scrivere un sottoprogramma che calcola il log in base 2 intero di un numero intero positivo.
il sottoprogramma prende come argomenti la variabile contenente il numero ed una variabile
in cui salvare il risultato. Restituisce 1 se il logaritmo intero è preciso, 0 se non lo è.

Scrivere un programma che utilizza tale sottoprogramma per calcolare il log in base 2 di un intero 
inserito da un utente.
*/

int pot(int, int);
int log(int, int*);

int main(void){
    int a, ris, x;
    scanf("%d", &a);
    x = log(a, &ris);
    printf("Il logaritmo intero base 2 di %d è: %d, exit code: %d\n", a, ris, x);
    return 0;
}

int pot(int x, int n){
    int temp = x;
    while(n>1){
        x *= temp;
        n--;
    }
    if(n==0) // grado =0
        return 1;
    if(n<0) // grado <0
        return 1/x;
    return x; // grado >0
}

int log(int x, int *ris){
    *ris = 0;
    for(int i=1; i<x; i++){
        *ris++;
        if(pot(2, i) >= x){
            if (pot(2, i) == x)
                return 1;
            else
                return 0;
        }
    }
    return 0;
}