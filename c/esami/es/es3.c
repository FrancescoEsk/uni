#include<stdio.h>
#define M 3
#define N 3
int main(){
  int n, i, j;
	int m1[M][N];
	int trovata=0;
	
	
  // Acquisizione dati
  scanf("%d", &n);
  while(n<=0)
		scanf("%d", &n);
  for(i=0;i<M;i++){
    for(j=0;j<N;j++){
      scanf("%d",&m1[i][j]);
    }
  }

    int somma;
  for(int i=0; i<N; i++){
    for(int z=0; z<M; z++){
        somma = 0;
        if(i+n < N && z+n < M){
            for(int a=i; a<i+n && a<N; a++){
                for(int b=z; b<z+n && b<M; b++){
                    somma += m1[a][b];
                } 
            }
            if(somma == 0) trovata=1;
        }
    }
  }
	printf("%d",trovata);
	
}

/*
2
1 3 -3 5
4 2 -2 6
7 8 9 10

3
1 3 -3 5
4 2 -2 6
7 8 9 10

3
1 3 -3 5
-1 2 -2 6
0 0 0 10


3
1 3 -3 5
-1 2 -2 -5
5 0 0 0
*/