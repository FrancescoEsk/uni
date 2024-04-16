#include <stdio.h>
/*
programma che calcola e stampa a video quanti quadrati perfetti sono presenti
nel file (quadrati.txt)
*/

int quad(int);

int main(void){
    FILE *fid;
    fid = fopen("quadrati.txt", "r");

    if(fid){
        int x;
        while(!feof(fid)){
            fscanf(fid, "%d ", &x);
            if(quad(x))
                printf("%d ", x);
        }
        printf("\n");
        fclose(fid);
    } else {
        printf("Errore\n");
    }
    return 0;
}

int quad(int n){
    if(n==1)
        return 1;
    for(int i=0; i<=n/2; i++)
        if(i*i == n)
            return 1;

    return 0;
}