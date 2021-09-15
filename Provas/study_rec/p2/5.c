#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[20];
    int avaliacao;
    int ano;
} filmes;

int main() {

    FILE *arq;

    if ((arq = fopen("filmes.dat", "rb")) == NULL) {
        printf("Erro de abertura\n");
        exit(0);
    }

    char P[256];
    scanf("%s", P);

    filmes f[5];
    fread(&f, sizeof(filmes), 5, arq);
    char *pont;
    for (int i = 0; i < 5; i++) {
        if (f[i].ano >= 2000 && (pont = strstr(f[i].nome, P))) {
            printf("%s\n", f[i].nome);
        }
    }

    return 0;
}
