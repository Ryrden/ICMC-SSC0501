#include <stdio.h>
#include <stdlib.h>

int main (){

    FILE *arq;
    int i, n;

    if((arq=fopen("TEXTO APOIO", "r"))==NULL){
        printf("\nErro abrindo arquivo.\n");
    }

    for(i=0; i<5; i++) {
        fscanf(arq, "%d", &n);
        printf("%d\n", n);
        }

    fclose(arq);
    system("PAUSE");
    return 0;
}
