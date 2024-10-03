#include <stdio.h>
#define N 7
/*
Dato un array di interi trova e stampa il valore 
con il maggior numero di divisori propri
(divisore diverso dal numero stesso), nel caso di doppioni
stampiamo l'ultima posizione di quel numero.

a = {5, 4, 12, 9, 12, 25, 2}

12 ha 4 divisori propri (2, 3, 4, 6)
*/

int divisori(int);

int main(void){
    int a[N];
    int countM=0, x, pos; 
    for(int i=0; i<N; i++){
        printf("Inserisci n in posizione %i: ", i+1);
        scanf("%i", &a[i]);
        x = divisori(a[i]);
        if (x >= countM){
            countM = x;
            pos = i;
        }
    }
    printf("Il numero con il maggior numero di divisori propri contenuto nell'array e': %i\n", a[pos]);
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