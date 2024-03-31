#include <stdio.h>
#define DIM 10

/*
implementiamo le funzioni di <string.h> a mano
*/

int main(void){ 

    return 0;
}

int strlen(char str[DIM+1]){
    int len = 0;
    for (int i=0; i<DIM+1 && str[i]!='\0'; i++)
        len++;
    return len;
}

int strcmp(char str1[DIM+1], char str2[DIM+1]){
    int b = 1;
    for (int i=0; i<DIM+1 && b==1; i++){
        if(str1[i]!=str2[i])
            b=0;
    }
    return b;
}

void strcpy(char str1[DIM+1], char str2[DIM+1]){
    for(int i=0; i<DIM+1 && str1[i]!='\0'; i++){
        str2[i] = str1[i];
    }
    // return str2;
}

void strcut(char str1[DIM+1], char str2[DIM+1]){
    char r[(DIM*2)+1];
    int i;
    for(int i=0; i<DIM && str1[i]!='\0'; i++){
        r[i] = str1[i];
    }
    for(int j=0; j<DIM && str1[i]!='\0'; j++){
        r[i] = str2[j];
        i++;
    }
    r[i] = '\0';
    // return r;
}