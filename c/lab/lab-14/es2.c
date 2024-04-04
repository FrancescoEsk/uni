#include <stdio.h>
/*
Scrivere le versioni ricorsiva e iterativa (con il while) di una funzione
 doble fx(double a, int n)
che calcola il seguente valore:

*/

double fx(double, int);

int main(void){
    double x;
    int n;
    scanf("%le", &x);
    do{
        scanf("%d", &n);
    } while(n<0);
    printf("%le\n", fx(x, n));
    return 0;
}

double fx(double a, int n){
    if(n==1)
        return (a-1/a);
    else
        return (a - n/a) + fx(a, n-1);
}