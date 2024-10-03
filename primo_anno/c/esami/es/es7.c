#include <stdio.h>
#include <stdlib.h>
#define DIM 15
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
    int val;
    struct node_t *next;
};

struct node_t* crealista(char*, char);
struct node_t* appendlista(struct node_t*, char*);
void printlista(struct node_t*);

int main(void){
    struct node_t *lista = crealista("132,34,9121,1,29", ',');
    printlista(lista);
    return 0;
}

struct node_t* appendlista(struct node_t *lista, char *s){
    struct node_t *new, *tmp;
    new = (struct node_t*) malloc(sizeof(struct node_t));

    if(new == NULL) return NULL;
    int len=0, pow=1, c=0;
    for(int i=0; s[i] != '\0'; i++) len++;

    for(int i=len-1; i>=0; i--){
        c += (s[i]-48) * pow;
        pow *= 10;
    }

    new->val = c;
    new->next = NULL;

    if(lista == NULL) return new;
    
    for(tmp = lista; tmp->next != NULL; tmp = tmp->next);
    tmp->next = new;
    return lista;
}

struct node_t* crealista(char *str, char c){
    struct node_t *lista = NULL, *head = NULL;
    int i=0, a=0;
    char s[DIM];

    while(str[i] != '\0'){
        if(str[i] == c || str[i+1] == '\0'){
            if (str[i+1] == '\0'){
                s[a] = str[i];
                a++;
            }
            s[a] = '\0';
            lista = appendlista(lista, s);
            if(head == NULL) head = lista;

            for(int b=0; b<a+1; b++) s[b] = 0;

            a=-1;
        } else {
            s[a] = str[i];
        }
        i++;
        a++;
    }
    return head;
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