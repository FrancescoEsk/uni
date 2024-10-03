#include <stdio.h>
#define N 10
/*
dato un array usiamo 2 puntatori per indicare le componenti con valore minimo e massimo
*/

int main(void){
    int a[N], *maxPtr = NULL, *minPtr = NULL;
    for (int i=0; i<N; i++){
        scanf("%d", &a[i]);
    }

    minPtr = &a[0];
    maxPtr = &a[0];
    for (int i=1; i<N; i++){
        if (*minPtr>a[i])
            minPtr = &a[i];
        
        if (*maxPtr<a[i])
            maxPtr = &a[i];
    }

    printf("min: %d e max: %d\n", *minPtr, *maxPtr);
    return 0;
}