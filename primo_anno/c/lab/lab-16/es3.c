#include <stdio.h>
/*
 Scrivere un programma C che chiede all’utente una sequenza di numeri 
a priori illimitata e che termina con l’inserimento del numero 0 – non fa parte della sequenza.
 Il programma deve salvare i numeri (0 escluso) in un file di nome “valori.txt” e come ultimo valore 
deve scrivere nel file quanti numeri sono stati salvati.
 Ad esempio se l’utente inserisce 5 2 4 0 nel file nel file “valori.txt” troveremo 5 2 4 3.
*/

int main(void){
    FILE *fid;
    int n, count=0;

    if( (fid = fopen("valori.txt", "w")) ){
        scanf("%d", &n);
        while(n!=0){
            fprintf(fid, "%d ", n);
            count++;
            scanf("%d", &n);
        }
        fprintf(fid, "%d\n", count);
        fclose(fid);
    } else {
        printf("Errore\n");
    }
    
    return 0;
}