#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Funciona mas no RunCodes est� incompleto

int ContaPalavra();

int main() {
    setlocale(LC_ALL, "");

    FILE *arq;
    char palavra1[256];
    char palavra2[256];
    int vezes;
    char s[256];

    if ((arq = fopen("texto.txt", "r+")) == NULL) {
        printf("Erro de abertura");
        return 0;
    }

    scanf("%[^\n]s", palavra1);
    fflush(stdin);
    scanf("%[^\n]s", palavra2);
    fflush(stdin);

    while (fscanf(arq, "%s", s) == 1) {

        char r[256];

        if (strcmp(s, palavra1) == 0) {
            fseek(arq, strlen(palavra1) - 1, SEEK_CUR);
            fscanf(arq, "%s", r);

            if (strcmp(r, palavra2) == 0) {
                vezes++;
            } else {
                fseek(arq, strlen(palavra2) - 1, SEEK_CUR);
            }
        }
    }

    printf("%d", vezes);

    fclose(arq);
    printf("\n\n");
    return 0;
}
