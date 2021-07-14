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

    if ((arq = fopen("16.5 Carros.txt", "wb+")) == NULL){
        printf("\nErro abrindo arquivo.\n");
        exit(0);
    }

    fwrite(&c, sizeof(struct automovel), 5, arq);

    fseek(arq,0,SEEK_SET);
    fread(c, sizeof(struct automovel), 1, arq);

    printf("\n\n");
    system("pause");
 return 0;
}
