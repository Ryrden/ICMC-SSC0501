#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Algoritmo de Euclides
int MDC(int numero1, int numero2){

    int resto;

    numero1 = abs(numero1);
    numero2 = abs(numero2);

    if (numero1 % numero2 == 0){return numero2;}
    else if (numero2 % numero1 == 0){return numero1;}
    else{

        while (numero2 != 0){

            resto = numero1 % numero2;
            numero1 = numero2;
            numero2 = resto;
        }
        return numero1;
    }
}


int main(){
    setlocale(LC_ALL, "");

    int numero1, numero2;
    int result;

    scanf("%d %d", &numero1, &numero2);

    result = MDC(numero1, numero2);

    printf("o mdc é %d", result);


    printf("\n\n");
    system("pause");
    return 0;
}
