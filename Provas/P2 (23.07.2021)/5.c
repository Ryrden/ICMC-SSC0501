#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Eu não sei como realizar a busca, não foi disponibilizado um arquivo texto

struct filme {

    char nome[20];
    int avaliacao;
    int ano;
};

int main(){
    setlocale(LC_ALL, "");

    FILE *arq;
    char palavra[256];

    if ((arq = fopen("filmes.dat", "r+")) == NULL){
        printf("Erro de abertura");
        return 0;
    }

    scanf("%[^\n]s", palavra);
    fflush(stdin);

    //a partir daqui eu vou supor que é struct do exercicio anterior

    struct filme f[5];

    //Supondo que neste arquivo tenha o vetor A em binario (a unica coisa que não foi cobrada)do exercicio anterior a partir do SEEK_SET
    fread(&f,sizeof(struct filme),5,arq);
    for(int i=0; i<5;i++){

        if(f[i].ano >= 2000){
            printf("Titulo: %s\n", palavra);
            printf("Ano: %d\n\n", f[i].ano);
        }
    }


    printf("\n\n");
    return 0;
}

