#include <stdio.h>
/*
Definire un tipo di dato strutturato per rappresentare una frazione 
in termini di numeratore e denominatore (due numeri interi). 
Scrivere un programma che acquisisce due frazioni ed esegue la 
somma. Il programma deve in seguito semplificare il risultato 
dell'operazione rappresentando l'eventuale segno meno nel 
numeratore.
*/

typedef struct { // DEFINIZIONE DI UN NUOVO TIPO DI DATO
        int num;
        int den;
    } fraz;

fraz fixsgn(fraz f){ // funzione che assicura che una frazione non sia -/-
    
    if (f.num < 0 && f.den < 0){ // se la frazione è negativa sia sopra che sotto la metto tutta postiva
        f.den = -f.den;
        f.num = -f.num;\
    } else{
        if (f.den < 0 && f.num >= 0){ // se la frazione è negativa solo sotto, metto negativo il sopra e nego il sotto
            f.den = -f.den;
            f.num = -f.num;
        }
    }
    return f;
}

int main(void){
    int max;
    fraz fraz1, fraz2, frazF;

    printf("Inserisci il numeratore della frazione 1: ");
    scanf("%i", &fraz1.num);
    do{
        printf("Inserisci il primo denominatore: ");
        scanf("%i", &fraz1.den);
    } while(fraz1.num*fraz1.den == 0);

    printf("Inserisci il numeratore della frazione 2: ");
    scanf("%i", &fraz2.num);
    do{
        printf("Inserisci il secondo denominatore: ");
        scanf("%i", &fraz2.den);
    } while(fraz2.num*fraz2.den == 0);

    // aggiusto il segno delle frazioni
    fraz1 = fixsgn(fraz1);
    fraz2 = fixsgn(fraz2);

    // calcolo la somma delle frazioni
    frazF.num = fraz1.num*fraz2.den + fraz2.num*fraz1.den;
    frazF.den = fraz1.den*fraz2.den;

    if (frazF.num >= frazF.den) max = frazF.num;// trovo il massimo tra il numeratore e il denominatore
    else   max = frazF.den;
    
    for (int i=2; i<=max; i++){ // for fino al massimo della frazione
        if (frazF.num % i == 0 && frazF.den %i == 0){ // se la frazione è semplificabile per i
            frazF.num /= i; // divido tutto per i
            frazF.den /= i;
            i = 1; // e ricomincio il for per vedere se la nuova frazione è ancora semplificabile
        }
    }

    printf("Frazione risultante: %i/%i\n", frazF.num, frazF.den);
    
    return 0;
}