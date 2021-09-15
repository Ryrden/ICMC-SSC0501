#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { //utilizei o typedef, espero que não seja problema :)
    char nome[50];
    char editor[50];
    int estoque;
    float preco;
} livros;

void Ordena(livros *vetor, int n) {
    int k, j, aux = 0;
    char auxString[50];
    float auxPreco = 0;

    for (k = 1; k < n; k++) {
        for (j = 0; j < n - 1; j++) {
            if (vetor[j].preco > vetor[j + 1].preco) {
                auxPreco = vetor[j].preco;
                vetor[j].preco = vetor[j + 1].preco;
                vetor[j + 1].preco = auxPreco;

                strcpy(auxString, vetor[j].nome);
                strcpy(vetor[j].nome, vetor[j + 1].nome);
                strcpy(vetor[j + 1].nome, auxString);

                strcpy(auxString, vetor[j].editor);
                strcpy(vetor[j].editor, vetor[j + 1].editor);
                strcpy(vetor[j + 1].editor, auxString);

                aux = vetor[j].estoque;
                vetor[j].estoque = vetor[j + 1].estoque;
                vetor[j + 1].estoque = aux;
            }
        }
    }
}

int main() {

    FILE *arq;
    int N;

    scanf("%d", &N);
    livros livro[N];

    if ((arq = fopen("arq1.txt", "rb")) == NULL) {
        printf("\nErro de abertura");
        exit(EXIT_FAILURE);
    }
    fread(&livro, sizeof(livros), N, arq);

    Ordena(livro, N);

    fclose(arq);
    if ((arq = fopen("arq1.txt", "wb+")) == NULL) {
        printf("\nErro de abertura");
        exit(EXIT_FAILURE);
    }

    fwrite(livro, sizeof(livros), N, arq);

    fclose(arq);
    return 0;
}
