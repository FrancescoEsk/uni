#include <stdio.h>
#include <math.h>
#define N 5
/*
5 punti nel piano cartesiano

x * y

distanza euclidea tra l'ultimo punto generato(sesto) e tutti i punti dell'array

stampa a video il nome del punto, le coordinate e il punto più vicino al sesto
sqrt (x)
pow (x, 2)
*/

typedef struct {
    char nome;
    double x;
    double y;
} punto;

double distanza (punto, punto);

int main(void){
    punto punti[N];
    punto find;
    char c='a';

    for(int i=0; i<N; i++){ // popolare array di punti
        punti[i].nome = c;
        printf("Inserisci x: ");
        scanf("%le", &punti[i].x);
        printf("Inserisci y: ");
        scanf("%le", &punti[i].y);
        c++;
    }
    // punto da cercare
    find.nome = c;
    printf("Inserisci x sesto punto: ");
    scanf("%le", &find.x);
    printf("Inserisci y sesto punto: ");
    scanf("%le", &find.y);
    
    int dist, min, indice = 0; // distanza euclidea
    dist = distanza(find, punti[0]);

    for (int i=0; i<N; i++){
        dist = distanza(find, punti[i]);
        if(min>dist){
            min = dist;
            indice = i;
        }
    }
    printf("Il punto con la distanza euclidea minima è: %c, %le, %le\n", punti[indice].nome, punti[indice].x, punti[indice].y);

    return 0;
}

double distanza(punto a, punto b){
    double x = pow(b.x-a.x, 2) + pow(b.y-a.y, 2);
    return sqrt(x);
}