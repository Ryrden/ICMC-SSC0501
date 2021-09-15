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
    char str[20];
    char final[50];
    int i = 0;
    aluno a[11];

    if ((arq = fopen("arquivo.txt", "r")) == NULL) {
        printf("\nErro de abertura");
        exit(0);
    }

    while (!feof(arq)) { //NAO FUNCIONA
        fscanf(arq, "%s", a[i].nome);
        fscanf(arq, "%f", &a[i].nota1);
        fscanf(arq, "%f", &a[i].nota2);
        i++;
    }
    /*char temp[256];
    while (feof(arq) != EOF) { //FUNCIONA
        fscanf(arq,"%s", temp);
        strcpy(a[i].nome,temp);
        fscanf(arq,"%s", temp);
        a[i].nota1 = atof(temp);
        fscanf(arq,"%s", temp);
        a[i].nota2 = atof(temp);

        i++;
    }*/
    for (int i = 0; i < 11; i++) { //NÃO PRINTA NADA!
        printf("%s %f %f \n", a[i].nome, a[i].nota1, a[i].nota2);
    }

    fclose(arq);
    return 0;
}
