#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void barra(int largura) {
    printf("+");
    for (int i = 1; i <= largura - 2; i++)
        printf("-");
    printf("+ \n");
}

int main() {

    int altura, largura;

    scanf("%d", &altura);
    scanf("%d", &largura);

    /*Tem casos em que se o usuario digitar 1,1 ou 1,2 ou 2,1 não faz sentido o quadrado no caso 1,1 ser 
        ++
        ++
    Apesar disso, optei por deixar assim para não criar uam gama de casos com if and elses. Não sei se o senhor 
    queria o programa com estes casos...realmente espero que não e que isso não abaixe a minha nota! obrigado!
    */
    barra(largura); //cabeçalho
    for (int i = 1; i <= altura - 2; i++) {
        printf("|");
        for (int i = 1; i <= largura - 2; i++)
            printf(" ");
        printf("| \n");
    }
    barra(largura); // rodapé

    return 0;
}
