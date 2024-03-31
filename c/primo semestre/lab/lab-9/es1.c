#include <stdio.h>

/*
Si consideri la spesa al supermercato dove ogni articolo
comprato è caratterizzato da un codice, un prezzo e un
eventuale sconto espresso in percentuale (che potrebbe essere
0). Si scriva un programma C non scomposto in
sottoprogrammi che permetta di:

 memorizzare le informazioni di ogni articolo acquistato in
una variabile strutturata opportuna

 inserire da tastiera una sequenza a priori illimitata di articoli
comprati (la sequenza termina quando viene inserito il valore
-1 come codice di un articolo, tale codice ovviamente non fa
parte della sequenza).

 Calcolare e stampare il numero di articoli scontati acquistati e
la spesa totale.
*/

typedef struct{
    int codice;
    float prezzo;
    int sconto;
} articolo;

int main(void){

    int bought = 0;
    float totale = 0;
    articolo a;

    do {
        a.codice = 0; a.prezzo = 0; a.sconto = 0;
        printf("Inserire il codice articolo (-1 per terminare): ");
        scanf("%i", &a.codice);
        if (a.codice != -1){
            do{
                printf("Inserire il prezzo dell'articolo: ");
                scanf("%f", &a.prezzo);
            } while (a.prezzo <= 0);
            
            do{
                printf("Inserire lo sconto dell'articolo: ");
                scanf("%i", &a.sconto);
            } while (a.sconto < 0 && a.sconto >100);
            if (sconto>0)
                bought++;
            totale = totale + ( a.prezzo * ( (100-(float)a.sconto) / 100) );
        }

    } while(a.codice != -1);

    printf("Articoli scontati acquistati: %i\nTotale spesa: %.2f\n", bought, totale);

    return 0;
}