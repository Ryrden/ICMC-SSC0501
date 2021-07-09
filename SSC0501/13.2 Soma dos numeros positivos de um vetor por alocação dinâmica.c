#include <stdio.h>
#include <stdlib.h>

int *alocaVetor(int tamanho){

    int *vet;
    vet = (int *) malloc(tamanho * sizeof(int));

    for(int i=0; i < tamanho;i++){
        scanf("%d", &vet[i]);
    }
    return(vet);
}

int SomaDosPositivos(int *vet, int tam) {

    int soma=0;

    for(int i=0; i < tam;i++){
        if (vet[i] > 0){
            soma+= vet[i];
        }
    }

    return(soma);
}

int main(){

    int *vet, tam;

    printf("Qual o tamanho do vetor? ");
    scanf("%d", &tam);

    vet = alocaVetor(tam);

    printf("%d", SomaDosPositivos(vet, tam));

    free(vet);

    return 0;
    system("pause");
}
