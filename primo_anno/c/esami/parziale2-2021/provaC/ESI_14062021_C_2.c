#include <stdio.h>
#include <stdlib.h>

struct length_t {
    int value;
    struct length_t *next;
};

struct length_t *create_length(int value);
void append_length(struct length_t *head, int value);
void print_list(struct length_t *head, char sep);
int list_length(struct length_t *head);

/**
 * Entry point del programma.
 * Non gestire la deallocazione della memoria.
 * Output:
 * 7-8-6-3
 * Lunghezza totale: 24
 */
int main() {
    struct length_t *head = create_length(7);
    append_length(head, 8);
    append_length(head, 6);
    append_length(head, 3);
    print_list(head, '-');
    printf("\nLunghezza totale: %i\n", list_length(head));
    return 0;
}

/**
 * Crea e ritorna un nuovo nodo.
 */
struct length_t *create_length(int value) {
    struct length_t *lista;
    lista = (struct length_t*) malloc(sizeof(struct length_t));
    if(lista != NULL){
        lista->value = value;
        lista->next = NULL;
    } else {
        printf("Memoria piena\n");
        return NULL;
    }
    return lista;
}

/**
 * Aggiunge un nodo alla lista.
 * Ipotesi: head è diverso da NULL
 */
void append_length(struct length_t *head, int value) {
    if(head != NULL){
        struct length_t *tmp, *new;
        for(tmp = head; tmp->next != NULL; tmp = tmp->next);
        new = (struct length_t*) malloc(sizeof(struct length_t));
        if(new != NULL){
            new->value = value;
            new->next = NULL;
            tmp->next = new;
        } else {
            printf("Memoria piena\n");
        }
    }
}

/**
 * Stampa le distanze dei nodi della lista utilizzando sep come separatore.
 * Quindi, dopo l'ultimo nodo non va posto sep.
 */
void print_list(struct length_t *head, char sep) {
    int check=0;
    while(head != NULL){
        if(!check)
            printf("%d", head->value);
        else
            printf("%c%d", sep, head->value);
        check = 1;
        head = head->next;
    }
}

/**
 * Ritorna la somma delle lunghezze dei nodi della lista.
 */
int list_length(struct length_t *head) {
    int count=0;
    while(head != NULL){
        count += head->value;
        head = head->next;
    }
    return count;
}
