#include <stdio.h>
#include <string.h>

char checkCapital(char *,int);

int main(void) 
{
    int i = 0;
    char c,singLet;
    char s[50];
    
    scanf("%c", &c);

    while (c != '\n') {
        s[i] = c;
        scanf("%c", &c);
        i++;
    }
    s[i] = '\0';
    singLet = checkCapital(s,0);
    if (singLet == 0)
    {
        printf(" Non ci sono lettere maiuscole in :  %s.\n", s);
    }
    else
    {
        printf(" La prima lettera maiuscola in %s è %c.\n", s, singLet);    
        return 0;
    }
  return 0; 
}

char checkCapital(char *stringa, int i)
{   
    if(*(stringa+i) == '\0')
        return 0;
    if(*(stringa+i) >= 'A' && *(stringa+i) <= 'Z')
        return *(stringa);
    else
        return checkCapital(stringa+1, i);
    //TODO
}