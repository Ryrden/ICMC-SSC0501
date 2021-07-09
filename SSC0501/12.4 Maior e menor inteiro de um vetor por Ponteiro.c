#include <stdio.h>
#include <stdlib.h>

void maior_menor(int *vet, int i, int *maior, int *menor){

    *maior = vet[0];
    *menor = vet[0];

    for (i = 0; i < 10; i++){

        if (*maior < vet[i]){
            *maior = vet[i];
        }

        if (*menor > vet[i]){
            *menor = vet[i];
        }
    }
}

int main(){

    int v[10], *maior, *menor, i;

    for(i = 0; i < 10; i++){
        scanf("%d", &v[i]);
    }

    maior_menor(v, i, &maior, &menor);

    printf("Maior: %d \nMenor: %d", maior, menor);

    return 0;
    system("pause");
}
