#include <stdio.h>
#include <stdlib.h>

int isPrime(int primo){

    int primo_confirmado = 0, verificador;

    verificador = primo;

    while (verificador > 0){ //Verificando se o valor atual � primo

        if (primo % verificador == 0){

            primo_confirmado++;
            }

        verificador = verificador - 1;

        }

    return (primo_confirmado);
}

int main(){

    int valor;

    scanf("%d", &valor);

    for (int i = 2; i <= valor; i++){

        if (isPrime(i) == 2){ //Se a vari�vel Primo tiver apenas dois d�visores, � primo

            printf("%d ", i);

            }
        }

    return 0;
    system("pause");
}
