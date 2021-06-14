#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main(){
    setlocale(LC_ALL, "");

    int lin, col;
    int i,j;

    printf("Digite o número de linhas que sua matriz deverá ter: ");
    scanf("%d", &lin);

    printf("Digite o número de colunas que sua matriz deverá ter: ");
    scanf("%d", &col);

    int matriz[lin][col];


    for (i = 0; i < lin; i++){

        for(j = 0; j < col; j++){

            matriz[i][j] = i*j;

        }
    }

    for (i = 0; i < lin; i++){

        for(j = 0; j < col; j++){

            printf("[%d] ", matriz[i][j]);

        }
        printf("\n");
    }


    return 0;
    system("pause");
}
