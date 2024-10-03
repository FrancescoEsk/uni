#include <stdio.h> 
#define MAXD 4

/*
Scrivere un programma che chiede all’utente di riempire
una matrice quadrata 4x4 di caratteri (qualsiasi valore
char). Il programma individua il carattere che compare
più frequentemente e lo mostra a schermo (si ipotizzi che
sia sempre unico). Inoltre il programma visualizza il
contenuto della matrice, mostrando però un asterisco al
posto dei caratteri uguali a quello individuato.
*/

int main (void) 
{
 char matr[MAXD][MAXD];
 char maxc;
 char temp;
 int count=0, countT, i, j, k, h;
// TODO
 for(i=0; i<MAXD; i++) { 
 	for(j=0; j<MAXD; j++) {
		scanf(" %c", &matr[i][j]);
	}
}
	
 for(i=0; i<MAXD; i++) { 
 	for(j=0; j<MAXD; j++) {
		countT=0;
		temp = matr[i][j];
		for(k=0; k<MAXD; k++) { 
         	for(h=0; h<MAXD; h++) {
        		if (matr[k][h] == temp) countT++;
        	}
		}
		if (countT > count){
		    count = countT;
		    maxc = temp;
		}
	}
}

printf("MAX: %c\n", maxc);

// visualizzo matrice
 for(i=0; i<MAXD; i++) { 
 	for(j=0; j<MAXD; j++) {
		if(matr[i][j]!= maxc)
			printf("%c", matr[i][j]);
		else printf("*");
	}
	printf("\n");
	
 }
 return 0;
}
