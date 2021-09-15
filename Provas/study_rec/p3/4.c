#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    FILE *arq1, *arq2;

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
                printf("%s ", palavra1);
                //break;
            }
        }
    }
    /*
    bla bla casa bla gato cao cao casa bla bla
    casa ble ble gato cao casa gato gato ble ble bli
    */
    fclose(arq1);
    fclose(arq2);
    return 0;
}
