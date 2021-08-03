#include <stdio.h>
#include <stdlib.h>

int main(){

    int jogos, soma;
    int empatados=0,vitorias=0;
    int aux;

    scanf("%d %d", &jogos, &soma);

    if (soma % 3 == 0){
        vitorias = jogos;
    }
    else{
        aux = (int) (soma / 3)*3;
        vitorias = (soma / 3);
        while(aux != soma){
            aux +=2;
            empatados++;
        }

    }

    printf("%d %d", empatados, vitorias);
    return 0;
}
