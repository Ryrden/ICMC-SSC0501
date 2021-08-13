#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *somaVetor(int *vet1, int x, int *k) {
    int tam = 0;
    for (int i = 0; i < 10; i++) {
        if (vet1[i] != x) {
            tam++;
        }
    }
    int *v = malloc(tam * sizeof(int));

    int cont = 0;
    for (int i = 0; i < 10; i++) {
        if (vet1[i] != x) {
            v[cont] = vet1[i];
            cont++;
        }
    }
    *k = tam;
    return v;
}

int main() {
    int vet1[10], *vet2;
    int x;

    for (int i = 0; i < 10; i++) {
        scanf("%d", &vet1[i]);
    }
    scanf("%d", &x);
    int N;
    vet2 = somaVetor(vet1, x, &N);

    for (int i = 0; i < N; i++) {
        printf("%d ", vet2[i]);
    }

    free(vet2);
    return 0;
}
