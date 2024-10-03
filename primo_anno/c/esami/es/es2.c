#include <stdio.h>
#include <stdlib.h>
/*
int main() {
char binary[] = "0100100001100101011011000110110001101111";
struct mychar_t *head = binary_to_mycharlist(binary);
print_mycharlist(head);
printf("\n");
return 0;
}
produca il seguente risultato:
Hello
Nella funzione main() la stringa binary fornita in ingresso si suppone valida e contiene la codifica binaria
dei codici ASCII dei caratteri che la compongono. Per esempio, i primi 8 caratteri 01001000 rappresentano il
numero decimale 72 che corrisponde al simbolo H.
*/

struct mychar_t{
    char val;
    struct mychar_t *next;
};

struct mychar_t* binary_to_mycharlist(char*);
void print_mycharlist(struct mychar_t*);

int main(void){
    char binary[] = "0100100001100101011011000110110001101111";
    struct mychar_t *head = binary_to_mycharlist(binary);
    print_mycharlist(head);
    printf("\n");
    return 0;
}

struct mychar_t* binary_to_mycharlist(char *s){
    struct mychar_t *lista, *head, *new;
    lista = (struct mychar_t*) malloc(sizeof(struct mychar_t));
    if(lista == NULL){
        printf("Memoria piena\n");
        return NULL;
    }

    head = lista;
    int x=0;
    char str[8], ris;

    for(int i=0; s[i] != '\0'; i++){
        str[x] = s[i];
        if(x == 7){
            ris = 0;
            int pow=1;
            while(x != -1){
                ris += (str[x]-48) * pow; // sottraggo 48 dal char, per ottenere la cifra
                pow *= 2;
                x--;
            }
            // aggiungo il ris alla lista
            if(lista->val){
                new = (struct mychar_t*) malloc(sizeof(struct mychar_t));
                if(new == NULL){
                    printf("Memoria piena\n");
                    return head;
                }

                new->val = ris;
                new->next = NULL;
                lista->next = new;
                lista = lista->next;
            } else {
                lista->val = ris;
                lista->next = NULL;
            }

        }
        x++;
    }
    return head;
}

void print_mycharlist(struct mychar_t *lista){
    while (lista != NULL){
        printf("%c", lista->val);
        lista = lista->next;
    }
}