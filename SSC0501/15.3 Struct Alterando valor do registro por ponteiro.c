#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct automoveis{
    int ano;
    float preco;
    char cor[10];
    char modelo[30];
    char fabricante[30];
};
void LeDados(struct automoveis *carro);
void ImprimeDados(struct automoveis carro);

int main(){

    struct automoveis carro1;

    LeDados(&carro1);

    AlteraRegistro(&carro1);

    ImprimeDados(carro1);

    return 0;
    system("pause");
}

void AlteraRegistro(struct automoveis *carro){

    if (carro->ano < 2000){

        carro->ano = 2000;
    }

    if (strcmp(carro->fabricante, "Chevrolet") == 0){

        strcpy(carro->fabricante, "GM");
    }

}

void LeDados(struct automoveis *carro){

    printf("Digite o ano do carro: ");
    scanf("%d", &carro->ano);
    fflush(stdin);

    printf("\nDigite o modelo do carro: ");
    fgets(carro->modelo, 30, stdin);
    fflush(stdin);

    printf("\nDigite a cor do carro: ");
    fgets(carro->cor, 10, stdin);
    fflush(stdin);

    printf("\nDigite o nome da fabricante desse carro: ");
    fgets(carro->fabricante, 30, stdin);
    fflush(stdin);

    printf("\nDigite o preco do carro: ");
    scanf("%f", &carro->preco);
    fflush(stdin);

}

void ImprimeDados(struct automoveis carro){

    printf("\nCarro: %d ", carro.ano);
    printf("\nModelo: %s ", carro.modelo);
    printf("\nCor: %s ", carro.cor);
    printf("\nFabricante: %s ", carro.fabricante);
    printf("\nPreco: R$ %.2f ", carro.preco);

}
