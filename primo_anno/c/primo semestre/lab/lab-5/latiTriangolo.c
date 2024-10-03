#include <stdio.h>

// inserisci i tre lati del triangolo e dici se è scaleno, equilatero oppure isoscele

int main(void){
    float n1, n2, n3;
    do{
    printf("Inserisci il primo lato: ");
    scanf("%f", &n1);
    printf("Inserisci il secondo lato: ");
    scanf("%f", &n2);
    printf("Inserisci il terzo lato: ");
    scanf("%f", &n3);
    } while (n1 <= 0 || n2 <= 0 || n3 <= 0);

    if ((n1+n2) < n3)
        printf("Il triangolo inserito è errato\n");
    else{
        if (n1 == n2 && n2 == n3 && n1 == n3)
            printf("Il triangolo inserito è equilatero\n");
        else if (n2 == n3 || n1 == n3 || n2 == n1)
            printf("Il triangolo inserito è isoscele\n");
        else if (n1 != n2 && n2 != n3 && n1 != n3)
            printf("Il triangolo inserito è scaleno\n");
    }
    return 0;
}