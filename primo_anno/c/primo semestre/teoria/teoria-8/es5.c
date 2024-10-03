#include <stdio.h>
#define N 3
/*
due array ordinati
di massimo 10 
costruire un terzo array ordinato che unisca i due
*/

int main(void){
    int a[N], b[N], v[N*2], x, j;
    printf("Array 1: \n");
    for (int i=0; i<N; i++){
        do  scanf("%i", &a[i]);
        while(a[i] <= 0);
    }
    printf("Array 2: \n");
    for (int i=0; i<N; i++){
        do  scanf("%i", &b[i]);
        while(b[i] <= 0);
    }

    for (int i=0; i<N; i++){
        v[i] = a[i];
    }
    for (int i=N; i<N*2; i++){
        v[i] = b[i];
    }

    // BUBBLESORT
	for (int i=1;i<N*2;i++){ // per ogni numero nel vettore (saltando la prima posizione)
		x = v[i]; 	// salvo il numero nella posizione
		j = i-1;	// prendo l'indice prima
		while (j>=0 && v[j]>x){ // finché il numero è minore di quelli precedenti, faccio spazio spostando i numeri prima in avanti
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = x;	// quando abbiamo fatto spazio, inseriamo il numero nella sua nuova posizione
	}
    printf("Array ordinato unito: \n");
    for (int i=0; i<N*2; i++)
		printf("%i ", v[i]);
    return 0;
}