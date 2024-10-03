#include <stdio.h>
#define N 10
/*
(versione con un solo array)
Crea una copia di un array contentente gli stessi valori di quello fornito, ma senza duplicati
SENZA MEM DINAMICA
e 
CON MEM DINAMICA
*/

int main(void){
    int a[N], check, temp, dim = N;
    for(int i=0; i<N; i++) // leggo array
        scanf("%d", &a[i]);
    
    for(int i=0; i<N; i++){
        check = -1;
        for(int z=i+1; z<N && check==-1; z++){ // controllo se il valore è già contenuto nell'array
            if(a[i] == a[z])
                check=z; // se si, mi salvo la sua posizione
        }

        if(check != -1){
            for(int z=check; z<N-1; z++){
                temp = a[z];
                a[z] = a[z+1];
                a[z+1] = temp;
            }
            dim--; // diminuisco la dimensione da stampare dell'array, siccome ho messo nell'ultima posizione il valore da saltare
        }
    }
    // stampa
    for(int i=0; i<dim; i++)
        printf("%d ", a[i]);
    printf("\n");
    
    return 0;
}