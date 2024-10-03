#include <stdio.h>
/*
Scrivere un programma che acquisisca un indice X tra 0 e 9 (controllare 
validità del valore inserito) e una sequenza di 10 numeri interi. Il programma 
dovrà stampare la somma dei numeri in posizioni minori di X e il prodotto 
dei numeri in posizioni successive a X.
*/

int main(void){
    int indice, n, somma=0, prodotto=1;
    do{
        printf("Inserisci indice: ");
        scanf("%i", &indice);
    } while(indice<0 || indice>9); // controllo

    for(int i=0; i<10; i++){
        printf("Inserisci numero: ");
        scanf("%i", &n);
        if (i<indice+1) // prima e all'indice sommo
            somma += n; 
        else // dopo l'indice faccio prodotto
            prodotto *= n; 
    }

    printf("Somma dei numeri inseriti: %i\nProdotto dei numeri inseriti: %i\n", somma, prodotto);
    return 0;
}