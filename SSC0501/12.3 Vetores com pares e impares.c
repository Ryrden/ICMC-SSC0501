#include <stdio.h>
#include <stdlib.h>

void par_impar(int *vet, int *par, int *impar){

    int cont = 0;

    for (int i = 0; i < 20; i++){
        if(vet[i] % 2 == 0){

            par[cont] = vet[i];
            cont++;
        }

         if(vet[i] % 2 == 1){

            impar[cont] = vet[i];
        }

    }
}


int main(){

    int vet[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int par[10];
    int impar[10];

    par_impar(vet, par, impar);

    printf("Impares: ");
    for(int i=0; i<10;i++){

        printf("%d ", impar[i]);
    }
    printf("\nPares: ");
    for(int i=0;i<10;i++){

        printf("%d ", par[i]);
    }

    return 0;
    system("pause");
}
