#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void soma_vetor(int *vetor1,int *vetor2,int *vetor_res,int n){

    vetor_res = (int *) calloc(n, sizeof(int));

    for(int i=0;i<n;i++){
        vetor_res[i] = vetor1[i] + vetor2[i];
    }
}

int main(){
    setlocale(LC_ALL, "");

    int n=10;
    int vetor1[10] = {1,2,3,4,5,6,7,8,9,10};
    int vetor2[10] = {10,9,8,7,6,5,4,3,2,1};
    int vetor_res[10];

    soma_vetor(vetor1, vetor2, vetor_res, n);

    for(int i=0;i<n;i++){
        printf("%d ", vetor_res[i]);
    }

    free(vetor_res);
    printf("\n\n");
    system("pause");
    return 0;
}
