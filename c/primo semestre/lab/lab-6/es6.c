#include <stdio.h>
#define N 100
/*
Chiedere all’utente una sequenza di numeri interi che 
termina con l’inserimento dello 0 (e in ogni caso lunga al 
massimo 100 elementi). Creare un array che contenga 
tutti e soli valori distinti della sequenza (ovvero 
omettendo i duplicati). Visualizzare l’array e il numero di 
elementi unici inseriti.
*/

int main(void){
    int a[N];
    int count=0, x;
    do{
        int check;
        count++;
        do{
            check=1;
            printf("Inserisci un numero: ");
            scanf("%i", &x);
            if (x!=0){
                for (int i=0; i<count-1; i++){
                    if (a[i] == x) check=0;
                }
            }
        } while (check==0);
        a[count-1]=x;
    } while (a[count-1]!=0 && count<100);

    printf("Array risultante:\n");
    for(int i=0; i<count; i++){
        printf("%i ", a[i]);
    }
    printf("\nNumero di valori unici inseriti: %i\n", count);
    return 0;
}