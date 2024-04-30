#include <stdio.h>
#include <stdlib.h>
/*
esempio di allocazione dinamica di un array
*/

int main(void){
    int *p;
    int quanti;
    printf("Quanti elementi? ");
    scanf("%d", &quanti);
    p = malloc(quanti*sizeof(int));
    // p = calloc(quanti, sizeof(int));
    if(p!=NULL){
        for(int i=0; i<quanti; i++){
            printf("Elemento: ");
            scanf("%d", &p[i]);
        }
        for(int i=0; i<quanti; i++){
            printf("%d ", p[i]);
        }
    } else {
        printf("Errore\n");
    }
    
    free(p);
    return 0;
}