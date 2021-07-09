#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

int main(){
    setlocale(LC_ALL, "");
    SetConsoleOutputCP(65001);

    FILE *arq;
    char frase[256];

    if((arq = fopen("16.1 Texto escrito", "w+")) == NULL){
        printf("\nErro abrindo arquivo.\n");
    }

    printf("Digite a frase que deseja por no arquivo: \n\nFrase:  ");
    fgets(frase,256,stdin);
    fprintf(arq, "%s\n", frase);

    fclose(arq);

    printf("\n\n");
    system("pause");
 return;
}
