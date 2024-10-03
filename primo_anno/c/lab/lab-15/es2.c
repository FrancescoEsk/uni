#include <stdio.h>
/*
Si scriva un programma che utilizzando una struttura per l’anno 
il mese ed il giorno,chiamata “miadata”, calcoli il giorno successivo 
ad un giorno chiesto all’utente usando
printf("\ndimmi che giorno è oggi (gg mm aaaa):");
scanf("%i%i%i", ...............);
*/

typedef struct{
    int g, m, a;
} miadata;

int check(int, int, int);

int main(void){
    int gg, mm, aaaa;
    printf("\ndimmi che giorno è oggi (gg mm aaaa):");
    do{
        scanf("%d", &gg);
        scanf("%d", &mm);
        scanf("%d", &aaaa);
    } while(check(gg, mm , aaaa)==1 || (mm<0 && mm>12));

    miadata d = {gg, mm, aaaa};

    d.g++;
    if(check(d.g, d.m, d.a)==1){
        d.g=1;
        d.m++;
        if(d.m>12){
            d.m=1;
            d.a++;
        }
    }
    printf("%d %d %d\n", d.g, d.m, d.a);
    return 0;
}

int check(int g, int m, int a){
    int c=0;
    if (a%4 == 0 && a%100 != 0)
        c=1;

    switch(m){
        case 1:
        case 5:
        case 7:
        case 8:
        case 10: 
        case 12:
            if(g>31)
                return 1;
            break;
        case 2:
            if((g>28 && !c) || (g>29 && c))
                return 1;
            break;
        default:
            if(g>30)
                return 1;
            break;
    }
    return 0;
}
