#include <stdio.h>
#include <stdlib.h>

int main(){

    int tam;
    float *notas, soma = 0;

    printf("Quantas Notas? ");
    scanf("%d", &tam);

    notas = (float*) malloc(tam*sizeof(float));

    for(int i = 0; i < tam; i++){
        scanf("%f", &notas[i]);
        soma+= notas[i];
    }
    free(notas);

    printf("A media aritmetica da turma foi de: %f", (soma/tam));

    return 0;
    system("pause");
}
