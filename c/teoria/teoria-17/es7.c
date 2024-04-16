#include <stdio.h>
/*
legge due elenchi ordinati di numeri    fa, fb
e scrive un unico elenco ordinato       fc
*/

int main(void){
    FILE *fa, *fb, *fc;
    
    if( (fa = fopen("elencoa.txt", "r")) ){
        if ( (fb = fopen("elencob.txt", "r")) ){
            if ( (fc = fopen("risultato.txt", "w")) ){
                int a, b;
                fscanf(fa, "%d", &a);
                fscanf(fb, "%d", &b);
                while(!feof(fa) && !feof(fb)){
                    if (a == b){
                        fprintf(fc, "%d\n", a);
                        fscanf(fa, "%d", &a);
                        fprintf(fc, "%d\n", b);
                        fscanf(fb, "%d", &b);
                    } else if (a < b){
                        fprintf(fc, "%d\n", a);
                        fscanf(fa, "%d", &a);
                    } else if (b < a){
                        fprintf(fc, "%d\n", b);
                        fscanf(fb, "%d", &b);
                    }
                }
                while(!feof(fa)){
                    fprintf(fc, "%d\n", a);
                    fscanf(fa, "%d", &a);
                }
                while(!feof(fb)){
                    fprintf(fc, "%d\n", b);
                    fscanf(fb, "%d", &b);
                }

                fclose(fa);
                fclose(fb);
                fclose(fc);  
            }
        }
    } else {
        printf("Errore\n");
    }
    return 0;
}