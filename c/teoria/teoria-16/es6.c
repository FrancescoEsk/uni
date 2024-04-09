#include <stdio.h>
#define DIM 50
/*
riproduco strlen in modo ricorsivo (strlenR)
*/

int strlen(char[DIM+1]);
int strlenR(char*);

int main(void){
    char c[DIM+1];
    scanf("%s", c);
    printf("%d e %d\n", strlen(c), strlenR(c));
    return 0;
}

int strlen(char s[DIM+1]){
    int l=0;
    while(s[l]!='\0'){
        l++;
    }
    return l;
}

int strlenR(char *s){
    if(*s == '\0') // caso base
        return 0;
    else // passo induttivo
        return 1+strlenR(s+1);
}