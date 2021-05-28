#include <stdio.h>
#include <stdlib.h>


int main(){

    float prova1,prova2,prova3;
    float trabalho1,trabalho2;
    float media;
    float maior1;
    float maior2;

    scanf("%f %f %f", &prova1, &prova2, &prova3);

    scanf("%f %f", &trabalho1, &trabalho2);

    if (prova1 >= prova2 && prova2 >= prova3){
        maior1 = prova1;
        maior2 = prova2;
    }
    else if (prova1 >= prova3 && prova3 >= prova2){
        maior1 = prova1;
        maior2 = prova3;
    }

    if (prova2 >= prova1 && prova1 >= prova3){
        maior1 = prova2;
        maior2 = prova1;
    }
    else if (prova2 >= prova3 && prova3 >= prova1){
        maior1 = prova2;
        maior2 = prova3;
    }

    if (prova3 >= prova1 && prova1 >= prova2){
        maior1 = prova3;
        maior2 = prova1;
    }
    else if (prova3 >= prova2 && prova2 >= prova1){
        maior1 = prova3;
        maior2 = prova2;
    }

    media = (0.70*((maior1+maior2)/2)) + (0.30*(trabalho1+trabalho2)/2);

    printf("%f", media);


    return 0;
    system("pause");
}
