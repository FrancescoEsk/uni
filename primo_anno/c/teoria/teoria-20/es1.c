#include <stdio.h>
#include <stdlib.h>
/*
Scrivere un programma C che lavora su liste di interi e usa una funzione "prodotto"
che calcola il prodotto dei valori contenuti nella lista

Versione iterativa e Versione ricorsiva 
*/

typedef struct elem{
    int dato;
    struct elem *next;
} elemento;

int prodotto(struct elem*);
int prodottoRic(struct elem*);

int main(void){
    
    return 0;
}

int prodotto(struct elem* lista){ // versione iterativa
    int tot = 1;
    if (lista == NULL){
        printf("Lista vuota\n");
    } else {
        do{
            tot = tot * lista->dato;
            lista = lista->next;
        } while (lista != NULL);
    }
    return tot;
}

int prodottoRic(struct elem* lista){ // versione ricorsiva
    if(lista == NULL) // caso BASE
        return 1;
    else // passo INDUTTIVO
        return lista->dato * prodottoRic(lista->next);
}
