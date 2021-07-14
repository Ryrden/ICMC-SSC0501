#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ContaPalavra(FILE *arq, char *palavra);

int main(){

    FILE *arq;
    char palavra[256];
    int cont;

    if ((arq = fopen("arquivo.txt", "r+")) == NULL){
        printf("\nErro abrindo arquivo.\n");
        exit(0);
    }

    scanf("%[^\n]s", palavra);
    fflush(stdin);

    cont = ContaPalavra(arq, palavra);

    printf("%d", cont);

    fclose(arq);
    return 0;
}

int ContaPalavra(FILE *arq, char *palavra){

    int cont = 0;
    char s[256];

    while(feof(arq) == 0){

        fscanf(arq, "%s", s);

        if(strcmp(palavra, s) == 0){
            cont++;
        }
    }

    return cont;
}
