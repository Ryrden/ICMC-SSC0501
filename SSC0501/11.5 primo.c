#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void isPrime(num){

    int primo = 3;
    int verificador = 1;
    int isPrime;
    int prime;

    while (primo < num){

        verificador = 1;
        isPrime = 0;

        while (verificador <= primo){


            prime = primo % verificador;

            if (prime == 0){

                isPrime++;
            }
            verificador++;

            }

            if (isPrime == 2){
                printf("%d ", primo);
        }
        primo++;

    }
}

int main(){
 setlocale(LC_ALL, "");

    int num;

    printf("Digite um numero e irei mostrar todos os primos \nno intervalo entre 2 até valor digitado: ");
    scanf("%d", &num);


    isPrime(num);


 printf("\n\n");
 system("pause");
 return;
}
