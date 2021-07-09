#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <strings.h>

int main(){
    setlocale(LC_ALL, "");

    char palavra[256];

    FILE *arq;
    arq = fopen("TEXTO APOIO.txt", "r");

    if(arq == NULL){
        printf("\nErro abrindo arquivo.\n");
    }

    printf("Digite a palavra que deseja buscar:\n\n    Palavra:   ");
    fgets(palavra, 256, stdin);
    palavra[strlen(palavra)-1] = '\0';
    fflush(stdin);

    int x = BuscaPalavraEmArquivo(palavra, arq);

    if (x==1){printf("A palavra %s, pertence ao arquivo", palavra);}
    else{printf("A palavra %s, não pertence ao arquivo", palavra);}

    fclose(arq);
    printf("\n\n");
    system("pause");
 return 0;

}

int BuscaPalavraEmArquivo(char *palavra, FILE *arq){ // retorna 1 se encontrar e 0 se não encontrar a palavra

    int c; //caractere
    int pertence, cont;

    while((c = getc(arq)) != EOF){

        if (palavra[0] == c){
            cont = 0;
            pertence = 1;

            while((c = getc(arq)) != ' '){

                cont++;
                if (palavra[cont] != c){
                    pertence = 0;
                }
            }
            if (pertence == 1)break;
        }
    }

    return pertence;
}
