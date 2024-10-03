#include <stdio.h>

int main(void){
    int *p, *q;

// qual è il valore di default di p?
// per dire che un puntatore non punta a nulla --> p = NULL; (anche p=0, ma meglio il primo)
// se accedo a *p mentre vale NULL, il compilatore da ERRORE (evito danni)
// se accedo a p senza averlo annullato, non so a cosa sto puntando

    p = q; // copio l'indirizzo contenuto in q, in p    , quindi ora puntano entrambi alla stessa variabile in mem
    *p = *q; // copio il valore puntato in un altro valore puntato, ma le aree di mem non vengono toccate


    return 0;
}