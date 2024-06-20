#include <stdio.h>
#include <stdlib.h>

/*

*/

struct list_t{
    int val;
    int c;
    struct list_t *next;
};

struct list_t* crealista(int*, int);
struct list_t* appendlista(struct list_t*, int, int);
void printlista(struct list_t*);

int main(void){
    int a[] = {1, 3, 4, 1, 2, 3, 3, 3, 4, 5};
    struct list_t *lista = crealista(a, 10);
    printlista(lista);
    return 0;
}

struct list_t* appendlista(struct list_t *lista, int num, int c){
    struct list_t *new, *tmp;
    new = (struct list_t*) malloc(sizeof(struct list_t));
    if(new == NULL)
        return NULL;
    
    if(lista->val == -1){
        lista->val = num;
        lista->c = c;
        lista->next = NULL;
        return lista;
    }
    new->val = num;
    new->c = c;
    new->next = NULL;

    for(tmp = lista; tmp->next != NULL; tmp = tmp->next);
    tmp->next = new;

    return lista;
}

struct list_t* crealista(int *a, int n){
    struct list_t *head, *lista;
    
    lista = (struct list_t*) malloc(sizeof(struct list_t));

    if(lista == NULL)
        return NULL;

    head = lista;
    lista->val = -1;

    int cnum;
    for(int i=0; i<n; i++){
        if(a[i] != -1){
            cnum = 1;
            
            for(int z=i+1; z<n; z++){
                if(a[i] == a[z] && a[z] != -1){
                    cnum++;
                    if(z+1 < n){
                        a[z] = -1;
                    }
                }
            }

            lista = appendlista(lista, a[i], cnum);
        }
        
    }

    return head; 
}

void printlista(struct list_t *lista){
    while(lista != NULL){
        printf("(%d, %d)", lista->val, lista->c);
        if(lista->next != NULL)
            printf(" -> ");
        lista = lista->next;
    }
    printf("\n");
}