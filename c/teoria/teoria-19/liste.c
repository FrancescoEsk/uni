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

int listalen(elem*); // restituisce la lunghezza della lista
 
int main(void){
    
    return 0;
}

int listalen(elem *lista){
    if(lista == NULL)
        return 0;
    else
        return 1 + listalen(lista->next);
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

// inserimento di un elemento in testa ( all'inizio della lista )
elem* inserimentoInTesta(elem *lista, int n){
    elem* tmp;
    tmp = (elem*) malloc(sizeof(elem));
    // verificare esito dell'allocazione
    if(tmp != NULL){
        tmp->num = n;
        tmp->next = lista; // inserisco davanti
        lista = tmp; // aggiorno il puntatore al primo elemento
    } else {
        printf("Memoria piena!\n");
    }
    return lista;
}

// inserimento ordinato
elem* inserisciOrdinato(elem *lista, int n){
    elem *tmp, *prox; 
    tmp = (elem*) malloc(sizeof(elem));
    // verificare esito dell'allocazione
    if(tmp != NULL){
        tmp->num = n; 
        if(lista == NULL){ // se lista è vuota
            tmp->next = lista;
            lista = tmp;
        } else {
            if(tmp->num <= lista->num){ // se il num da inserire è più piccolo del primo elemento della lista
                // inserimento in testa
                tmp->next = lista;
                lista = tmp;
            } else if(lista->next = NULL){ // nel caso la lista abbia solo un elemento
                tmp->next = NULL;
                lista->next = tmp; 
            } else { // scorro lista fino a trovare il punto in cui inserire l'elemento
                for(prox = lista; prox->next != NULL && tmp->num > prox->next->num; prox = prox->next);
                // prox diventa l'elemento precedente al numero da inserire
                tmp->next = prox->next;
                prox->next = tmp;
            }
        }
    } else {
        printf("Memoria piena!\n");
    }
    return lista;
}

// visualizza gli elementi
void visualizza(elem *lista){
    elem *tmp = lista;
    while(tmp!=NULL){
        printf("%d ", tmp->num);
        tmp = tmp->next;
    }
    printf("\n");
}

// distruggi lista
elem* distruggiLista(elem *lista){
    elem *tmp=lista, *next;
    while(tmp != NULL){
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    return NULL;
}

// esiste un elemento n --> return 1, altrimenti return 0;
int esisteElemento(elem *lista, int n){
    elem *tmp = lista;
    while (tmp != NULL){
        if(tmp->num == n)   return 1; // se trovo il num nella lista
    } // altrimenti
    return 0;
}

// cancellazione di un elemento
elem* rimuovi(elem *lista, int n){
    elem *curr = lista, *prec = NULL;
    int found = 0;
    while(curr != NULL && !found){
        if(curr->num == n){
            found = 1;
            if(prec != NULL)    prec->next = curr->next;
            else    lista = curr;
            free(curr);
        } else {
            prec = curr;
            curr = curr->next;
        }
    }
    return lista;
}

// calcola il massimo dei valori della lista
int massimo(elem *lista){
    int m;
    elem *curr = lista;
    if(curr != NULL){ // se la lista non è vuota
        m = curr->num; // inizializzo il max al primo numero
        curr = curr->next; // avanzo

        while(curr != NULL){ // trovo il max
            if(curr->num > m)   m = curr->num;
        }
        return m;
    } else {
        printf("Lista vuota\n");
        return 0;
    }
}
