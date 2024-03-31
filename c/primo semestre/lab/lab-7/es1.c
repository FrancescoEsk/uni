#include <stdio.h>
#define D1 3
#define D2 2

/*
Si scriva un programma che copi tutti i valori di una
matrice int M[D1][D2] in un array di dimensione D1*D2
eliminando nel processo di copia tutti i duplicati se questi
sono valori negativi (<0)
*/

int main(void){
    int M[D1][D2];
    int a[D1*D2] = {0};
    int c, t = 0;

    for(int i=0; i<D1; i++){
        for (int z=0; z<D2; z++){
            printf("inserisci: ");
            scanf("%i", &M[i][z]);
        }
    }

    for(int i=0; i<D1; i++){
        for (int z=0; z<D2; z++){
            c = 0;
            for (int k=0; k<D1*D2; k++){
                if (M[i][z] == a[k] && M[i][z] < 0)
                    c = 1;
            }
            if (c == 0){
                a[t] = M[i][z];
                t++;
            }
        }
    }

    for (int i=0; i<t; i++)
        printf("%i ", a[i]);
    printf("\n");

    return 0;
}