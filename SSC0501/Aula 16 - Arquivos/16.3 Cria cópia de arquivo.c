#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <strings.h>

int main(){
    setlocale(LC_ALL, "");

    char arq1[256];
    char arq2[256];

    FILE *arq_origem;
    FILE *arq_copia;

    printf("Qual o nome do arquivo que você deseja copiar?: ");
    fgets(arq1, 256, stdin);
    arq1[strlen(arq1)-1] = '\0';
    fflush(stdin);

    if((arq_origem = fopen(arq1, "r+")) == NULL){
        printf("\nErro abrindo arquivo.\n");
        exit(0);
    }

    printf("\n\nDigite agora o nome do arquivo cópia: ");
    fgets(arq2, 256, stdin);
    arq2[strlen(arq2)-1] = '\0';
    fflush(stdin);

    if((arq_copia = fopen(arq2, "w+")) == NULL){
        printf("\nErro abrindo arquivo.\n");
        exit(0);
    }

    CopiaArquivo(arq_origem, arq_copia);

    fclose(arq_origem);
    fclose(arq_copia);
    printf("\n\n");
    system("pause");
    return 0;
}

void CopiaArquivo(FILE *arq, FILE *arqCopy){

    int c; //caractere

    while((c = getc(arq)) != EOF){
        fprintf(arqCopy, "%c", c);

    }
}
