#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

void numero_de_palavras(char *palavra, int *num_palavras){

    for(int i=0; i < (strlen(palavra)); i++){

        if (palavra[i] == ' ' && palavra[i+1] != ' '){
            *num_palavras)++;
        }
    }

}

int main(){

    char palavra[255];
    int *num_palavras = 1;

    gets(palavra);

    palavra[strlen(palavra)] = '\0';

    numero_de_palavras(&palavra, &num_palavras);

    printf("A frase que voce digitou tem %d palavras.", num_palavras);

    return 0;
    system("pause");
}
