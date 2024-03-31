#include <stdio.h>
/*
 Scrivere una funzione sort che ordina 3 interi in 
ordine crescente. La funzione non deve utilizzare 
un array ma 3 puntatori.
 La funzione deve essere richiamata dalla 
funzione main, la quale si occupa anche di 
richiedere i tre interi all’utente e stampare il 
risultato.
*/

void sort(int*, int*, int*);
void swap(int*, int*);

int main(void){
    int a, b, c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    sort(&a, &b, &c);
    printf("%d %d %d\n", c, b, a);
    return 0;
}

void sort(int *a, int *b, int *c){
    int temp;
    if(*a>*b && *a>*c){
        if(*c > *b){
            swap(c, b);
        }
    } else if (*b > *c && *b > *a){
        swap(a, b);
        if(*a < *c){
            swap(b, c);
        }
    } else{
        swap(a, c);
        if(*b<*c){
            swap(b, c);
        }
    }
}

void swap(int *n1, int *n2){
    int temp = *n2;
    *n2 = *n1;
    *n1 = temp;
}