#include <stdio.h>
#include <stdlib.h>


int main(){

    int vetor[10];
    int soma = 0;

    for (int cont = 0; cont < 10; cont++){

        scanf("%d", &vetor[cont]);

    }


    for (int i=0; i < 10; i++){

        if (i % 2 != 0){

            soma = soma + vetor[i];
        }
    }

    printf("%d", soma);

    return 0;
    system("pause");
}
