#include <stdio.h>
/*
 Scrivere un programma C che conta i valori compresi in un intervallo [a, b] 
presenti in file di testo, utilizzando le funzioni fscanf() e feof().
 Esempio di contenuto del file di testo e di output del programma:
    4 8 19
    99 1
    7 7 9 10
    3 20
    23
    18
 $ ./esercizio7
Ci sono 5 valori nell'intervallo [10, 20]
*/

int main(void){
    FILE *fid;

    char c, a, b;
    if( (fid = fopen("testo.txt", "r"))){
        int count=0;

        do{ // popolo array da cercare
            printf("Inserisci intervallo: ");
            scanf(" %c", &a);
            scanf(" %c", &b);
        } while (a>=b);

        while(!feof(fid)){
            
            fscanf(fid, " %c", &c);
            if(c>=a && c<=b)
                count++;
        }
        printf("Ci sono %d valori nell'intervallo\n", count);
        fclose(fid);
    } else {
        printf("Errore\n");
    }
    return 0;
}