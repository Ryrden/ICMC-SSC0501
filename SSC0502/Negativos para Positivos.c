#include <stdio.h>
#include <stdlib.h>

//Tente fazer sem a função abs mas não encontrei jeito, vou tentar novamente até 5/7, caso não consiga esse texto ainda estará aqui.

void MudaSinal(int *vet){

    for(int i = 0; i < 10; i++){

        vet[i] = abs(vet[i]);
    }
}

int main(){

    int vet[10];

    for(int i = 0; i < 10; i++){

        scanf("%d", &vet[i]);
    }

    MudaSinal(&vet[0]);

    for(int i = 0; i < 10; i++){

        printf("%d ", vet[i]);
    }


    return 0;
    system("pause");
}
