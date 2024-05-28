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

nodo* inserisciInCoda(nodo*, int);
void visualizzaLista(nodo*);
nodo* rimuoveDuplica(nodo*);

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

void visualizzaLista(nodo* lista){
    while(lista != NULL){
        printf("%d ", lista->val);
        lista = lista->next;
    }
    printf("\n");
}

nodo* inserisciInCoda(nodo* lista, int n){
    nodo *tmp, *prec;
    tmp = malloc(sizeof(nodo));
    // verificare l'esito dell'allocamento
    if( tmp != NULL ){
        tmp->val = n;
        tmp->next = NULL;
        if (lista == NULL){
            lista = tmp;
        } else{
            for(prec = lista; prec != NULL; prec = prec->next);
            // uscito dal for, prec vale l'ultimo nodo

            // quindi, inserisco valore in coda
            prec->next = tmp;
        }
    } else {
        // allocazione fallita
        printf("Memoria piena\n");
    }
    return lista;
}

nodo* rimuoveDuplica(nodo* lista){
    if(lista == NULL) // se lista vuota
        return lista;

    nodo *tmp = lista->next, *aux;
    free(lista); // elimino primo elemento
    lista = tmp; // e faccio partire lista dal secondo

    while(tmp != NULL){
        aux = (nodo*) malloc(sizeof(nodo)); // nuovo nodo in cui mettere il duplicato
        if( aux == NULL){
            printf("Memoria piena\n");
            return lista;
        }
        aux->val = tmp->val; // copio il valore
        if(tmp->next != NULL){ // se non è finita la lista
            aux->next = tmp->next->next; // punto al prossimo elemento da duplicare
            free(tmp->next); // ed elimino il dispari
        } else {
            aux->next = NULL; // altrimenti, finisco
        }
        tmp->next = aux; // punto all'elemento duplicato
        tmp = aux->next; // e vado avanti
    }
    return lista; // punta al secondo elemento della lista (diventato il primo)
}