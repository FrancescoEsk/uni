#include <stdio.h>
#include <stdlib.h>
/*
Sia data una lista contenente almeno due elementi ed i cui nodi sono definiti tramite la seguente struttura C:
struct nodo{
    int valore;
    struct nodo *next;
};
Si scriva una funzione C che ricevendo in ingresso un puntatore alla lista 
modifichi la stessa, memorizzando nell’ultimo nodo la somma dei valori di tutti i nodi presenti nella lista.
Ad esempio, una lista contenente la sequenza di interi: 4 6 2 3 9 verrà modificata dalla funzione nella lista 4 6 2
3 9 24
Realizzare anche la funzione per stampare la lista.
*/

typedef struct {
    int valore;
    struct nodo *next;
} nodo;

int main(void){

    return 0;
}

void f1(nodo *a){
    int sum=0;
    while((*a).next != NULL){
        sum += (*a).valore;
        a = (*a).next;
    }
    (*a).valore = sum;
}

void pr(nodo *a){
    while(a != NULL){
        printf("%d ", (*a).valore);
        a = (*a).next;
    }
    printf("%d\n", (*a).valore);
}