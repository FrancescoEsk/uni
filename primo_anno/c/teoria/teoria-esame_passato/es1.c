#include<stdio.h>

/*
Scrivere un programma che riceve in ingresso:
- la dimensione n di una matrice (es: 6)
- la dimensione d della forma geometrica da disegnare (es: 3)
- un numero type compreso tra 0 e 2 inclusi (es: 1)

Il programma ritorna in uscita:

Se type=0: una matrice di zeri (0) con disegnato, a partire dalla cella (n-2,1), 
un quadrato di uni (1) di dimensione dxd

Se type=1: una matrice di zeri (0) con disegnato, a partire dalla cella (n-2,1), 
un trianagolo rettangolo di uni (1) con cateti di dimensione d e angolo retto nella cella (n-2,1)

Se type=2: una matrice di zeri (0) con disegnati, a partire dall'angolo in alto a sinistra (i.e., (0,0)),
 dei quadrati di dimensione dxd parzialmente sovrapposti fino a raggiungere l'angolo 
 in basso a destra (i.e., (n-1,n-1)), dove il quadrato i-esimo e' spostato in basso ed a destra 
 di i celle e contiene nelle sue celle il numero i:
*/

int main(){
  int n, d, type, i, j, count;

  // Acquisizione dati
  scanf("%d", &n);
  
  int m1[n][n];
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      m1[i][j]=0;
    }
  }
  
  scanf("%d", &d);
  scanf("%d", &type);
  
  switch (type)
  {
    case 0: 
        for(int i=n-1-d; i<=(n-2); i++){
            for(int z=1; z<d+1; z++){
                m1[i][z] = 1;
            }
        }
    break;

    
    case 1:
        count=d-1;
        for(int i=n-1-d; i<=(n-2); i++){
            for(int z=1; z<d+1-count; z++){
                m1[i][z] = 1;
            }
            count--;
        }
    break;

    case 2:
        for(int a=0; a<=n-d; a++){
            for(int i=a; i<a+d; i++){
                for(int z=a; z<a+d; z++){
                    m1[i][z] = a+1;
                }
            }
        }
    break;
  }

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf("%d ", m1[i][j]);
    }
    printf("\n");
  }
 
}