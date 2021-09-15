#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    char nome[30];
    float nota1;
    float nota2;

} aluno;

int main() {

    FILE *arq;
    float soma = 0;
    float media = 0;

    if ((arq = fopen("arquivo.txt", "w+")) == NULL) {
        printf("\nErro de abertura");
        exit(EXIT_FAILURE);
    }

    aluno a[10];

    for (int i = 0; i < 10; i++) {

        fgets(a[i].nome, 30, stdin);
        a[i].nome[strlen(a[i].nome) - 1] = '\0';
        scanf("%f", &a[i].nota1);
        scanf("%f", &a[i].nota2);
        setbuf(stdin,NULL);

        media = (a[i].nota1 + a[i].nota2) / 2;
        soma += media;
    }

    for (int i = 0; i < 10; i++) {
        fprintf(arq, "%s %f %f \n", a[i].nome, a[i].nota1, a[i].nota2);
    }

    fprintf(arq, "MT: %f 0", (float)soma / 10);

    fclose(arq); //Apagar se necess�rio
    return 0;
}
