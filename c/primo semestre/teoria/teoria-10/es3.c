#include <stdio.h>
#define N 7
/*
Dato un array di interi trova e stampa il valore 
con il maggior numero di divisori propri
(divisore diverso dal numero stesso), nel caso di doppioni
stampiamo l'ultima posizione di quel numero.

a = {5, 4, 12, 9, 12, 25, 2}

12 ha 4 divisori propri (2, 3, 4, 6)

VARIAZIONE
- Sostituire ogni numero non primo con il suo piu' piccolo
divisore > 1
- stampare array ed numero di valori sostituiti

*/

int divisori(int); // calcola num divisori
int primo(int); // return 1 se è primo, altrimenti 0
int minDivisore(int); // return il minimo divisore >1

int main(void){
    int a[N];
    int countM=0, x, pos, count=0; 
    for(int i=0; i<N; i++){
        printf("Inserisci n in posizione %i: ", i+1);
        scanf("%i", &a[i]);
        x = divisori(a[i]);
        if (x >= countM){
            countM = x;
            pos = i;
        }
        if (primo(a[i]) != 1){
            a[i] = minDivisore(a[i]);
            count++;
        }
    }
    printf("Il numero con il maggior numero di divisori propri contenuto nell'array e': %i\n", a[pos]);
    printf("Stampa array: \n");
    for(int i=0; i<N; i++){
        printf("%i ", a[i]);
    }
    printf("\nNumeri sostituiti: %i\n", count);
    return 0;
}

int divisori(int a){
    int count=0;
    for(int i=2; i<a; i++){
        if(a%i == 0)
            count++;
    }
    return count;
}

int primo(int a){
    for(int i=2; i<=a/2; i++)
        if (a%i == 0)
            return 0;
    return 1;
}

int minDivisore(int a){
    for(int i=2; i<a; i++)
        if(a%i == 0)
            return i;
    return 0;
}