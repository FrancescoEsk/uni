#include <stdio.h>

/*
Scrivere un sottoprogramma che riceve due numeri interi
positivi e calcola l'elevamento a potenza del primo rispetto al
secondo, restituendo il risultato. 

Scrivere un sottoprogramma
che stampa a video la radice ennesima intera di un numero
intero positivo. 
Il sottoprogramma prende come parametri il
numero e il grado della radice. 
Il sottoprogramma restituisce 1
se la radice intera è precisa, in alternativa 0.

Scrivere un programma che utilizza tale sottoprogramma per calcolare la
radice ennesima intera di un numero e di un grado chiesti
all'utente, e ne visualizza il risultato
*/

int pov(int, int);
int radn(int, int);
int radint(int, int);

int main(void){
    int n1, n2;
    do{
        printf("Inserisci numero 1: ");
        scanf("%i", &n1);
        printf("Inserisci numero 2: ");
        scanf("%i", &n2);
    } while (n1 == 0 || n2 == 0);

    printf("%i\n", pov(n1, n2));
    printf("%i\n", radn(n1, n2));
    printf("%i\n", radint(n1, n2));
    return 0;
}

int pov(int a, int b){
    int temp = a;
    if (b==0) // se il numero è elevato alla 0, fa 1
        return 1;
    else{
        for (int i=1; i<b; i++)
            a *= temp; // altrimenti lo calcolo e lo restituisco
        return a;
    }
}

int radn(int a, int n){
    for (int i=1; i<=a; i++){
        if (pov(i, n) == a) // se la potenza del numero combacia con quello sotto la radice, la radice è precisa
            return 1;
    }
    return 0; // se non trovo nessun numero che combacia, la radice non è precisa
}

int radint(int a, int n){
    for (int i=1; i<=a; i++){
        if (pov(i, n) >= a) // se la potenza di i è maggiore o uguale del numero siamo arrivati al risultato
            if (pov(i, n) == a) // se combacia è il numero esatto
                return i;
            else 
                return i-1; // altrimenti prendo il numero prima siccome ho sforato
    }
}