#include <stdio.h>
#include <stdlib.h>

struct automoveis{

    int ano;
    float preco;
    char cor[10];
    char modelo[30];
    char fabricante[30];
};

int main(){

    struct automoveis carro1;

    printf("Digite o ano do carro: ");
    scanf("%d", &carro1.ano);
    fflush(stdin);

    printf("\nDigite o modelo do carro: ");
    gets(carro1.modelo);
    fflush(stdin);

    printf("\nDigite a cor do carro: ");
    gets(carro1.cor);
    fflush(stdin);

    printf("\nDigite o nome da fabricante desse carro: ");
    gets(carro1.fabricante);
    fflush(stdin);

    printf("\nDigite o preco do carro: ");
    scanf("%f", &carro1.preco);
    fflush(stdin);

    printf("\nCarro: %d ", carro1.ano);
    printf("\nModelo: %s ", carro1.modelo);
    printf("\nCor: %s ", carro1.cor);
    printf("\nFabricante: %s ", carro1.fabricante);
    printf("\nPreco: R$ %.2f ", carro1.preco);




    return 0;
    system("pause");
}
