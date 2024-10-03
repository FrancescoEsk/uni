#include <stdio.h>
#define DIM 30
/*
 Scrivere un programma C che legge e stampa a video un file di testo.
 In particolare, il programma chiede all’utente di inserire il nome di un file di testo, 
legge un carattere alla volta con la funzione fgetc() dal file e lo stampa a video.
 Nel caso vi siano errori nell’apertura del file, il programma visualizza il messaggio di errore:
  Errore di apertura del file: <nome file>
*/

int main(void){
    FILE *fid;
    char s[DIM+1];
    printf("Inserisci nome file: ");
    scanf("%s", s);

    if ( (fid = fopen(s, "r")) ){
        while(!feof(fid)){
            printf("%c", fgetc(fid));
        }
        printf("\n");
        fclose(fid);
    } else {
        printf("Errore di apertura del file: %s\n", s);
    }
    return 0;
}