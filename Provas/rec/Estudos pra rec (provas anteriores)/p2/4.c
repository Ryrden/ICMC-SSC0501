#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[20];
    int avaliacao;
    int ano;
} filme;

int copiaDados(filme *vetA, filme *vetB) {

    int cont = 0;
    for (int i = 0; i < 5; i++) {
        if (vetA[i].ano >= 2000) {
            strcpy(vetB[cont].nome, vetA[i].nome);
            vetB[cont].avaliacao = vetA[i].avaliacao;
            vetB[cont].ano = vetA[i].ano;
            cont++;
        }
    }

    return cont;
}

int main() {

    filme vetA[5], vetB[5];

    for (int i = 0; i < 5; i++) {
        fgets(vetA[i].nome, 20, stdin);
        vetA[i].nome[strlen(vetA[i].nome) - 1] = '\0';
        scanf("%d", &vetA[i].avaliacao);
        scanf("%d", &vetA[i].ano);
        setbuf(stdin, NULL);
    }
    int tam = copiaDados(vetA, vetB);

    for (int i = 0; i < tam; i++) {
        printf("%s\n", vetB[i].nome);
    }

    return 0;
}
