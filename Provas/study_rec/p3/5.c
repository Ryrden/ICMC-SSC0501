#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    FILE *arq1, *arq2;
    char vetorPalavras[256][100];
    int cont = 0;

    if ((arq1 = fopen("arq1.txt", "r")) == NULL) {
        printf("DEU RUIM!!\n");
        exit(0);
    }
    if ((arq2 = fopen("arq2.txt", "r")) == NULL) {
        printf("DEU RUIM!!\n");
        exit(0);
    }

    char palavra1[256];
    while (fscanf(arq1, "%s", palavra1) == 1) {
        char palavra2[256];
        fseek(arq2, 0, SEEK_SET);
        while (fscanf(arq2, "%s", palavra2) == 1) {
            if (strcmp(palavra1, palavra2) == 0) {
                int flag = 1;
                for (int i = 0; i <= cont; i++) {
                    if (strcmp(palavra1, vetorPalavras[i]) == 0) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    printf("%s ", palavra1);
                }
                strcpy(vetorPalavras[cont], palavra1);
                cont++;
            }
        }
    }

    fclose(arq1);
    fclose(arq2);
    return 0;
}
