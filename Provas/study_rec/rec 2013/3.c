#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int matrix[4][5];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int j = 0; j < 5; j++) {
        int soma = 0;
        for (int i = 0; i < 4; i++) {
            soma += matrix[i][j];
        }
        printf("%d ", soma);
    }

    return 0;
}
