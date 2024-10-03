#include <stdio.h>
#define DIM 50
/*
stringhe palindrome
*/

int palindromo(char*, char*);
int strln(char[DIM+1]);

int main(void){
    char c[DIM+1];
    scanf("%s", c);

    printf("%d\n", palindromo(c, &c[strln(c)-1]));

    return 0;
}

int strln(char s[DIM+1]){
    int l=0;
    while(s[l]!='\0'){
        l++;
    }
    return l;
}

int palindromo(char *s, char *dim){
    if (s>=dim)
        return 1;
    else if(*s == *dim)
        return palindromo(s+1, dim-1);
    else
        return 0;
}