#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void caso1 (int a,int b, int *q, int *r){

    *q = a / b;

    *r = a % b;

}


int main(){
    setlocale(LC_ALL, "");

    int dividendo,divisor,quociente, resto;

    printf("Considerando o Algoritmo como b|a, tal que a = bq + r \nDigite b: ");
    scanf("%d", &divisor);

    printf("\nDigite a: ");
    scanf("%d", &dividendo);


    if (dividendo > 0 && divisor > 0){

        caso1(dividendo, divisor, &quociente, &resto);

        printf("a = %d \nb = %d \nq = %d \nr = %d", dividendo,divisor,quociente, resto);
    }

    printf("\n\n");
    system("pause");
 return;
}
