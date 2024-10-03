#include <stdio.h>
/*
mcd(m, n) in maniera ricorsiva

1. il mcd fra due numeri m e n è uguale a m se m=n
2. il mcd fra due numeri m e n è uguale a mcd(m-n, n) se m>n
3. è uguale a mcd(m, n-m) se m<n
*/

int mcd(int, int);

int main(void){
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    printf("%d\n", mcd(a, b));
    return 0;
}

int mcd(int m, int n){
    if(m==n)
        return m;
    else if(m>n)
        return mcd(m-n, n);
    else
        return mcd(m, n-m);
}