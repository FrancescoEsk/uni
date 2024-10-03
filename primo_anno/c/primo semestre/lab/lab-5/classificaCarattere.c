#include <stdio.h>

int main(void){
    char c;
    printf("Inserisci un carattere: ");
    scanf("%c", &c);
    if (c >= '0' && c <= '9')
        printf("Il carattere inserito e' numerico\n");
    else if (c >= 'A' && c <= 'z')
        printf("Il carattere inserito e' alfabetico\n");
    else
        printf("Il carattere inserito e' speciale\n");

    return 0;
}