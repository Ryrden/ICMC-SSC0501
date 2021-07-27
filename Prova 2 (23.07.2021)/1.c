#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Deu certo aqui, no RunCodes não sai nada

int *ContaDiferente(int vet1[10], int x, int *N){

    int *vet2;
    int tam;
    int cont=0;

    for(int i=0; i < 10;i++){
        if (vet1[i] != x){
            tam++;
        }
    }

    vet2 = (int *) malloc(tam * sizeof(int));
    for(int i=0; i < 10;i++){
        if(vet1[i] != x){
            vet2[cont] = vet1[i];
            cont++;
        }
    }
    *N = tam;

    return(vet2);
}


int main(){
    setlocale(LC_ALL, "");

    int vet1[10];
    int *vet02;
    int x;
    int N;

    for(int i=0;i<10;i++){
        scanf("%d", &vet1[i]);
    }

    scanf("%d", &x);

    vet02 = ContaDiferente(vet1,x, &N);

    for(int i=0;i<N;i++){
        printf("%d ", vet02[i]);
    }

    printf("\n\n");
    system("pause");
    return 0;
}
