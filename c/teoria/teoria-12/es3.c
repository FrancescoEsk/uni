#include <stdio.h>
#include <string.h>
#define DIM 50
/*
acquisisce una stringa str1 di massimo 50 caratteri e ne restituisce una nuova (str2)
copiando il contenuto di str1 e sostituendo le vocali con il carattere *
poi visualizzare str2
*/

int main(void){
    char str1[DIM+1];
    char str2[DIM+1];
    scanf("%s", str1);
    for(int i=0; i<DIM+1; i++){
        if(str1[i] == 'a' || str1[i] == 'e' || str1[i] == 'i' || str1[i] == 'o' || str1[i] == 'u' ||
        str1[i] == 'A' || str1[i] == 'E' || str1[i] == 'I' || str1[i] == 'O' || str1[i] == 'U' )
            str2[i] = '*';
        else
            str2[i] = str1[i];
    }
    printf("%s\n", str2);
    return 0;
}