#include <stdio.h>
#include <stdlib.h>

//Não consegui ordenar sem ter que reordenar no meio da função...

int *ConcatenaVetor(int v1[], int v2[]){

    int *v3;
    int cont=0;

    v3 = (int*) calloc(20,sizeof(int));

    for(int i=0;i<20;i+=2,cont++){

        if (v2[cont] == v1[cont]){
            v3[i] = v1[cont];
            v3[i+1] = v2[cont];

        }
        else if (v2[cont] > v1[cont] && v1[cont] >= v3[i-1]){
            v3[i] = v1[cont];
            v3[i+1] = v2[cont];

        }
        else if (v2[cont] > v1[cont] && v1[cont] <= v3[i-1]){
            v3[i-1] = v1[cont];
            v3[i] = v2[cont-1];
            v3[i+1] = v2[cont];
        }
        else{
            v3[i] = v2[cont];
            v3[i+1] = v1[cont];
        }

    }

    return v3;
}

int main(){

    int v1[10] = {1, 2, 3, 4, 5, 6, 6, 8, 9, 9};
    int v2[10] = {1, 2, 3, 4, 5, 7, 7, 8, 8, 10};
    int *v3;

    /*for(int i=0;i<10;i++){
        scanf("%d", &v1[i]);
    }

    for(int i=0;i<10;i++){
        scanf("%d", &v2[i]);
    }*/

    v3 = ConcatenaVetor(v1,v2);

    for(int i=0;i<20;i++){
        printf("%d ", v3[i]);
    }

    free(v3);
    return 0;
}
