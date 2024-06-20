#include <stdio.h>
#include <stdlib.h>
/*
Completare il file ESI 21062023 A 3.c definendo il sottoprogramma crealista che riceve in ingresso una stringa
(chiamata str) e un carattere (chiamato sep). La stringa str `e senz’altro composta da pi`u sequenze di cifre
(’0’, ..., ’9’) separate da una singola occorrenza del carattere sep (si assuma che la stringa sia benformata). Il
sottoprogramma crea e restituisce una lista di interi strettamente positivi (str non contiene il carattere ’-’) in
cui ciascun elemento della lista contiene un valore intero corrispondente ad una sequenza di cifre presenti nella
stringa str. Non `e consentito modificare la stringa di ingresso. Esempio: ingressi: str: ”132,34,9121,1,29” sep:
’,’ uscita: 132 − > 34 − > 9121 − > 1 − > 29
*/

struct node_t{
    char* val;
    struct node_t *next;
};

struct node_t* crealista(char*, char);
struct node_t* appendlista(struct node_t*, char*);
void printlista(struct node_t*);

int main(void){
    
    return 0;
}

struct node_t* appendlista(struct node_t *lista, char *s){
    struct node_t *new, *tmp;
    new = (struct node_t*) malloc(sizeof(struct node_t));

    if(new == NULL) return NULL;
    new->val = s;
    new->next = NULL;

    if(lista == NULL) return new;

    for(tmp = lista; tmp->next != NULL; tmp = tmp->next);
    tmp->next = new;
    return lista;
}

struct node_t* crealista(char *str, char c){
    struct node_t *lista, *head;
    int count=0;

    for(int i=0; str[i] != '\0'; i++){
        if(str[i] == c){
            
        } else {
            count++;
        }
    }
    
}

void printlista(struct node_t *lista){
    while(lista != NULL){
        printf("%d", lista->val);
        if(lista->next != NULL)
            printf(" -> ");
        lista = lista->next;
    }
    printf("\n");
}