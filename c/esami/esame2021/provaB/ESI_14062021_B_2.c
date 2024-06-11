#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct node_t {
    char value;
    struct node_t *next;
};

struct node_t *create_list(const char *s);
struct node_t *create_node(char value);
void print_chars(struct node_t *head, char *white_list);
bool instr(char ch, char *s);

/**
 * Entry point del programma.
 * Non gestire la deallocazione della memoria.
 * Output:
 * hll wrld
 */
int main() {
    struct node_t *head = create_list("hello world");
    print_chars(head, " dhlrw");
    printf("\n");
    return 0;
}

/**
 * Crea e ritorna un nuovo nodo.
 */
struct node_t *create_node(char value) {
    struct node_t *nodo;
    nodo = (struct node_t*) malloc(sizeof(struct node_t));
    if(nodo != NULL){
        nodo->value = value;
        nodo->next = NULL;
    } else {
        printf("Errore: memoria piena\n");
        return NULL;
    }
    return nodo;
}

/**
 * Crea una lista di nodi e ritorna il puntatore al primo di essi.
 */
struct node_t *create_list(const char *s) {
    struct node_t *lista, *head;
    lista = (struct node_t*) malloc(sizeof(struct node_t));
    if(lista != NULL){
        head = lista;
        for(int i=0; s[i] != '\0'; i++){
            lista->next = create_node(s[i]);
            lista = lista->next;
        }
    } else {
        printf("Errore: memoria piena\n");
        return NULL;
    }
    return head;
}

/**
 * Stampa il valore dei nodi della lista se sono presenti in white_list
 */
void print_chars(struct node_t *head, char *white_list) {
    while(head != NULL){
        if(instr(head->value, white_list))
            printf("%c", head->value);
        head = head->next;
    }
}

/**
 * Ritorna true se ch è presente in s, false in caso contrario.
 */
bool instr(char ch, char *s) {
    for(int i=0; s[i] != '\0'; i++){
        if(ch == s[i])
            return true;
    }
    return false;
}
