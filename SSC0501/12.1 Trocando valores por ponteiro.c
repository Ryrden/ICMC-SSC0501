#include <stdio.h>
#include <stdlib.h>

void TrocaValor(int *x, int *y){
    int aux;

    aux = *x;
    *x = *y;
    *y = aux;

}


int main(){

    int valor1, valor2;


    scanf("%d %d", &valor1, &valor2);

    TrocaValor(&valor1, &valor2);

    printf("Valor 1: %d \nValor 2: %d", valor1, valor2);


    return 0;
    system("pause");
}
