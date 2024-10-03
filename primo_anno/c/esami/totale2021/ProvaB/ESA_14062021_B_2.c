#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct location_t {
    char name;
    int distance;  // Distanza dalla location precedente nella lista
    struct location_t *next;
};

struct location_t *create_location(char name, int distance);
struct location_t *append_location(struct location_t *head, char name, int distance);
void print_route(struct location_t *head, char sep);

/**
 * Entry point del programma.
 * Non gestire la deallocazione della memoria.
 * Output:
 * A-25-B-15-C-10-D
 * Distanza totale: 50
 */
int main() {
    struct location_t *head = append_location(NULL, 'A', 0);
    append_location(head, 'B', 25);
    append_location(head, 'C', 15);
    append_location(head, 'D', 10);
    print_route(head, '-');
    return 0;
}

/**
 * Crea e ritorna un nodo per una nuova location.
 */
struct location_t *create_location(char name, int distance) {
    struct location_t *new;
    new = (struct location_t*) malloc(sizeof(struct location_t));
    if(new != NULL){
        new->name = name;
        new->distance = distance;
        new->next = NULL;
    } else {
        printf("Memoria piena\n");
        return NULL;
    }
    return new;
}

/**
 * Aggiunge una location alla lista
 * e ritorna il puntatore alla prima location della lista.
 */
struct location_t *append_location(struct location_t *head, char name, int distance) {
    if(head !=NULL){
        struct location_t *tmp;

        for(tmp=head; tmp->next != NULL; tmp = tmp->next);
        
        tmp->next = create_location(name, distance);
    } else {
        head = create_location(name, distance);
    }
    return head;
}

/**
 * Stampa le location della lista utilizzando sep come separatore.
 * Casi:
 * 1. Primo nodo (o location)
 * Ha distanza = 0 e stampa solo il nome della location (es. "A")
 *
 * 2. Nodo intermedio e ultimo nodo.
 * Stampa il separatore, la distanza dal nodo precedente, il separatore e il nome del nodo (es. "-25-B")
 *
 * Alla fine stampa anche la distanza totale.
 * Es. "Distanza totale: 50"
 */
void print_route(struct location_t *head, char sep) {
    struct location_t *current = head;
    int total_distance = 0;

    while (current) {
        if (current->distance == 0) {
            printf("%c", current->name);  // Primo nodo
        } else {
            printf("%c%i%c%c", sep, current->distance, sep, current->name);  // Nodi intermedi
        }
        total_distance += current->distance;
        current = current->next;
    }
    printf("\nDistanza totale: %i\n", total_distance);
}
