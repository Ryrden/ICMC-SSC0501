#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int ano;
    int aparicao = 1986;

    scanf("%d", &ano);
    while (ano >= aparicao) {
        aparicao += 76;
    }

    printf("%d \n", aparicao);
    return 0;
}
