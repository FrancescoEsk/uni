#include <stdio.h>
#define D 10
/*
Ritornare la prima posizione di un 7 nell'array a
*/

int main(void){
    int a[D], trovato=0;

    for (int i=0; i<D && !trovato; i++){
        if (a[i]==7){
            printf("Posizione dell'array del primo 7: %i\n", i);
            trovato++;
        }
    }
    if(!trovato)
        printf("Il 7 non è presente nell'array\n");

    return 0;
}