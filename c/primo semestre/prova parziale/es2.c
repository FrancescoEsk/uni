#include <stdio.h>
#define N 10

int main(){ 
    int src[N];
    for(int i=0; i<N; i++){
        scanf("%i", &src[i]);
    }

    int temp, check;
    for(int i=0; i<N; i++){
        check = 0;
        if (src[i]%2 == 0){
            for(int k=0;k<N; k++){
                if (src[k]%2==1)
                    check = k;
            }
            temp = src[check];
            src[check] = src[i];
            src[i] = temp;
        } else if(i==9 && src[i]%2==1){
            for(int k=9; k>0 && !check; k--){
                if (src[k-1]%2 == 0){
                    temp = src[k-1];
                    src[k-1] = src[k];
                    src[k] = temp;
                } else {
                    check=1;
                }
            }
        }
    }
    
    for(int i=0; i<N; i++){
        printf("%d ", src[i]);
    }

    return(0); 
}
