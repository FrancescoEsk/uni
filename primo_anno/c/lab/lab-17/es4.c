#include <stdio.h>
#include <stdlib.h>
/*
Sia data una lista contenente almeno due elementi ed i cui nodi sono definiti tramite la seguente struttura C:
struct nodo{
     int valore;
     struct nodo *next;
};
Si scriva una funzione C che ricevendo in ingresso un puntatore alla lista 
modifichi la stessa, memorizzando nell’ultimo nodo il prodotto del penultimo 
ed ultimo nodo, nel penultimo il prodotto del terzultimo e del penultimo e così via. 
Il primo nodo non deve essere modificato (perché non ha un precedente).
Ad esempio, una lista contenente la sequenza di interi 4 6 2 3 9 verrà modificata 
dalla funzione nella lista 4 24 12 6 27
*/

typedef struct {
    int valore;
    struct nodo *next;
} nodo;

int main(void){
    
    return 0;
}

