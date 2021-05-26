#include <stdio.h>
#include <stdlib.h>


int main(){

    int x,y,soma = 0;

    scanf("%d", &x);

    scanf("%d", &y);

    for(int i = x; i <= y; i++){
        soma = soma + i;
    }

    printf("%d", soma);

    return 0;
    system("pause");
}
