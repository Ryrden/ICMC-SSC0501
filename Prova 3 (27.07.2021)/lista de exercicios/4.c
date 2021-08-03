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
    char str[20];
    int i=0;
    struct aluno a[10];

    if((arq=fopen("arquivo.txt", "r")) == NULL){
        printf("\nErro de abertura");
        exit(0);
    }
    fseek(arq,0,SEEK_SET);
    while(!feof(arq)){


        fgets(a[i].nome,30,arq);
        printf("%s ", a[i].nome);
        fgets(a[i].nota1,1,arq);

        fseek(arq,2,SEEK_CUR);
        fscanf(arq, "%f", a[i].nota1);
        printf("%f ", a[i].nota1);
        fscanf(arq, "%f", a[i].nota2);
        i++;
    }

    for(int i=0;i<10;i++){
        printf("%s ", a[i].nome);
        printf("%f ", a[i].nota1);
        printf("%f \n", a[i].nota2);
    }

    fclose(arq); //Apagar se necessário
    printf("\n\n");
    system("pause");
    return 0;
}
