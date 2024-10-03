#include <stdio.h>

// Ricevuto in ingresso un numero intero positivo (correggere l'eventuale input sbagliato) 
// stampa tutti i suoi divisori

int main(void){
    int n;
    printf("Inserisci il numero: ");
    scanf("%d", &n);
    if (n<0) // se il numero è negativo lo rendo positivo
        n = -n;
    if (n != 0){
        for (int i=1; i<=(n/2); i++){ // controllo fino alla metà del numero, siccome oltre è inutile
            if ((n%i) == 0) // se è divisore lo stampo
                printf("Divisore: %d\n", i);
        }
    }
    return 0;
}