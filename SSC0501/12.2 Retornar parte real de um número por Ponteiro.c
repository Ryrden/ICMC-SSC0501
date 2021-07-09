#include <stdio.h>
#include <stdlib.h>

void retornaInteiro(float num, int *inteiro, float *fracionario){

    *inteiro = (int)num;

    *fracionario = num - *inteiro;
}

int main(){

    float numero;
    int inteiro;
    float fracionario;

    scanf("%f", &numero);

    retornaInteiro(numero, &inteiro, &fracionario);

    printf("Parte Inteira: %d \nParte Fracionada: %.3f", inteiro, fracionario);

    return 0;
    system("pause");
}
