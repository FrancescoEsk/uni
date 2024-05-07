#include <stdio.h>
#define N 10
/*
(versione con due array)
Crea una copia di un array contentente gli stessi valori di quello fornito, ma senza duplicati
SENZA MEM DINAMICA
e 
CON MEM DINAMICA
*/

int main(void){
    int a[N], b[N], check, temp=0, dim=0;
    for(int i=0; i<N; i++) // leggo array
        scanf("%d", &a[i]);
    
    for(int i=0; i<N; i++){
        check = 0;
        for(int z=i+1; z<N && !check; z++){ // controllo se il valore è già contenuto nell'array
            if(a[i] == a[z])
                check=1; // se si, lo salto
        }
        if(!check){ // se è unico, lo scrivo nel nuovo array
            b[temp] = a[i];
            temp++;
            dim++; // diminuisco la dimensione da stampare dell'array
        }
    }
    // stampa
    for(int i=0; i<dim; i++)
        printf("%d ", b[i]);
    printf("\n");
    
    return 0;
}
