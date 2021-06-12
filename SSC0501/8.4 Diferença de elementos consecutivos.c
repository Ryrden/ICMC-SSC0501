#include <stdio.h>
#include <stdlib.h>


int main(){

    int vetor[10];
    int i, resto = 0;

    for (i = 0; i < 10; i++){

        scanf("%d", &vetor[i]);

        if (vetor[i] - vetor[i-1] >= resto){

            resto = vetor[i] - vetor[i-1];
        }
    }

    printf("%d", resto);


    return 0;
    system("pause");
}
