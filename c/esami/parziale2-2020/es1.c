#include <stdio.h>
#include <stdlib.h>
/*
Si completi il file ESI 20062019 A 1.c di modo che:
• la funzione selectitems riceva in input una lista e due interi min e max, crei una nuova lista contenente
tutti e soli i valori presenti nella lista di ingresso strettamente compresi tra min e max (estremi inclusi),
ordinati in modo crescente e la restituisce al chiamante. La lista di partenza non deve essere modificata.
• la funzione stampa lista stampa la lista in input.
• la funzione inserimento ordinato riceve in input una lista (il puntatore al primo nodo) ordinata in
modo crescente e un intero num, inserisce l’intero nella lista nella posizione corretta per poter restituire
il puntatore ad una nuova lista ordinata.
Ad esempio, data la seguente lista
1 -> 3 -> 5 -> 3 -> 7 -> 2
e i valori 2 (min), 4 (max), la nuova lista ordinata generata sar´a:
2 -> 3 -> 3
Lo studente NON deve gestire la deallocazione della lista
*/

struct nodo_t{
    int val;
    struct nodo_t *next;
};

struct nodo_t* selectitems(struct nodo_t*, int, int);
void stampalista(struct nodo_t*);
struct nodo_t* inserimento_ordinato(struct nodo_t*, int);

int main(void){
    struct nodo_t *lista;
    lista = (struct nodo_t*) malloc(sizeof(struct nodo_t));
    lista = NULL;

    lista = inserimento_ordinato(lista, 3);
    lista = inserimento_ordinato(lista, 3);
    lista = inserimento_ordinato(lista, 2);

    stampalista(lista);
    
    return 0;
}

struct nodo_t* selectitems(struct nodo_t *lista, int min, int max){
    struct nodo_t *new;

    while(lista != NULL){
        if(lista->val >= min && lista->val <= max){ // se il num e' compreso nell'intervallo, stampo
            new = inserimento_ordinato(new, lista->val);
        }
        lista = lista->next;
    }
    return new;
}

struct nodo_t* inserimento_ordinato(struct nodo_t *lista, int num){
    struct nodo_t *tmp, *prec, *new;
    new = (struct nodo_t*) malloc(sizeof(struct nodo_t));
    if (new == NULL){ 
        printf("Memoria piena\n");
        return NULL;
    }
    new->val = num;

    if(lista == NULL){ // se la lista e' vuota, ritorno new come primo elemento
        new->next = NULL;
        return new;
    }

    if(lista->val >= num){ // se l'elemento e' da inserire nel primo slot
        new->next = lista;
        return new;
    }
        
    for(tmp=lista; tmp != NULL; tmp = tmp->next){
        if(tmp->val >= num){ // quando trovo il valore prossimo, inserisco nello slot prima 'new'
            new->next = tmp;
            prec->next = new;
            return lista;
        }
        prec = tmp;
    }

    prec->next = new;
    new->next = NULL;

    return lista;
}

void stampalista(struct nodo_t *lista){
    int count=0;
    while(lista != NULL){
        if(count == 0) printf("%d", lista->val);
        else printf(" -> %d", lista->val); // separatore
        lista = lista->next;
        count++;
    }
    printf("\n");
}