#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
 setlocale(LC_ALL, "");

    int vetor[20];
    int i, j, aux;
    int cont = 0;

    //lendo vetor
    for (i = 0; i < 20; i++){

        scanf("%d", &vetor[i]);
    }

    //ordenando vetor
    for(i = 0; i < 20; i++){

        for (j = i+1; j < 20; j++){

            if (vetor[i] > vetor[j]){

                aux = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = aux;
            }
        }
    }

    //contar quanto repetidos
    for(i = 0; i < 20; i++){

        if (vetor[i] == vetor[i+1]){

            cont++;
        }

    }

    //Declarando novo vetor com tamanho ideal
    //a quantidade de elementos não repetidos

    int sem_repetidos[20-cont];

    sem_repetidos[0] = vetor[0];

    j = 1;

    for (i = 1; i < (20); i++){

        if (vetor[i] != vetor[i-1]){

            sem_repetidos[j] = vetor[i];

            j++;
        }
    }

    //Imprimindo novo vetor sem elementos repetidos
    for(i = 0; i < (20-cont); i++){

        printf("%d ", sem_repetidos[i]);
    }


 printf("\n\n");
 system("pause");
 return;
}
