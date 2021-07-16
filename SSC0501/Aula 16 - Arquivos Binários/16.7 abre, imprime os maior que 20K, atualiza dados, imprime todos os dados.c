#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct automovel{

    char modelo[30];
    char cor[30];
    float preco;
};

void LeDados(struct automovel *c){ //Realiza leitura dos dados do funcionário

    printf("Digite o modelo do carro:");
    scanf("%[^\n]s", &c->modelo);
    fflush(stdin);

    printf("\nDigite a cor do carro:");
    scanf("%[^\n]s", &c->cor);
    fflush(stdin);

    printf("\nDigite o preço do carro:");
    scanf("%f", &c->preco);
    fflush(stdin);

}

int main(){
    setlocale(LC_ALL, "");

    struct automovel c[5]; //carros

    FILE *arq;

    if ((arq = fopen("16.5 Carros.txt", "ab+")) == NULL){
        printf("\nErro abrindo arquivo.\n");
        exit(0);
    }

    fread(c,sizeof(struct automovel), 5, arq);

    printf("Carros com preço maior que 20K: \n");
    for(int i=0;i<5;i++){

        if (c[i].preco > 20000){
            printf("%s %s %f \n", c[i].modelo, c[i].cor, c[i].preco);
        }
    }

    for(int i=0;i<5;i++){
        LeDados(c + i);
    }

    arq = fopen("16.5 Carros.txt", "w");
    fwrite(c, sizeof(struct automovel), 5, arq);

    printf("\n\n");
    system("pause");
 return;
}
