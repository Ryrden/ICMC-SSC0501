#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *ConcatenaVetores(int *vetor1, int tam1, int *vetor2, int tam2) {
    // Vetor resultado
    int *unido = (int *)malloc(sizeof(int) * (tam1 + tam2));

    // Posição no vetor 1
    int pos1 = 0;
    // Posição no vetor 2
    int pos2 = 0;

    while (1) {
        // Caso exista elemento no vetor1 E (não tenha elemento no vetor2 OU o elemento de vetor1 seja menor)
        if (pos1 < tam1 && (pos2 >= tam2 || vetor1[pos1] < vetor2[pos2])) {
            // Colocar elemento do vetor1 no vetor resultado
            unido[pos1 + pos2] = vetor1[pos1];
            // Incrementar posição
            pos1++;
            // Se não, caso exista elemento no vetor2
        } else if (pos2 < tam2) {
            // Colocar elemento do vetor2 no vetor resultado
            unido[pos1 + pos2] = vetor2[pos2];
            // Incrementar posição
            pos2++;
            // Se não, acabaram os dois vetores
        } else {
            break;
        }
    }

    return unido;
}

int main() {

    int vetA[10];
    int vetB[10];
    int *vetFinal;

    for (int i = 0; i < 10; i++) {
        scanf("%d", &vetA[i]);
    }
    for (int i = 0; i < 10; i++) {
        scanf("%d", &vetB[i]);
    }

    vetFinal = ConcatenaVetores(vetA, 10, vetB, 10);

    for (int i = 0; i < 20; i++) {
        printf("%d ", vetFinal[i]);
    }

    free(vetFinal);
    return 0;
}
