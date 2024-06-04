#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 80

struct node_t {
    char c;
    int count;
    struct node_t *next;
};

struct node_t *string_to_list();
void print_list(struct node_t *head);
struct node_t *insert_on_tail(struct node_t *head, char c, int value);

int main() {
    char s[MAX_LENGTH + 1];
    scanf("%80s", s);

    struct node_t *head = string_to_list(s);
    print_list(head);
    return 0;
}

struct node_t *string_to_list(char *s) {
    struct node_t *lista;
    char l;
    int count=0;
   for(int i=0; s[i] != '\0'; i++){
        if (i == 0){
            l = s[i];
        }
        if(s[i] == l){
            count++;
        } else {
            lista = insert_on_tail(lista, l, count);
            l = s[i];
            count = 1;
        }
   }
   lista = insert_on_tail(lista, l, count);
   return lista;
}

struct node_t *insert_on_tail(struct node_t *head, char c, int value) {
    struct node_t *node = (struct node_t *)malloc(sizeof(struct node_t));
    node->c = c;
    node->count = value;
    node->next = NULL;

    if (head == NULL) {
        head = node;
    } else {
        struct node_t *current = head;

        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
    return head;
}

void print_list(struct node_t *head) {
    while(head != NULL){
        for (int i=0; i<head->count; i++)
            printf("%c", head->c);
        printf(" ");
        head = head->next;
    }
}
