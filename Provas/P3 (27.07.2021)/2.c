#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int isPrime(int primo) {
    int primo_confirmado = 0, verificador;
    verificador = primo;
    while (verificador > 0) { //Verificando se o valor atual � primo
        if (primo % verificador == 0) {
            primo_confirmado++;
        }
        verificador = verificador - 1;
    }
    return (primo_confirmado);
}

int main() {

    int x;
    int flag;
    int i, k;

    scanf("%d", &x);

    for (i = 2; i <= x; i++) {
        for (k = 2; k <= i; k++) {
            if (i % k == 0 && isPrime(k) == 2) {
                if (i % (k * k) == 0) {
                    flag = 0;
                } else {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 0) {
            printf("%d ", i);
        }
    }

    return 0;
}
