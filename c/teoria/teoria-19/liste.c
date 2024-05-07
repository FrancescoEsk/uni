#include <stdio.h>
#include <stdlib.h> // allocazione dinamica della memoria
/*
per mantenere un array ordinato, all'arrivo di un nuovo elemento
spreco temp e risorse per eseguire la riorganizzazione ( devo fare shift )

LISTE
ciascun elemento è fatto da due parti
    - valore ( CONTENUTO INFORMATIVO )
    - PUNTATORE AL PROSSIMO ELEMENTO

LISTE CONCATENATE
--> facili gli inserimenti e le cancellazioni in un qualunque punto di un array ordinato

pile(stack) --> inserimento e cancellazione solo in cima alla pila
es. LIFO (Last In First Out)

code(queue) --> inserimento in coda e cancellazione in testa
es. FIFO (First In First Out)

alberi binari --> ricerca veloce 
                inserimento e cancellazione ordinati 
---------------------------------------------------------------------------------------------------------------------
LISTE
    - valore ( CONTENUTO INFORMATIVO )
    - PUNTATORE AL PROSSIMO ELEMENTO

fatta da una struct (ogni NODO)

ultimo elemento della lista avrà come puntatore NULL.

nodi della lista NON sono memorizzati necessariamente in modo contiguo


esistono anche LISTE DOPPIAMENTE CONCATENATE
--> ogni nodo è collegato sia al nodo precedente che a quello successivo
--> si può scorrere la lista in entrambe le direzioni

------------------------------------------
ESERCIZIO
definire una struttura dati lista concatenata con una serie di operazioni
- inserimento
- cancellazione
- ricerca

CRUD
Create (insert) - Retrieve - Update - Delete
*/

// definizione struttura dati lista
// LISTA CONCATENATA
typedef struct elem_{
    int num; // valore
    struct elem_* next; // puntatore al nodo successivo (tipo struct node) - STRUTTURA RICORSIVA
    // chiamato anche LINK perché definisce il collegamento al nodo successivo
} elem;

// funzioni
elem* inserisciInCoda(elem*, int); // puntatore al primo elemento della lista
// ritorna puntatore della lista aggiornata
elem* inserimentoInTesta(elem*, int);

elem* inserisciOrdinato(elem*, int);

elem* rimuovi(elem*, int); // rimuove l'intero presente nella lista

void visualizza(elem*); // stampa

elem* distruggiLista(elem*); // elimina

int esisteElemento(elem*, int); // 1 se trova l'elemento, 0 se no

int massimo(elem*); // trova il massimo num della lista

int main(void){
    
    return 0;
}

elem* inserisciInCoda(elem *lista, int n){
    elem *new, *p;
    // allocare lo spazio di memoria per memorizzare il nuovo elemento
    new = (elem*) malloc(sizeof(elem));
    // verificare esito dell'allocazione
    if(new != NULL){
        new->num = n;
        new->next = NULL;

        if(lista==NULL){ // se la lista non esiste ancora
            lista = new;
        } else { // se esiste già
            // scorro la lista per trovare l'ultimo elemento
            for(p=lista; p->next != NULL; p = p->next);
            // all'uscita del for, p è l'ultimo elemento della lista
            p->next = new; // sostituisco il vecchio NULL con il puntatore al nuovo nodo
        }
    } else {
        printf("Memoria piena!\n");
    }
    return lista;
}