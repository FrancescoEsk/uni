#include <stdio.h>
#include <stdlib.h>
/*
Scrivere una funzione listeUguali che accetta in input due liste l1 e l2
che possono essere vuote, e restituisce:

    0 se sono uguali
    1 se l1 > l2 --> in posizione i t.c. l1[i] > l2[i]
    -1 altrimenti
*/

typedef struct elem_{
    int num; // valore
    struct elem_* next; // puntatore al nodo successivo (tipo struct node) - STRUTTURA RICORSIVA
    // chiamato anche LINK perché definisce il collegamento al nodo successivo
} elem;

int listeUguali(elem*, elem*);

int main(void){
    
    return 0;
}

int listeUguali(elem *l1, elem *l2){
    if (l1 == NULL && l2 == NULL) // liste uguali
        return 0;

    while(l1->next != NULL && l2->next != NULL && l1->num == l2->num){
        l1 = l1->next;
        l2 = l2->next;
    }
    if(l1->next != NULL && l2->next != NULL){ // uscito dal while perché l1->num != l2->num
        if(l1->num > l2->num)
            return 1;
        else
            return -1;
    } else if (l1->next != NULL) { // uscito perché una lista è finita
        if(l1->num == l2->num)
            return 1;
        else if(l1->num > l2->num)
            return 1;
        else
            return -1;
    } else if (l2->next != NULL) { // uscito perché una lista è finita
        if(l1->num == l2->num)
            return -1;
        else if(l2->num > l1->num)
            return 1;
        else
            return -1;
    }
}