#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Crie uma função que receba como parâmetro uma matriz de inteiros 5x5, e 
retorne a lista (um vetor) dos inteiros que aparecem pelo menos 3 vezes nessa 
matriz. Criar também o programa que executa a função e imprime o resultado.
*/

int *solve(int matriz[5][5], int *TamResposta) {
    int *valores;

    valores = (int *)calloc(sizeof(int), 10000); //limitei a entrada de elementos (da matrix) do usuário para o valor 10000

    int cont = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            valores[matriz[i][j]] += 1;
            if (valores[matriz[i][j]] == 3) {
                cont++;
            }
        }
    }
    *TamResposta = cont;

    int *final = (int *)calloc(sizeof(int), cont);

    cont = 0;
    for (int i = 0; i < 1000; i++) {
        if (valores[i] >= 3) {
            final[cont] = i;
            cont++;
        }
    }

    free(valores);
    return final;
}

void ImprimeMatrix(int *resposta, int tamresposta) {
    for (int i = 0; i < tamresposta; i++) {
        printf("%d ", resposta[i]);
    }
}

int main() {

    int *resposta;
    int matrix[5][5];

    /*Teste utilizado
    int matrix[5][5] = {{1, 2, 3, 4, 5}, {1, 1, 1, 2, 2}, {1, 2, 3, 4, 5}, {1, 1, 3, 2, 2}, {15, 20, 5, 26, 30}};
    */

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &matrix[i][j]);
            setbuf(stdin, NULL);
        }
    }

    int tamresposta;
    resposta = solve(matrix, &tamresposta);

    ImprimeMatrix(resposta, tamresposta);

    free(resposta);
    return 0;
}
