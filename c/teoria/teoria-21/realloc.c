#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
Consegna ignota, arrivati in ritardo a lezione
*/

int main(void){
    int *p, dim, count=0;

    printf("Quanto grande l'array? ");
    scanf("%d", &dim);
    // alloco memoria
    p = (int*) malloc(sizeof(int) * dim);
    // ottengo valori randomici
    srand(time(NULL));
    for(int i=0; i<dim; i++){
        p[i] = rand();
    }
    int i;
    // contare i multipli di 3
    for(i=0; i<dim; i++){
        if(p[i]%3 == 0)
            count++;
    }
    printf("Il numero di multipli di 3: %d\n", count);

    // aggiungere spazio ad una memoria allocata
    // realloc: celle già scritte rimangono tali. la cella aggiunta è nell'ultima posizione dell'array
    p = (int*) realloc(p, (dim+1) * sizeof(int)); 
    // p punta sempre all'inizio dell'area di memoria

    // adesso i vale dim
    p[i] = count; // inserisco count nell'ultima cella degli array

    p = (int*) realloc(p, (dim+2) * sizeof(int)); // aggiungo un'altra cella

    // devo spostare tutti gli elementi di una posizione in avanti in modo da liberare la prima cella
    for(i=dim+1; i>0;i--){
        p[i] = p[i-1];
    }
    p[0] = count; // popolo il nuovo spazio

    free(p); // alla fine libero la memoria prima di terminare
    
    return 0;
}


