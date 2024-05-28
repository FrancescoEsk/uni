#include <stdio.h>
#include <stdlib.h>
/*
scrivere una funzione iterativa 'rimuoveDuplica' che data una LISTA di interi,
elimina gli elementi in posizione dispari e duplica gli elementi in posizione pari.
*/

struct elem{
    int val;
    struct elem* next;
}
typedef nodo;

elem* inserisciInCoda(elem*, int);
void visualizzaLista(elem*);
elem* rimuoveDuplica(elem*);

int main(void){
    nodo* testa = NULL; // inizializzo la lista vuota
    testa = inserisciInCoda(testa, 1);
    testa = inserisciInCoda(testa, 2);
    testa = inserisciInCoda(testa, 3);
    testa = inserisciInCoda(testa, 4);
    visualizzaLista(testa);
    testa = rimuoveDuplica(testa);
    visualizzaLista(testa);
    return 0;
}

void visualizzaLista(elem* lista){
    while(lista != NULL){
        printf("%d ", lista->val);
        lista = lista->next;
    }
    printf("\n");
}

elem* inserisciInCoda(elem* lista, int n){

}