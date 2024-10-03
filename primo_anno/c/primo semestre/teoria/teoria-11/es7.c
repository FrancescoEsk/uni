#include <stdio.h>
/*
bisottratto intero positivo
1 formato da almeno 3 cifre

a partire dalla terza cifra meno significativa, ogni cifra è 
pari alla differenza in valore assoluto delle due cifre precedenti

sottoprogramma generaBisottratto
c0 cifra meno sign.
c1 penultima cifra
dim num cifre

(2, 5, 5)
xxx52
xx352
x2352
12352
*/

int generaBisottratto(int, int, int);
int diff(int, int);

int main(void){
    printf("%i\n", generaBisottratto(2, 5, 5));
    return 0;
}

int diff(int a, int b){
    if (a-b<0)
        return -(a-b);
    else
        return a-b;
}

int generaBisottratto(int c0, int c1, int dim){
    int r=c0 + c1*10;
    int cf1, cf2, x, pow;
    if (dim<3)
        return -1;
    for(int i=2; i<dim; i++){
        pow = 1;
        for (int x=0; x<=i-2; x++) // calcolo potenza della cifra -2 
            pow *= 10;
        cf1 = (r*10/pow)%10;
        cf2 = (r/pow)%10;

        r += diff(cf1, cf2)*pow*10;

        printf("%i, %i, %i, %i, %i\n", cf1, cf2, diff(cf1,cf2), pow, r);
    }
    int temp = r, count=0;
    while (temp>0){
        temp /= 10;
        count++;
    }
    if (count == dim)
        return r;
    else return -1;
}