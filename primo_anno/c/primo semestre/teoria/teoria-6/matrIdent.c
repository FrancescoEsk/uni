#include <stdio.h>
#define D 3
/*
Data una matrice quadrata dire se è una matrice identità 
Esempio:

1 0 0
0 1 0
0 0 1
*/

int main(void){
    int m[D][D], flag=1;

    for (int i=0; i<D; i++){
        for(int z=0;z<D;z++){
            if (i != z && m[i][z]!=0)
                flag = 0;
            if (i==z && m[i][z]!=1)
                flag = 0;
        }
    }

    if (flag)
        printf("La matrice e' una matrice identita'\n");
    else
        printf("La matrice non e' una matrice identita'\n");

    return 0;
}