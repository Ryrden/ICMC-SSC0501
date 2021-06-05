#include <stdio.h>
#include <stdlib.h>


int main(){

    int num, fatorial = 0;

    scanf("%d", &num);

    fatorial = num;

    while (num > 1){

        fatorial = fatorial * (num-1);
        num--;
    }
    if (fatorial == 0){
        fatorial = 1;
    }

    printf("%d", fatorial);

    return 0;
    system("pause");
}
