#include <stdio.h>
#include <stdlib.h>

#define LENGTH 4

struct letter_t {
    char letter;
    struct letter_t *next;
};

void put_word(struct letter_t *phrase[], int pos, int length, const char *s);
void print_phrase(struct letter_t *phrase[], int length, char sep);
void free_word(struct letter_t *word);
struct letter_t *construct_word(const char *s);

/**
 * Entry point del programma.
 * Output:
 * hello darkness my old
 */
int main() {
    struct letter_t *phrase[LENGTH] = {NULL};
    put_word(phrase, 0, LENGTH, "hello");
    put_word(phrase, 1, LENGTH, "darkness");
    put_word(phrase, 2, LENGTH, "my");
    put_word(phrase, 3, LENGTH, "old");
    put_word(phrase, 4, LENGTH, "friend");
    print_phrase(phrase, LENGTH, ' ');
    printf("\n");

    free_word(phrase[0]);
    free_word(phrase[1]);
    free_word(phrase[2]);
    free_word(phrase[3]);
    return 0;
}

/**
 * Crea una lista di nodi di tipo letter_t
 * con i caratteri della stringa s
 * e ritorna il puntatore al primo nodo.
 */
struct letter_t *construct_word(const char *s) {
    struct letter_t *node, *head, *prec;
    node = (struct letter_t*) malloc(sizeof(struct letter_t));
    if(node != NULL){
        head = node;
        prec = head;
        for(int i=0; s[i] != '\0'; i++){
            node = (struct letter_t*) malloc(sizeof(struct letter_t));
            if(node != NULL){
                node->letter = s[i];
                prec->next = node;
                prec = node;
            }else {
                printf("Memoria piena\n");
                return NULL;
            }
        }
    } else {
        printf("Memoria piena\n");
        return NULL;
    }
    return head;
}

/**
 * Libera la memoria di una lista di nodi di tipo letter_t.
 */
void free_word(struct letter_t *word) {
    struct letter_t *succ;
    while(word != NULL){
        succ = word->next;
        free(word);
        word = succ;
    }
}

/**
 * Libera la memoria di una lista di nodi di tipo letter_t.
 * Se pos non è un indice valido per l'array phrase non fa nulla.
 * Se pos si riferisce a lista di tipo letter_t non vuota,
 * prima va deallocata la memoria di tale lista richiamando free_word().
 */
void put_word(struct letter_t *phrase[], int pos, int length, const char *s) {
    if(pos < length){
        if(phrase[pos] != NULL) // se lista non vuota
            free(phrase[pos]);
        phrase[pos] = construct_word(s);
    }
}

/**
 * Stampa un array di elementi di tipo lista di nodi di tipo letter_t.
 */
void print_phrase(struct letter_t *phrase[], int length, char sep) {
    struct letter_t *tmp, *node;
    for(int i=0; i<length; i++){
        tmp = phrase[i];
        for(node = tmp; node != NULL; node = node->next){
            printf("%c", node->letter);
        }
        if(i != length-1)
            printf("%c", sep);
    }
}
