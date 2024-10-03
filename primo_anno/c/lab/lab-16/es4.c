#include <stdio.h>
/*
Scrivere un programma C che crea il file di testo “tabellina.txt” con la tabellina pitagorica 
fino a un dato numero (per es. fino a 5).
 Utilizza il formato "%3i\t" per allineare i numeri a destra con almeno 3 spazi come dimensione minima.
*/

int main(void){
    FILE *fid;

    if ( (fid = fopen("tabellina.txt", "w")) ){
        int n;
        scanf("%d", &n);
        for(int i=1; i<=n; i++){
            for (int z=1; z<=10; z++)
                fprintf(fid, "%3i\t", i*z);
            fprintf(fid, "\n");
        }
        fclose(fid);
    } else {
        printf("Errore\n");
    }
    return 0;
}