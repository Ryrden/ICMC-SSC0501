#include <stdio.h>
#include <stdlib.h>

int main(){

    int matriz[5][5];
    int linha, coluna;
    int menor, maior;

    for (linha = 0; linha < 5; linha++){

        for (coluna = 0; coluna < 5; coluna++){

            scanf("%d", &matriz[linha][coluna]);
        }
    }

    menor = matriz[0][0];
    maior = matriz[0][0];

    for(linha = 0; linha < 5; linha++){ //Percorrendo Linha

        for(coluna = 0; coluna < 5; coluna++){ //Percorrendo Coluna

            if (matriz[linha][coluna] <= menor){

                menor = matriz[linha][coluna];
            }

            if (matriz[linha][coluna] >= maior){

                maior = matriz[linha][coluna];
            }
        }
    }

    printf("%d %d", menor, maior);

    return 0;
    system("pause");
}
