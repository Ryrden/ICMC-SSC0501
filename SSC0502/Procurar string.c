#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ProcuraString(FILE *arq, char *palavra);

int main(){

    FILE *arq;
    char palavra[256];
    int cont;

    if ((arq = fopen("arquivo2.txt", "r+")) == NULL){
        printf("\nErro abrindo arquivo.\n");
        exit(0);
    }

    scanf("%[^\n]s", palavra);
    fflush(stdin);

    cont = ProcuraString(arq, palavra);

    printf("%d", cont);

    fclose(arq);
    return 0;
}

int ProcuraString(FILE *arq, char *palavra){

    int c;
    int cont=0;
    char palavra2[256];

    while((c = fgetc(arq)) != EOF){

        if (palavra[0] == c){
            fseek(arq, -1, SEEK_CUR); //volta uma caractere para o scanf ler a palavra toda
            fscanf(arq, "%s", palavra2);

            for(int i=0; i <strlen(palavra2);i++){
                int igual = 1;

                for(int j=i; palavra[j] != palavra[strlen(palavra)];j++){

                    if (palavra[j] != palavra2[j]){
                    igual = 0;
                    break;
                    }
                }

                if (igual == 1){
                    cont++;
                }
                break;
            }
        }
    }

    return cont;
}
