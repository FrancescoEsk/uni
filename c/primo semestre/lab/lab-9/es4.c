#include <stdio.h>

/*
Si realizzi un programma nel linguaggio C che, dati due
interi n e m da standard input, facendo uso di una funzione di
nome multipli, calcoli il numero degli interi appartenenti
all’intervallo [1, n] che sono multipli di m. Il programma
principale, al termine della chiamata alla funzione multipli,
dovrà stampare il numero degli elementi appartenenti
all’insieme e poi terminare
*/

int multipli(int, int);

int main(void){
    int n, m;

    printf("Inserisci n: ");
    scanf("%i", &n);
    printf("Inserisci m: ");
    scanf("%i", &m);

    printf("%i\n", multipli(n, m));
    return 0;
}

int multipli (int n, int m){
    int count=0;
    for (int i=1; i<=n; i++)
        if (i%m == 0)   count++;

    return count;
}