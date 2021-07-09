#include <stdio.h>
#include <stdlib.h>

int *alocaVetor(int tamanho){

    int *vet;
    vet = (int *) calloc(tamanho, sizeof(int));
    return(vet);

}

void alocaMultiplos(int *mult, int num){

    mult[0] = num;
    for(int i=0; i < num; i++){
        mult[i+1] = mult[i] + num;
    }
}

int main(){

    int num, *multiplos;
    scanf("%d", &num);

    multiplos = alocaVetor(num);
    alocaMultiplos(multiplos, num);

    for(int i=0; i < num; i++){
        printf("%d ", multiplos[i]);
    }

    free(multiplos);
    return 0;
    system("pause");
}
