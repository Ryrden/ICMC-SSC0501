#include <stdio.h>
#include <stdlib.h>

int main(){

    int num;
    int fibonacci, soma = 1, soma_anterior = 0;

    scanf("%d", &num);


    printf("0 1 ");

    while (soma <= num){

        fibonacci = soma_anterior + soma;

        soma_anterior = soma;

        soma = fibonacci;

        printf("%d ", fibonacci);

    }

    return 0;
    system("pause");
}
