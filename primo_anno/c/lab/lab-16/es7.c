#include <stdio.h>
#include <stdlib.h>
/*
 Scrivere un programma C che legge un file di testo e fornisce in output le seguenti statistiche:
numero di righe
numero di caratteri
numero di lettere (case insensitive)
 Nel caso di errori nell’apertura del file, utilizzare la funzione exit() definita in stdlib.h 
che termina il processo, chiudendo tutti i file aperti e i processi figli eventualmente creati:
void exit(int status);
status: valore restituito al processo padre
– – –
 Attenzione alla codifica dei caratteri!
 Programmi come hexdump visualizzano i byte in
esadecimale (ottale) e in codice ASCII (hexdump -C)
 “Il diavolo si nasconde nei dettagli” (per es. negli accenti curvi)
ASCII
0a7175656c206e75 6c6c610a6427696e |.quelnulla.d'in|
UTF-8
0a7175656c206e75 6c6c610a64e28099 |.quelnulla.d...| 696e657361757269 62696c6520736567 |inesauribileseg|2
*/

int main(void){
    FILE *fid;

    if( (fid = fopen("testo.txt", "r"))){
        char c;
        int chr=0, r=1, lt=0;
        while(!feof(fid)){
            fscanf(fid, " %c", &c);
            chr++;
            if(c == '\n')
                r++;
            
            if(c>'A' && c<'z')
                lt++;
        }

        printf("Righe: %d\nCaratteri: %d\nLettere: %d\n", r, chr, lt);
        fclose(fid);
    } else {
        
        void exit(int status);
        printf("Errore\n");
    }
    return 0;
}