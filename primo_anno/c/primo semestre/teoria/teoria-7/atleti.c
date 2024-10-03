#include <stdio.h>
#define MAX 5
/*
Acquisire info anagrafiche di atleti e calcolare altezza media degli atleti.
Poi stampare le info degli atleti con altezza > media.
*/
typedef struct{
    char nome[11];
    char cognome[21];
    float peso;
    float altezza;
    char nick;
} info_atleta;

int main(void){
    info_atleta a[MAX];
    float somma=0, media;
    
    for(int i=0; i<MAX; i++){
        scanf("%s", a[i].nome); // per le stringhe non serve la &
        scanf("%f", &a[i].peso);
        scanf("%f", &a[i].altezza);
        scanf(" %c", &a[i].nick); // metto uno spazio prima di %c per evitare di prendere come input l'invio
    }

    for(int i=0; i<MAX; i++){
        somma += a[i].altezza;
    }

    media = somma/MAX; // float / intero --> float

    for(int i=0; i<MAX; i++){
        if (a[i].altezza > media){
            printf("Dati dell'atleta con altezza maggiore della media\n");
            printf("Nome: %s\n", a[i].nome);
            printf("Cognome: %s\n", a[i].cognome);
            printf("Altezza: %f\n", a[i].altezza);
            printf("Peso: %f\n", a[i].peso);
            printf("Nick: %c\n", a[i].nick);
        }
    }

    return 0;
}