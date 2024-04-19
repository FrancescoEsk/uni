#include <stdio.h>
#define DIM 50
/*
 Scrivere un programma C che conta il numero di spazi, 
tabulazioni e righe di un file di testo.
 Chiedere all’utente se vuole inserire il testo direttamente 
da terminale oppure vuole specificare il nome di un file di testo.
*/

int main(void){
    FILE *fid;
    char s[DIM+1], x[DIM+1];
    int countT=0, countS=0, countR=0;
    scanf("%s", x);

    if ( (fid = fopen(x, "r")) ){
        fscanf(fid, "%s", s);
        for(int i=0; s[i]!='\0'; i++){
            if(s[i]=='\t')
                countT++;
            if(s[i]== '\n')
                countR++;
            if(s[i]==' ')
                countS++;
        }
        printf("Spazi: %d\nTabulazioni: %d\nRighe (newline): %d\n", countS, countT, countR);

    } else {
        printf("Errore\n");
    }
    return 0;
}