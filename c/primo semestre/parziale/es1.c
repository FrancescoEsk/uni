# include <stdio.h>
# define DIM 10

/*
domanda
Scrivere un programma C che:
Richiede all’utente di inserire 10 double.
Ne calcola la media
Trova il più piccolo di quelli che stanno sopra la media.
Esempio:
se l'utente immette: 1, 7, 9, 2, 5, 8, 3, 8, 8, 7
la media è 5.8
il più piccolo dei valori che ci stanno sopra è 7
*/

int main(void) {
    double in[DIM];
    double sum = 0;
    double media;
    double min_sopra = 0.0;
    int i;
    // TO DO 
    for (i=0; i<DIM; i++){
        scanf("%le", &in[i]);
        sum+=in[i];
    }
    media = sum / DIM;
    for (i=0; i<DIM; i++){
        if (in[i]>media && i==0)   min_sopra = in[i];
        if (in[i]>media && min_sopra == 0.0) min_sopra = in[i];
        if (in[i]>media && in[i]<media)   min_sopra = in[i];
    }
    printf("Media: \%.2lf\n", media);
    printf("Il valore piu' piccolo tra quelli sopra la media e': \%.2lf\n", min_sopra);
    return 0;
}