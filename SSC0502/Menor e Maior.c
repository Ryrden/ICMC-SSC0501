#include <stdio.h>
#include <stdlib.h>

int main(){

    int matriz[5][5];
    int linha, coluna;
    int menor, maior;

    scanf("%d", &matriz[5][5]);

    printf("%d", matriz[0][2]);


    menor = matriz[0][0];
    maior = matriz[0][0];

    for(linha = 0; linha < 5; linha++){ //Percorrendo Linha

        for(coluna = 0; coluna < 5; coluna++){ //Percorrendo Coluna


            if (matriz[linha][coluna] <= menor){

                menor = matriz[linha][coluna];
            }
            else if (matriz[linha][coluna] >= maior){

                maior = matriz[linha][coluna];
            }
        }
    }

    return 0;
    system("pause");
}
