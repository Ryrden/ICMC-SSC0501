#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "");

    FILE *arq;
    int vet[5];

    if ((arq = fopen("16.4 arquivo.txt", "wb+")) == NULL){
        printf("\nErro abrindo arquivo.\n");
        exit(0);
    }

    for(int i=0;i<5;i++){
        scanf("%d", &vet[i]);
    }

    fwrite(vet, sizeof(int), 5, arq);

    fclose(arq);
    printf("\n\n");
    system("pause");
 return;
}
