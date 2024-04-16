#include <stdio.h>
#define DIM 30
/*
scrivere un programma che apre in lettura un file di testo il cui nome di max 30 char 
e' richiesto all'utente.
il programma legge la sequenza di valori interi salvati nel file (la cui lunghezza non è nota
a priori) e la visualizza.
*/

int main(void){
    FILE *fid;
    char s[DIM+1];
    scanf("%s", s);
    fid = fopen(s, "r");

    if(fid){   
        int x;
        while(!feof(fid)){
            fscanf(fid, "%d ", &x);
            printf("%d ", x);
        }
        printf("\n");
        fclose(fid);
    } else{
        printf("Errore\n");
    }
    return 0;
}