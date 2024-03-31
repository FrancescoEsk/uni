#include <stdio.h>
#define N 10
/*
Dato un numero sicuramente positivo, salvare in una struttura
quante volte ogni cifra compare
*/

typedef struct {
    int cifra;
    int num;
} t;

int main(void){
    int n, x;
    t t1[N];
    printf("Inserisci un numero: ");
    scanf("%i", &n);
    for (int i=0; i<N; i++){
        t1[i].cifra = i;
        t1[i].num = 0;
        x = n;
        while(x>0){
            if (x%10 == i)
                t1[i].num++;
            x /= 10;
        }
        printf("Cifra: %i, Count: %i\n", t1[i].cifra, t1[i].num);
    }
    return 0;
}