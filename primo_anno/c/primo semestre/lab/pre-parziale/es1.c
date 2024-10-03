#include <stdio.h>
/*
scrivere il sottoprogramma int higerdigit(int n, int m) che ricevuti in ingresso 
due numeri interi int n e int mnon negativi, restituisce la cifra più alta tra
quelle presenti nei due numeri, se i due numeri sono formati dallo stesso numero di cifre
da -1.
*/

int higherdigit(int ,int);
int maxC(int);
int nC(int);

int main(void){
    int n, m;
    do{
        printf("Inserisci m ed n: ");
        scanf("%i %i", &n, &m);
    } while(n<0 || m<0); // numeri entrambi positivi per continuare
    printf("Higher digit: %i\n", higherdigit(n, m));
    return 0;
}

int nC(int n){
    int x=0;
    while (n>0){
        x++;
        n /= 10;
    }
    return x;
}

int maxC(int n){ // calcola la cifra più grande del numero dato
    int x, r=0;
    while (n>0){
        x = n%10;
        if(!r || x > r)
            r = x;
        n /= 10;
    }
    return r;
}

int higherdigit(int n, int m){ // confronta le cifre più grandi di due numeri e da il maggiore (-1 se sono uguali)
    int nM, mM;
    nM = maxC(n);
    mM = maxC(m);
    if (nC(n) == nC(m))
        return -1;
    else if(nM > mM)
        return nM;
    else    
        return mM;
}