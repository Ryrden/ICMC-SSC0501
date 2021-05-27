#include <stdio.h>
#include <stdlib.h>


int main(){


    for (int quadrado = 1; quadrado <= 5000; quadrado++){

        int constante = 1;

        while((constante*constante) <= quadrado){

            if ((constante*constante) == quadrado){

                printf("%d ", quadrado);
            }

            constante++;
        }
    }

    return 0;
    system("pause");
}
