#include <stdio.h>
int coppiei(int);


int main(){
	int a,r;
	
	do{
		scanf("%d",&a);
	}while(a<0);
	
	r=coppiei(a);
	
	printf("%d",r);
	
	return 0;
}

int coppiei (int a){
    int x = a, count=0, ris=0, old;
    while (x>0){
        x /= 10;
        count++;
    }
    old = a%10;
    a /= 10;
    for (int i=0; i<count; i++){
        if ( old == a%10)
            ris++;
        old = a%10;
        a /= 10;
    }
    return ris;
}
