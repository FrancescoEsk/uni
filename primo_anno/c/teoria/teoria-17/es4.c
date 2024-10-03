#include <stdio.h>
#define DIM 30
/*
apre in scrittura un file il cui nome (max 30 char) è chiesto all'utente.
il programma chiede all'utente quanti valori vuole inserire, li aquisisce e li salva sul file
*/

int main(void){
    FILE *fid;
    char s[DIM+1];
    scanf("%s", s);
    fid = fopen(s, "w");
    if (fid){
        int x, a;
        printf("Quanti valori vuoi scrivere nel file? ");
        scanf("%d", &x);

        for(int i=0; i<x; i++){
            scanf("%d", &a);
            fprintf(fid, "%d ", a);
        }

        fclose(fid);
    } else {
        printf("Errore\n");
    }
    return 0;
}