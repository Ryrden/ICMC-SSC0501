#include <stdio.h>
#include <stdlib.h>


int main(){

    int num1, num2, num3;
    int mmc, mdc;
    int maior, menor;

    scanf("%d %d %d", &num1, &num2, &num3);

    if(num1 >= num2 && num1 >= num3){
        maior = num1;
    }
    else if(num2 >= num1 && num2 >= num3){
        maior = num2;
    }
    else if(num3 >= num1 && num3 >= num2){
        maior = num3;
    }

    if(num1 <= num2 && num1 <= num3){
        menor = num1;
    }
    else if(num2 <= num1 && num2 <= num3){
        menor = num2;
    }
    else if(num3 <= num1 && num3 <= num2){
        menor = num3;
    }

    for(int divisor = 1; divisor <= menor; divisor++){
        if((num1 % divisor == 0) && (num2 % divisor == 0) && (num3 % divisor == 0)){
            mdc = divisor;
        }
    }

    for(int divisor = num1 * num2 * num3; divisor >= maior; divisor--){
        if((divisor % num1 == 0) && (divisor % num2 == 0) && (divisor % num3 == 0)){
            mmc = divisor;
        }
    }


    printf("%d %d", mmc, mdc);

    return 0;
    system("pause");
}
