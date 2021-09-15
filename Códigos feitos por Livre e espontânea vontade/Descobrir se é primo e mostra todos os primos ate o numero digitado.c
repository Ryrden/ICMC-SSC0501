#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int isPrime(int num) {

    if (num <= 1) {
        return 0;
    }

    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

int fatora_num(int num, int *vet) {

    int cont = 0;

    for (int i = 2; i <= num; i++) {

        if (isPrime(i)) {

            while (num % i == 0) {

                num = num / i;
                vet[cont] = i;
                cont++;
            }
        }
    }

    return (cont);
}

int main() {
    setlocale(LC_ALL, "");

    int valor;
    int resposta;

    printf("Digite o n�mero que deseja saber se � primo: ");
    scanf("%d", &valor);

    if (isPrime(valor) == 2) {

        printf("\nEsse n�mero � primo");
    } else {
        printf("\nEsse n�mero n�o � primo");
    }

    printf("\n\nDigite '1' para ver todos os primos at� o n�mero digitado e '0' caso o contr�rio: ");
    scanf("%d", &resposta);
    system("CLS");
    if (resposta == 1) {
        for (int i = 2; i <= valor; i++) {

            if (isPrime(i) == 2) {
                printf("%d ", i);
            }
        }
    } else {
        printf("Obrigado");
    }

    return 0;
    system("pause");
}
