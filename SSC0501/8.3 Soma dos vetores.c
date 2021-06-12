#include <stdio.h>
#include <stdlib.h>


int main(){

    int vetor1[5], vetor2[5];
    int i, soma = 0;

    for (i = 0; i < 5; i++){

        scanf("%d", &vetor1[i]);

    }

    for (i = 0; i < 5; i++){

        scanf("%d", &vetor2[i]);

    }

    for (i = 0; i < 5; i++){

        soma = vetor1[i] + vetor2[i];
        printf("%d ", soma);

        soma = 0;
    }

    return 0;
    system("pause");
}
