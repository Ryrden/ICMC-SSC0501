#include <stdio.h>
#include <stdlib.h>

int Maior(num1, num2, num3){ //retornar maior entre os 3 dados

    int maior;

    if(num1 >= num2 && num1 >= num3){
        maior = num1;
    }
    else if(num2 >= num1 && num2 >= num3){
        maior = num2;
    }
    else if(num3 >= num1 && num3 >= num2){
        maior = num3;
    }

    return maior;
}

int Menor(num1, num2, num3){ //retorna o menor valor entre os 3 dados

    int menor;

     if(num1 <= num2 && num1 <= num3){
        menor = num1;
    }
    else if(num2 <= num1 && num2 <= num3){
        menor = num2;
    }
    else if(num3 <= num1 && num3 <= num2){
        menor = num3;
    }

    return(menor);
}


int MMC(num1, num2, num3, maior, menor){

    int divisor = 2;
    int mmc;

    for(int divisor = num1 * num2 * num3; divisor >= maior; divisor--){
        if((divisor % num1 == 0) && (divisor % num2 == 0) && (divisor % num3 == 0)){
            mmc = divisor;
        }
    }

    return (mmc);
}

int MDC(num1, num2, num3, maior, menor){

    int divisor = 2;
    int mdc;

     for(int divisor = 1; divisor <= menor; divisor++){
        if((num1 % divisor == 0) && (num2 % divisor == 0) && (num3 % divisor == 0)){
            mdc = divisor;
        }
    }

    return (mdc);

}

int main(){

    int num1, num2, num3;
    int mmc, mdc;
    int maior, menor;

    scanf("%d %d %d", &num1, &num2, &num3);

    maior = Maior(num1,num2,num3);

    menor = Menor(num1,num2,num3);

    mmc = MMC(num1, num2, num3, maior, menor);

    mdc = MDC(num1, num2, num3, maior, menor);

    printf("%d %d", mmc, mdc);

    return 0;
    system("pause");
}
