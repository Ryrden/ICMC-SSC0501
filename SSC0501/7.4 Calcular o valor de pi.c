#include <stdio.h>
#include <stdlib.h>

int main(){

    int valor;
    int constante1 = 0;
    int constante2 = 0;
    double pi=0;

    scanf("%d", &valor);


    for(int i = 0; i < valor; i++){

        if (i % 2 == 0){

            pi = pi + (double)4/(double)(1 + constante1);
            constante1 = constante1 + 4;

        }
        else if (i % 2 != 0){

            pi = pi - (double)4/(double)(3 + constante2);
            constante2 = constante2 + 4;
        }

    }

    printf("%0.6f", pi);

    return 0;
    system("pause");
}
