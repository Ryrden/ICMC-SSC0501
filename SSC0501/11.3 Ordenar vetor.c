#include <stdio.h>
#include <stdlib.h>


int main(){

    int gaveta[10];
    int i, j, aux;

    for(i = 0; i < 10; i++){

        scanf("%d", &gaveta[i]);
    }
    i = 0;
    while( i < 10){

        j = i+1; //crucial

        while (j < 10){

            if (gaveta[i] > gaveta[j]){

                aux = gaveta[i];
                gaveta[i] = gaveta[j];
                gaveta[j] = aux;
                }
            j++;
        }

        i++;
    }

    for(i = 0; i < 10; i++){

        printf("%d ", gaveta[i]);

    }

    return 0;
    system("pause");
}
