#include <stdio.h>
#include <stdlib.h>
#define DIM 5
/*

*/

int main(void){
    int n, d, type;
    
    do{ scanf("%d", &n); } while(n<0 || n%2 == 0);
    
    int** m = (int**) malloc(sizeof(int*)*n);

    for(int i=0; i<n; i++){ // allocamento righe
        m[i] = (int*) malloc(n*sizeof(int)); // alloco gli array delle righe
    }

    if(m == NULL) return -1;

    for(int i=0; i<n; i++)
        for(int z=0; z<n; z++)  scanf("%d", &m[i][z]);
    
    
    do{ scanf("%d", &d); } while(d<= -(n-1) || d>= (n-1));
    do{ scanf("%d", &type); } while(type< 0 || type> 2);

    int somma=0;
    switch (type)
    {
    case 0:
        for(int i=0; i<n; i++)
            if(i+d >= 0 && i+d <n)
                somma += m[i][i+d];
        break;
    
    case 1:
        for(int i=0; i<n; i++)
            for(int z=0; z<n; z++)
                if(z+d >= i)
                    somma += m[i][z];
        break;

    case 2:
        for(int i=0; i<n; i++)
            for(int z=0; z<n; z++)
                if(i==0 && z==n/2)
                    somma += m[i][z];
                else if(i==1 && z>=(n/2)-1 && z<=(n/2)+1)
                    somma += m[i][z];
                else if(i>1)
                    somma += m[i][z];
        break;
    }
    
    printf("%d\n", somma);
    return 0;
}