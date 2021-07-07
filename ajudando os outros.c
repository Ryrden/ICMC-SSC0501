#include <stdio.h>
#include <stdlib.h>

int isPrime(int primo){

    int primo_confirmado = 0, verificador;

    verificador = primo;

    while (verificador > 0){ //Verificando se o valor atual é primo

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

    int valor, vet[100], cont;

    printf("Digite o numero que deseja ver Fatorado: ");
    scanf("%d", &valor);

    cont = fatora_num(valor, &vet);
    printf("\nEste numero na forma fatorada tem a forma: \n\n");
    for(int i=0;i < (cont);i++){
        printf("%d ", vet[i]);
        if (i != (cont-1))printf("x ");
    }

    printf("\n\n");
    return 0;
    system("pause");
}
