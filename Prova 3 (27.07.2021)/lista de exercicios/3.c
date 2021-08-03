#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct aluno{

    char nome[30];
    float nota1;
    float nota2;

};

int main(){
    setlocale(LC_ALL, "");

    FILE *arq;
    float soma=0;
    float media=0;

    if((arq=fopen("arquivo.txt", "w+")) == NULL){
        printf("\nErro de abertura");
        exit(0);
    }

    struct aluno a[10];

    for(int i=0;i<10;i++){

        scanf("%[^\n]", a[i].nome);
        fflush(stdin);
        scanf("%f", &a[i].nota1);
        fflush(stdin);
        scanf("%f", &a[i].nota2);
        fflush(stdin);
        media = (a[i].nota1+a[i].nota2)/2;
        soma += media;
        
    }

    for(int i=0;i<10;i++){

        fprintf(arq, "%s ", a[i].nome);
        fprintf(arq, "%f ", a[i].nota1);
        fprintf(arq, "%f \n", a[i].nota2);
    }

        fprintf(arq, "\n\nMEDIA TOTAL: %f", (float)soma/10);


    fclose(arq); //Apagar se necess�rio
    printf("\n\n");
    system("pause");
    return 0;
}
