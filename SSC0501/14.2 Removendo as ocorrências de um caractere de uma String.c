#include <stdio.h>
#include <stdlib.h>

void RemoveCaractere(char *palavra, char caractere){

    int i, cont;

    for(i=0; i < (strlen(palavra)); i++){

        if (palavra[i] == caractere){

            for(cont = i; cont < strlen(palavra); cont++){
                palavra[cont] = palavra[cont+1];
            }
            i--;
        }
    }
}

int main(){

    char palavra[255];
    char caractere[2];
    printf("Digite a palavra ou frase que seja manipular: ");
    gets(palavra);

    palavra[strlen(palavra)] = '\0';

    printf("Digite o caractere que deseja remover: ");
    scanf("%s", &caractere);

    RemoveCaractere(&palavra, caractere[0]);

    printf("%s", palavra);

    printf("\n\n");
    return 0;
    system("pause");
}
