#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define N 10
#define EVEN 0
#define ODD 1

struct number_t {
    int value;
    struct number_t *next;
};

struct number_collector_t {
    struct number_t *evens;
    struct number_t *odds;
};

struct number_collector_t *new_number_collector();
void append_number(struct number_collector_t *number_collector, int n);
void print_number_collector(struct number_collector_t *number_collector, int which);

/**
 * Entry point del programma.
 * Non gestire la deallocazione della memoria.
 * Output:
 * 90 88 98 64
 * 19 75 61 77 45 27
 */
int main() {
    srand(2);
    struct number_collector_t *numbers = new_number_collector();

    for (int i = 0; i < N; i++) {
        append_number(numbers, rand() % MAX);
    }
    print_number_collector(numbers, EVEN);
    print_number_collector(numbers, ODD);
    return 0;
}

/**
 * Crea e ritorna un nuovo elemento di tipo number_collector_t.
 */
struct number_collector_t *new_number_collector() {
    struct number_collector_t *new;
    new = (struct number_collector_t*) malloc(sizeof(struct number_collector_t));
    if(new == NULL)
        printf("Memoria piena\n");
    return new;
}

/**
 * Crea un nuovo nodo number_t e lo aggiunge:
 * - in coda alla lista evens di number_collector se n è pari
 * - in coda alla lista odds di number_collector se n è dispari
 */
void append_number(struct number_collector_t *number_collector, int n) {
    struct number_t *node;
    node = (struct number_t*) malloc(sizeof(struct number_t));
    if(node != NULL){
        struct number_t *tmp;
        node->value = n;
        node->next = NULL;
        if(n%2 == 0){
            if(number_collector->evens == NULL){
                number_collector->evens = node;
            } else {
               for(tmp = number_collector->evens; tmp->next != NULL; tmp = tmp->next);
                tmp->next = node; 
            }
        } else {
            if(number_collector->odds == NULL){
                number_collector->odds = node;
            } else {
                for(tmp = number_collector->odds; tmp->next != NULL; tmp = tmp->next);
                tmp->next = node;
            }
        }
    } else {
        printf("Memoria piena\n");
    }
}

/**
 * Stampa la lista dei numeri pari oppure dispari di number_collector,
 * stampando uno spazio dopo ciascun numero.
 */
void print_number_collector(struct number_collector_t *number_collector, int which) {
    struct number_t *tmp;
    if(number_collector != NULL){
        if(!which){ // EVENS
            for(tmp = number_collector->evens; tmp != NULL; tmp = tmp->next)
                printf("%d ", tmp->value);
            printf("\n");
        } else { // ODDS
            for(tmp = number_collector->odds; tmp != NULL; tmp = tmp->next)
                printf("%d ", tmp->value);
            printf("\n");
        }
    } else {
        printf("Lista vuota\n");
    }
}
