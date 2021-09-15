#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int numJogos, pontos;
    int vitorias = 0, empatados = 0;

    scanf("%d %d", &numJogos, &pontos);

    if (pontos % 3) {
        vitorias = pontos / 3;
        int temp = vitorias * 3;
        for (/**/; temp != pontos; temp += 2) {
            empatados++;
        }
    }
    // pontos % 3 == 0 //
    vitorias = pontos / 3;

    printf("%d %d", empatados, vitorias);

    return 0;
}
