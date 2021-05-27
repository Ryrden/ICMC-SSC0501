#include <stdio.h>
#include <stdlib.h>


int main(){

    int num;
    int cont = 1;
    scanf("%d", &num);

    do {

        if (num % cont == 0){
            printf("%d ", cont);
        }

        cont++;
        } while(cont <= num);

    return 0;
    system("pause");
}
