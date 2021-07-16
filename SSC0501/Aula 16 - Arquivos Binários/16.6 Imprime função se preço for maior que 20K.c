#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct automovel{

    char modelo[30];
    char cor[30];
    float preco;
};

int main(){
    setlocale(LC_ALL, "");

    struct automovel c[5]; //carros

    FILE *arq;

    if ((arq = fopen("16.5 Carros.txt", "ab+")) == NULL){
        printf("\nErro abrindo arquivo.\n");
        exit(0);
    }

    fread(c,sizeof(struct automovel), 5, arq);

    for(int i=0;i<5;i++){

        if (c[i].preco > 20000){
            printf("%s %s %f \n", c[i].modelo, c[i].cor, c[i].preco);
        }
    }

    printf("\n\n");
    system("pause");
 return;
}
