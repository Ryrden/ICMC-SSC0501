#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//se digitar 4, vai de 0 a 4, 4 é a 5º linha

int fatorial(int n) {
    int fat;
    for (fat = 1; n > 1; n--)
        fat = fat * n;

    return fat;
}

int CoefBinomial(int n, int k) {
    int resposta;
    int k_fatorial, n_fatorial;

    n_fatorial = fatorial(n);
    k_fatorial = fatorial(k);

    resposta = (n_fatorial) / (k_fatorial * (fatorial(n - k)));

    return resposta;
}

int main() {

    int N;

    scanf("%d", &N);

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < i + 1; j++) {
            int ans;
            ans = CoefBinomial(i, j);
            printf("%d ", ans);
        }
        printf("\n");
    }

    return 0;
}
