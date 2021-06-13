#include <stdio.h>
#include <stdlib.h>


int main(){

    int matriz[4][5], vetor[5];
    int lin, col;
    int coluna_fixa = 0;
    int soma = 0;

    for (lin = 0; lin < 4; lin++){

        for (col = 0; col < 5; col++){

            scanf("%d", &matriz[lin][col]);
        }
    }

    for (col = 0; col < 5; col++){

        for(lin = 0; lin < 4; lin++){

        soma = soma + matriz[lin][coluna_fixa];

        }

        vetor[col] = soma;

        soma = 0;

        coluna_fixa++;

    }

    for(int i = 0; i < 5; i++){

        printf("%d ", vetor[i]);
    }

    return 0;
    system("pause");
}
