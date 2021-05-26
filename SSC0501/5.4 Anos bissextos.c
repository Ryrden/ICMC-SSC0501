#include <stdio.h>
#include <stdlib.h>


int main(){

    int ano_inicial, ano_final;

    scanf("%d", &ano_inicial);
    scanf("%d", &ano_final);

    while(ano_inicial < ano_final){

        if ((ano_inicial % 4 == 0 && ano_inicial % 100 != 0) || ano_inicial % 400 == 0){
            printf("%d ", ano_inicial);
        }

        ano_inicial++;
    }

    return 0;
    system("pause");
}
