#include <stdio.h>
/*
stretta correlazione tra puntatore e array
perchè?

Il nome di una variabile array (es. a) è una COSTANTE di tipo puntatore al tipo componente dell'array,
il cui valore è l'indirizzo del primo elemento dell'array.


*/

void inverti(int[], int);

int main(void){
    /*
    int a[3]; // array di interi di dim 3

    // a è un puntatore COSTANTE di tipo int il cui valore è l'indirizzo del primo elemento dell'array
    // a = &a[0];

    int *p;
    p = p+1; // a[i] ==> *(a+i)
    */


    // a[i]; // accesso all'i-esimo elemento dell'array a
    // equivalente a *(a+i) --> spostando a partire dal primo elemento di a, di i posizioni
    
    // p = a; // equivalente = p = &a[0]

    // a = p;  ERRORE perchè a è COSTANTE, non può essere modificato
    // a = a+i; ERRORE

    int *const x; // puntatore COSTANTE a dati non costanti
    const int *x; // puntatore non costante a dati COSTANTI
    const int *const a; // puntatore COSTANTE a dati COSTANTI

    int *punt, arr[10]; // punt è un puntatore ad interi, arr è array di interi e puntatore al primo elm di arr

    punt = arr; // punt = &arr[0];
    *punt = 9; // arr[0] = 9;
    punt = punt +2; // punt = &arr[2];
    *punt = 7; // arr[2] = 7;
    *(punt+1) = 17; // arr[3] = 17;

    inverti(a, 10); // a puntatore costante di tipo int ad &a[0]
    return 0;
}

void inverti(int a[], int dim){ // questo modifica l'array senza necessitare di un return
    int temp;
    for(int i=0; i<dim/2; i++){
        temp = a[i];
        a[i] = a[dim-i-1];
        a[dim-i-1] = temp;
    }
}

/* NOTAZIONE CON PUNTATORI
void inverti(int *a, int dim){
    int temp;
    for(int i=0; i<dim/2; i++){
        temp = *(a+i);
        *(a+i) = *(a+dim-i-1);
        *(a+dim-i-1) = temp;
    }
}
*/