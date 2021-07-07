#include <stdio.h>
#include <stdlib.h>

//Ryan Souza Sá Teles
//nUSP: 12822062

//O pior é não saber o que está errado e ficar tentando...Consegui!

int main(){

    int num;
    int fibonacci, soma = 1, soma_anterior = 0;

    scanf("%d", &num);

    int fibonacci_invertido[num];

    for (int i = 0; i <= num;i++){

        fibonacci = soma_anterior + soma;

        soma_anterior = soma;

        soma = fibonacci;

        fibonacci_invertido[i] = fibonacci;
    }

    for (int i = num-2; i >= 0; i--){

        if (fibonacci_invertido[i] == 1){
            printf("%d %d", fibonacci_invertido[i], fibonacci_invertido[i]);
            break;
        }

        printf("%d ", fibonacci_invertido[i]);


    }

    return 0;
    system("pause");
}
