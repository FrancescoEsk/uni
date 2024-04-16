#include <stdio.h>
/*
LETTURA FILE

fscanf(fid, "%d %d, %s", &a, &b, s);

possiamo leggere una serie di valori dal file puntato dal descrittore fid
e vengono salvati nella lista di variabili

lettura SEQUENZIALE

fscanf(); esegue una lettura sequenziale. Quando arriva alla fine del file 
non modifica il contenuto delle variabili specificate (non legge più niente)

per capire se siamo arrivati alla fine del file
--> feof(fid);
se 1, siamo arrivati alla fine, altrimenti 0


Scrivere un programma che apre in lettura un file ciao.txt che contiene una sequenza di numeri
(lunghezza non nota) e ne visualizza il contenuto
*/

int main(void){
    FILE *fid;

    fid = fopen("ciao.txt", "r");

    if(fid){
        int x, sum=0;
        while(!feof(fid)){ // continua fino alla fine della lettura del file
            fscanf(fid, "%d", &x);
            sum += x;
        }
        printf("%d\n", sum);
        fclose(fid);
    } else {
        printf("Errore. File non aperto.\n");
    }
    return 0;
}