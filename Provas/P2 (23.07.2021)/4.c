#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct filme {

    char nome[20];
    int avaliacao;
    int ano;
};

void leDados(struct filme *f){


    for(int i=0;i<5;i++){

    scanf("%[^\n]s", f[i].nome);
    fflush(stdin);

    scanf("%d", &f[i].avaliacao);
    fflush(stdin);
    scanf("%d", &f[i].ano);
    fflush(stdin);
    }

}

void CopiaDados(struct filme *f1, struct filme *f2,int *vezes){

    int cont=0;

    for(int i=0;i<5;i++){

        if (f1[i].ano >= 2000){
            *f2[cont].nome = *f1[i].nome;
            f2[cont].avaliacao = f1[i].avaliacao;
            f2[cont].ano = f1[i].ano;
            cont++;
        }

    }

    *vezes = cont;

}

int main(){
    setlocale(LC_ALL, "");

    struct filme f1[5]; //vetor A
    struct filme f2[5]; //vetor B
    int cont = 0;

    leDados(f1);

    CopiaDados(f1,f2,&cont);

    for(int i =0; i < cont; i++){

        printf("%s \n", f2[i].nome);

    }

    printf("\n\n");

 return 0;
}
