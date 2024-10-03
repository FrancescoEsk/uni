#include <stdio.h>
#include <stdlib.h>
/*
Scrivere una funzione che riceve in ingresso un puntatore ad una lista di interi
e la MODIFICA 
memorizzando nell'ultimo nodo il prodotto del penultimo e dell'ultimo elemento,
nel penultimo nodo il prodotto del terzultimo e del penultimo,
--> in ogni elemento mettiamo il prodotto dell'elemento e del suo predecessore.
Il primo nodo non sarà modificato perché non ha antecedente
*/

typedef struct elem{
    int dato;
    struct elem *next;
} elemento;

void modify(struct elem*);
struct elem* inserisciInCoda(struct elem*, int);
void visualizzaLista(struct elem*);

int main(void){
    int val;
    struct elem* lista = NULL;
    do{
        scanf("%d", &val);
        if(val != -1){
            lista = inserisciInCoda(lista, val);
        } 
    } while(val != -1);
    visualizzaLista(lista);
    modify(lista);
    visualizzaLista(lista);
    return 0;
}

void modify(struct elem* lista){
    int temp1, temp2;
    struct elem* tmp = lista;
    if (tmp == NULL){
        printf("Lista vuota\n");
    } else {
        temp1 = tmp->dato;
        tmp = tmp->next;
        do{
            temp2 = tmp->dato;
            tmp->dato = tmp->dato * temp1;
            temp1 = temp2;
            tmp = tmp->next;
        } while (tmp != NULL);
    }
}

struct elem* inserisciInCoda(struct elem* lista, int v){
    struct elem *new, *p;
    
    new = (struct elem*) malloc(sizeof(struct elem)); // alloco nuovo spazio di mem

    if(new != NULL){
        new->dato = v;
        new->next = NULL;
        if(lista == NULL){
            lista = new;
        } else {
            for(p = lista; p->next != NULL; p = p->next); // all'uscita, p è l'ultimo valore della lista
            p->next = new;
        }
    } else {
        printf("Memoria piena!\n");
    }
    return lista;
} 

void visualizzaLista(struct elem* lista){
    struct elem* p = lista;
    while(p != NULL){
        printf("%d ", p->dato);
        p = p->next;
    }
    if(lista != NULL)
        printf("\n");
}
