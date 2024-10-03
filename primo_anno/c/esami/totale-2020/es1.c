#include <stdio.h>
#include <stdlib.h>
/*
Si completi il file ESA 23072019 A 1.c di modo che:
• delfromlist: sia data in ingresso una lista l di numeri interi e un intero n; la funzione elimina dalla
lista tutti gli elementi che compaiono almeno n volte e restituisce la lista ottenuta. Se ritenuto utile, la
funzione richiama al suo interno conta, funzione da sviluppare in ogni caso.
• conta: data una lista di interi e un numero intero x, la funzione conta restituisce quante volte x compare
nella lista. La soluzione deve essere ricorsiva.
Ad esempio, se delfromlist riceve in ingresso la lista di seguito riportata ed il valore 3:
3 → 3 → 1 → 2 → 4 → 3 → 5 → 3 → 5 → 4
il sottoprogramma restituisce la lista seguente
1 → 2 → 4 → 5 → 5 → 4

*/

struct nodo_t{
    int val;
    struct nodo_t *next;
};

struct nodo_t* delfromlist(struct nodo_t*, int);
int conta(struct nodo_t*, int);

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
    lista = inserimento_ordinato(lista, 4);

    stampalista(lista);

    lista = delfromlist(lista, 2);

    stampalista(lista);

    return 0;
}

struct nodo_t* delfromlist(struct nodo_t *lista, int num){
    struct nodo_t *tmp, *prec, *prec2, *tmp2;
    int x, check;

    tmp = lista;

    while(tmp != NULL){
        x = tmp->val;
        if(conta(lista, x) >= num){
            check = 0;
            prec2 = prec;
            for(tmp2=tmp; tmp2 != NULL; tmp2 = tmp2->next){

                if(tmp2->val == x){
                    prec2->next = tmp2->next;
                    free(tmp2);
                    tmp2 = prec2;
                } else {
                    check++;
                }
                if(check == 1)
                    tmp = tmp2;
                prec2 = tmp2;
            }
            
        }
        prec = tmp;
        tmp = tmp->next;
    }

    return lista;
}

int conta(struct nodo_t *lista, int x){
    if(lista == NULL)
        return 0;
    if(lista->val == x)
        return 1 + conta(lista->next, x);
    else
        return conta(lista->next, x);
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