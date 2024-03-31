#include <stdio.h>
#define N 10

/*
Scrivere un programma che acquisisce un array di 10 numeri
interi e un intero n senz’altro positivo. Il programma modifica
l’array facendo scorrere ogni intero di n posizioni a destra (gli
ultimi n interi vengono riportati all’inizio).

Esempio:
Ingresso: 0 1 2 3 4 5 6 7 8 9 e n=3
Uscita: 7 8 9 0 1 2 3 4 5 6
*/

int main(void){
    int a[N];
    int b[N];
    int n;

    for (int i=0; i<N; i++){ // inserimento
        printf("Inserisci il numero %i: ", i+1);
        scanf("%i", &a[i]);
    }

    printf("Inserisci n: ");
    scanf("%i", &n);

    while (n>=N){ // se sfora la grandezza dell'array, lo riduco di N fino a che non diventa accettabile
        n = n-N;
    }

    for (int i=0; i<N; i++){
        if (i+n<N) // se non sforo procedo normale
            b[i+n] = a[i];
        else // altrimenti tolgo N per "ricominciare" da capo
            b[i+n-N] = a[i];
    }

    for(int i=0; i<N; i++) // stampa
        printf("%i ", b[i]);
    return 0;
}
