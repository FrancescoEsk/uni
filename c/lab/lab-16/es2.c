#include <stdio.h>
#define DIM 30
/*
 Scrivere un programma C che si comporta come il programma dell’esercizio 1, 
ma legge una riga alla volta con la funzione fgets() dal file prima di stamparla a video.
*/

int main(void){
    FILE *fid;
    char s[DIM+1], x[DIM+1];
    printf("Inserisci nome file: ");
    scanf("%s", s);

    if ( (fid = fopen(s, "r")) ){
        while(fgets(x, DIM, fid) != NULL){
            printf("%s", x);
        }
        fclose(fid);
    } else {
        printf("Errore di apertura del file: %s\n", s);
    }
    return 0;
}