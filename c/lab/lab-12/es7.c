#include <stdio.h>
/*
 Scrivere un sottoprogramma che riceve due numeri interi 
positivi e calcola l'elevamento a potenza del primo rispetto 
al secondo.

 Scrivere un sottoprogramma che calcola la radice 
ennesima intera di un numero intero positivo. Il 
sottoprogramma prende come parametri il numero, il 
grado della radice, e una variabile, passata per indirizzo, 
in cui memorizzare la radice intera. Il sottoprogramma 
restituisce 1 se la radice intera è precisa, in alternativa 0.

 Scrivere un programma che utilizza tale sottoprogramma 
per calcolare la radice ennesima intera di un numero e di 
un grado chiesti all'utente, e ne visualizza il risultato. E’ 
consigliato sfruttare la funzione potenza definita per il 
punto precedente.
*/

int pot(int, int);
int prog(int, int, int*);


int main(void){
    int n, grad, rad, x;
    printf("Inserisci n: ");
    scanf("%d", &n);
    printf("Inserisci il grado: ");
    scanf("%d", &grad);

    x = prog(n, grad, &rad);

    printf("ris: %d, exit code: %d\n", rad, x);
    return 0;
}

int pot(int n, int potenza){
    int temp = n;
    while(potenza>1){
        n *= temp;
        potenza--;
    }
    return n;
}

int prog(int x, int grado, int *ris){
    if(x == 1){
        *ris = 1;
        return 1;
    }
    for(int i=1; i<=x; i++){
        if(pot(i, grado) >= x){
            if(pot(i, grado) == x){
                *ris = i;
                return 1;
            } else{
                *ris = i-1;
                return 0;
            }
        }
    }
    *ris = 0;
    return 0;
}
