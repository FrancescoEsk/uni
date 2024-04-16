#include <stdio.h>
/*
chiede all'utente una sequenza di lunghezza indefinita di numeri positivi
terminata da un valore non positivo 
il programma conta per ciascun valore della sequenza il numero di divisori propri ( diversi da se stesso )
e salva il risultato in un file 
-> su ogni riga     valore_letto num_divisori_propri

1 5 4 3 2 8 9 -1

1 0
5 1
4 2
3 1
2 1
8 3
9 2

*/

int div(int);

int main(void){
    int n;
    FILE *fid;
    if ( (fid = fopen("es8.txt", "w")) ){
        scanf("%d", &n);
        while(n>0){
            fprintf(fid, "%d %d\n", n, div(n));
            scanf("%d", &n);
        }

        fclose(fid);
    } else {
        printf("Errore\n");
    }
    return 0;
}

int div(int a){
    int r=0;
    for(int i=1; i<=a/2; i++){
        if(a%i == 0)
            r++;
    }
    return r;
}