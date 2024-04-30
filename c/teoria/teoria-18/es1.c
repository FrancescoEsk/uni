#include <stdio.h>
#define LINE 255
/*

fgets()

legge un'intera riga del file (fino a '\n')

PARAMETRI:
    array di caratteri (variabile in cui inserire la stringa da leggere)
    num di caratteri massimo (int)
    puntatore a file (FILE)

Scrivere un programma che legge una serie di righe da un file
e le stampa a video
*/

int main(void){
    FILE *fid;

    char s[LINE];
    if( (fid = fopen("testo.txt", "r"))){
        int r=1;
        while(!feof(fid)){
            fgets(s, LINE, fid);
            printf("Riga %d: %s", r, s);
            r++;
        }
        printf("\n");
        fclose(fid);
    } else {
        printf("Errore\n");
    }
    return 0;
}