#include <stdio.h>
#define D 4
/*
verificare se una matrice è simmetrica
*/

int main(void){
    int m[D][D] = {
        {1, 2, 3, 4},
        {2, 7, 6, 5},
        {3, 6, 4, 8},
        {4, 5, 8, 9}
    };
    int check, i;
    for(i=0, check=1; i<D&&check; i++){
        for(int z=0; i<D&&check; z++){
            if (m[i][z] != m[z][i]) check=0;
        }
    }

    if (check) printf("La matrice e' simmetrica\n");
    else printf("La matrice non e' simmetrica\n");
    return 0;
}