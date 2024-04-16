#include <stdio.h>
#define DIM 15
/*
scrivere un programma che legge da file stringhe (15 char max) e stampa a video quelle formate da soli
caratteri numerici

"Oggi è il 16 aprile 2024" --> 16 2024
*/

int main(void){
    FILE *fid;
    fid = fopen("testo.txt", "r");
    char s[DIM+1]; // var per lettura delle stringhe
    int check;
    if(fid){
        while(!feof(fid)){
            fscanf(fid, "%s", s); // legge una stringa fino allo spazio successivo
            // verificare se s è fatta di soli numeri
            check=1;
            for(int i=0; s[i]!='\0' && check; i++){
                if(s[i] < '0' || s[i] > '9')
                    check=0;
            }
            if(check) // se è fatta di soli numeri stampo
                printf("%s ", s);
        }
        printf("\n");
        fclose(fid);
    } else {
        printf("Errore\n");
    }
    return 0;
}