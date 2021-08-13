#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *ConcatenaVetores(int *vetA, int *vetB) {

    int *vetFinal = malloc(20 * sizeof(int));
    int cont1 = 0, cont2 = 0;

    for (int i = 0; i < 20; i++) {

        if (vetB[cont2] < vetA[cont1] && cont2 <= 9) {
            vetFinal[i] = vetB[cont2];
            cont2++;
        } else if (vetA[cont1] < vetB[cont2] && cont1 <= 9) {
            vetFinal[i] = vetA[cont1];
            cont1++;
        } else if (vetA[cont1] == vetB[cont2] && cont1 <= 9 && cont2 <= 9) {
            vetFinal[i] = vetA[cont1];
            vetFinal[i + 1] = vetB[cont2];
            cont1++;
            cont2++;
            i++;
        } else {
            if (cont1 > 9) {
                vetFinal[i] = vetB[cont2];
                cont2++;
            } else {
                vetFinal[i] = vetA[cont1];
                cont1++;
            }
        }
    }

    return vetFinal;
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

    vetFinal = ConcatenaVetores(vetA, vetB);

    for (int i = 0; i < 20; i++) {
        printf("%d ", vetFinal[i]);
    }

    free(vetFinal);
    return 0;
}
