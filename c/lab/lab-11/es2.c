#include <stdio.h>
#include <string.h>
#define DIM 100
/*
Scrivere un programma C che si comporta
come il programma precedente, ma accetta in input una
stringa (quindi non si ferma al primo spazio).
*/

int main(void){
    char str1[DIM+1];
    gets(str1);
    int l = strlen(str1), vocali=0, consonanti=0;
    printf("%i\n", l);
    for (int i=0; i<l; i++){
        if(str1[i] == 'a' || str1[i] == 'e' || str1[i] == 'i' || str1[i] == 'o' || str1[i] == 'u' ||
        str1[i] == 'A' || str1[i] == 'E' || str1[i] == 'I' || str1[i] == 'O' || str1[i] == 'U' ){
            vocali++;
        } else {
            consonanti++;
        }
    }
    printf("len: %i, vocali: %i, consonanti: %i\n", l, vocali, consonanti);
    return 0;
}