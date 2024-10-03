#include <stdio.h>
/*
Scrivere un sottoprogramma che calcola l'area e il 
perimetro di un cerchio di raggio dato. Il 
sottoprogramma riceve come parametri un 
numero in virgola mobile che rappresenta il 
raggio del cerchio e altri due parametri, sempre 
in virgola mobile, in cui verranno salvati i due 
risultati richiesti. 

Scrivere un programma che 
chiede all'utente la lunghezza del raggio del 
cerchio, calcola mediante la funzione sopra e 
visualizza il perimetro e l'area del cerchio. In 
seguito il programma chiede all'utente se vuole 
continuare o meno (0 per continuare, qualsiasi 
altro valore per terminare).
*/

void calc(float, float*, float*);

int main(void){
    float raggio, area, perimetro;
    int check;
    do{
        scanf("%f", &raggio);
        calc(raggio, &area, &perimetro);
        printf("area: %.001f, perimetro: %.001f\nContinuare? (0 per continuare, qualsiasi altro valore per terminare)", area, perimetro);
        scanf("%d", &check);
    } while(check==0);
    
    return 0;
}

void calc(float r, float *area, float *perim){
    *area = r*r*3.14;
    *perim = r*2*3.14;
}