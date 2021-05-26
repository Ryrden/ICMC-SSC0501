#include <stdio.h>
#include <stdlib.h>

int main(){

    float nota;
    float mediageral, porcnotas_altas;
    float soma;
    int notasaltas = 0;
    int notasbaixas = -1;


    while (nota >= 0){


        if (nota >= 5){
            notasaltas++;
        } else if (nota < 5){
            notasbaixas++;
        }

        soma = soma + nota;

        scanf("%f", &nota);
    }

    mediageral = soma / (notasaltas+notasbaixas);

    float notasaltasF = notasaltas;
    float notasbaixasF = notasbaixas;
    porcnotas_altas = (notasaltas / (notasaltasF+notasbaixasF))*100;

    printf("%d %d %f %f", notasaltas, notasbaixas, mediageral, porcnotas_altas);

    return 0;
    system("pause");
}

