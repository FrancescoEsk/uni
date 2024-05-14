#include <stdio.h>
#include <stdlib.h>
/*
Scrivere una funzione int2list che ricevuto un intero
restituisce una lista in cui ogni cifra del numero in ingresso 
compare tante volte quante il suo valore

3204 --> 3 3 3 2 2 4 4 4 4

Nel caso in cui il valore ricevuto in ingresso sia negativo, il sottoprogramma
ritorna la lista creata dalle cifre in ordine opposto
*/

typedef struct elem_{
    int num; // valore
    struct elem_* next; // puntatore al nodo successivo (tipo struct node) - STRUTTURA RICORSIVA
    // chiamato anche LINK perché definisce il collegamento al nodo successivo
} elem;

elem* inserisciInCoda(elem*, int); // puntatore al primo elemento della lista
// ritorna puntatore della lista aggiornata
elem* inserimentoInTesta(elem*, int);
void visualizza(elem*); // stampa

elem* int2list(int);
int inverti(int);

int main(void){
    int n;
    scanf("%d", &n);
    elem* lista = NULL;
    lista = int2list(n);
    visualizza(lista);
    return 0;
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

elem* int2list(int val){
    elem* lista;
    int tmp;
    if (val > 0){ // positivo
        val = inverti(val);
        while(val > 1){
            tmp = val%10;
            for(int i=0; i<val%10; i++)
                lista = inserisciInCoda(lista, tmp);
            val /= 10;
        }
        
    } else { // negativo
        val = -val;
        while(val > 1){
            tmp = val%10;
            for(int i=0; i<val%10; i++)
                lista = inserimentoInTesta(lista, tmp);
            val /= 10;
        }
    }
    return lista;
}

int inverti(int n){
    int x=0, tmp=n, count=0, pow;
    while(tmp>0){
        tmp /= 10;
        count++;
    }
    for(int i = 0; i<count; i++){
        x = x*10 + n%10;
        n /= 10;
    }
    return x;
}