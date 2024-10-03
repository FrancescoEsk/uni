#include <stdio.h>
#include <stdlib.h>
#define N 10
/*
(versione con MEM DINAMICA)
Crea una copia di un array contentente gli stessi valori di quello fornito, ma senza duplicati
SENZA MEM DINAMICA
e 
CON MEM DINAMICA
*/

int checkDim(int*);

int main(void){
    int a[N], check, temp=0, dim;
    for(int i=0; i<N; i++) // leggo array
        scanf("%d", &a[i]);
    dim = checkDim(a);
    int *b = (int*) calloc(dim, sizeof(int));
    for(int i=0; i<N; i++){
        check = 0;
        for(int z=i+1; z<N && !check; z++){ // controllo se il valore è già contenuto nell'array
            if(a[i] == a[z])
                check=1; // se si, lo salto
        }
        if(!check){ // se è unico, lo scrivo nel nuovo array
            b[temp] = a[i];
            temp++;
        }
    }
    // stampa
    for(int i=0; i<dim; i++)
        printf("%d ", b[i]);
    printf("\n");
    printf("%d\n", dim);
    return 0;
}

int checkDim(int *a){
    int check=0, d=0;
    for(int i=0; i<N; i++){
        check = 0;
        for(int z=i+1; z<N && !check; z++){ // controllo se il valore è già contenuto nell'array
            if(a[i] == a[z])
                check=1; // se si, lo salto
        }
        if(!check){
            d++;
        }
    }
    return d;
}