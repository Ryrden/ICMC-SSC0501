#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

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

int fatora_num(int num, int *vet){

    int cont=0;

    for (int i = 2; i <= num; i++){

        if (isPrime(i) == 2){

            while(num % i == 0){

                num = num / i;
                vet[cont] = i;
                cont++;
            }
        }
    }

    return(cont);

}

int main(){
    setlocale(LC_ALL, "");

    int valor;
    int resposta;

    printf("Digite o n�mero que deseja saber se � primo: ");
    scanf("%d", &valor);

    if (isPrime(valor) == 2){

        printf("\nEsse n�mero � primo");
    }
    else{
        printf("\nEsse n�mero n�o � primo");
    }

    printf("\n\nDigite '1' para ver todos os primos at� o n�mero digitado e '0' caso o contr�rio: ");
    scanf("%d", &resposta);
    system("CLS");
    if (resposta == 1){
        for (int i = 2; i <= valor; i++){

            if (isPrime(i) == 2){
                printf("%d ", i);
                }
            }
    }
    else{
        printf("Obrigado");
    }

    return 0;
    system("pause");
}
