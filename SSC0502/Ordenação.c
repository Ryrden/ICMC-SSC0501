#include <stdio.h>
#include <stdlib.h>


int main(){

    int valores[10];
    int aux;


    for (int i = 0; i < 10 ; i++){

        scanf("%d", &valores[i]);
    }

    for (int j = 0; j < 10; j++){

        for(int k = j+1; k < 10; k++){

            if (valores[j] > valores[k]){

                aux = valores[j];
                valores[j] = valores[k];
                valores[k] = aux;
            }

        }

    }


    for (int cont = 0; cont < 10; cont++){

        printf("%d ", valores[cont]);
    }


    return 0;
    system("pause");
}
