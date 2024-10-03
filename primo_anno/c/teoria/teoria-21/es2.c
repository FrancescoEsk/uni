#include <stdio.h>
#include <stdlib.h>
/*
LISTA DI CARATTERI
scrivere una funzione che, data una stringa s costruisce la lista corrispondente.
'makeString' che trasforma la stringa in una lista di char.
*/

struct node_t{
    char data;
    struct node_t *next;
} typedef nodo;

nodo* makeString(char*);

int main(void){
    
    return 0;
}

nodo* makeString(char *s){
    nodo *head = NULL, *current, *prec;
    // head mantiene il riferimento alla testa della lista
    // current è il nuovo nodo corrente
    // prec serve per iterare sulla lista che stiamo costruendo
    // tiene il puntatore all'ultimo elemento corrente
    while (*s != '\0'){
        // creiamo un nuovo nodo
        current = (nodo*) malloc(sizeof(nodo));
        if(current == NULL){
            printf("Memoria piena\n");
            return head;
        }
        // inizializzazione nuovo elemento
        current->data = *s;
        current->next = NULL;
        if(head == NULL) // inserimento del nuovo elemento
            head = current;
        else
            prec->next = current;

        prec = current;
        s++;
    }
    return head;
}