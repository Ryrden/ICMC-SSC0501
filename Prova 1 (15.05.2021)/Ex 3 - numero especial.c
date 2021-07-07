#include <stdio.h>
#include <stdlib.h>

//Ryan Souza Sá Teles
//nUSP: 12822062

//Pensei em utilizar um unsigned int.

int num_Especial(int num){

    int especial = 0, divisor;

    for(int i = num-1; i >= 1; i--){

        divisor = num % i;

        if (divisor == 0){

            especial = especial + i;
        }

    }

    return especial;

}



int main(){

    int numero;
    int especial;
    scanf("%d", &numero);

    while (numero < 0){scanf("%d", &numero);}

    especial = num_Especial(numero);

    if (especial == numero){printf("%d", 1);}
    else{printf("%d", 0);}



    return 0;
    system("pause");
}
