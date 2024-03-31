#include <stdio.h>
#include <string.h>
#define DIM 50
/*
variante di es3.c in cui si copia il contenuto di str1 in str2 senza le vocali
*/

int main(void){
    char str1[DIM+1];
    char str2[DIM+1];
    scanf("%s", str1);
    int k=0;
    for(int i=0; i<DIM+1; i++){
        if(str1[i] == 'a' || str1[i] == 'e' || str1[i] == 'i' || str1[i] == 'o' || str1[i] == 'u' ||
        str1[i] == 'A' || str1[i] == 'E' || str1[i] == 'I' || str1[i] == 'O' || str1[i] == 'U' ){
            
        }else{
            str2[k] = str1[i];
            k++;
        }
    }
    printf("%s\n", str2);
    return 0;
}