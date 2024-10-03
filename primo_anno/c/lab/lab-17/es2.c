#include <stdio.h>
#include <stdlib.h>
/*
Sia dato array contenente una sequenza ordinata di interi ed allocato dinamicamente.

Si scriva una funzione C che ricevendo in ingresso l’array, la sua dimensione ed un intero, 
modifichi il vettore in questione inserendo il nuovo intero nella posizione corretta.

Ad esempio, se il vettore v contiene gli interi 4 32 57 98 la funzione chiamata con i parametri 
v, 4, 50 dovrà modificare v in un vettore di 5 elementi contenente 4 32 50 57 98.
*/

void function(int*, int, int);

int main(void){
    int *a, n, x;
    scanf("%d", &n);
    a = (int *) malloc(sizeof(int)*n);
    if(a == NULL){
        printf("Errore\n");
        return -1;
    }
    
    for(int i=0; i<n; i++)
        scanf("%d ", &a[i]);

    scanf("%d", &x);
    function(a, n, x);
    for(int i=0; i<n+1; i++)
        printf("%d ", a[i]);
    printf("\n");
    free(a);
    return 0;
}

void function(int *a, int dim, int x){
    int check = 0;
    for(int i=0; i<dim && !check; i++){
        if(a[i]>x && !check){
            check = 1;
            for(int z=dim; z>=i; z--){
                a[z+1] = a[z];
            }
            a[i] = x;
        }
    }
}