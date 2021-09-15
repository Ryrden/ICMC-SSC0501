#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Dois números A e B são parentes se eles têm algum divisor em comum, 
além do 1. Crie um programa que lê dois inteiros e verifica se eles 
são parentes ou não. 
*/
int main() {
    int A, B;

    scanf("%d", &A);
    scanf("%d", &B);
    setbuf(stdin, NULL);

    int maior = (A > B) ? A : B; //Utilizei o Operador ternário como atribuição ao invés de criar uma função chamada max;

    for (int i = 2; i <= maior; i++) {
        if (A % i == 0 && B % i == 0) {
            printf("Sao parentes \n");
            return 0;
        }
    }
    printf("Nao sao parentes \n");

    return 0;
}
