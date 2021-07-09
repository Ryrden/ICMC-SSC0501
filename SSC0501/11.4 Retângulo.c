#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void barra(largura){

    printf("+");

    for(int i = 0; i < (largura-2); i++){

        printf("-");
    }
    printf("+\n");

}

void vazio(largura){

    for (int i = 0; i < (largura-2);i++){

        printf(" ");
    }

}

int main(){
 setlocale(LC_ALL, "");

    int altura, largura;

    printf("Qual a altura? ");
    scanf("%d", &altura);

    printf("Qual a largura? ");
    scanf("%d", &largura);


    barra(largura);

    for(int i = 1; i <= altura; i++){

        printf("|");
        vazio(largura);
        printf("|\n");

    }

    barra(largura);

    printf("A Área deste retângulo é de %d m²", (altura*largura));



 printf("\n\n");
 system("pause");
 return;
}
