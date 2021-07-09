#include <stdio.h>
#include <stdlib.h>

//Para numeros bem grandes e com poucos divisores parece que o código fica infinitamente trabalhando.
//Eu gostaria de aprender a trabalhar com esse long long int. acho que errei algo nisso.
//Print do meu problema, com o número que utilizei, a quantidade de divisores não passou do 5. link: https://imgur.com/a/u6A4ugv
//Caso possa entrar em contato comigo, eu sou a pessoa da dúvida "exercicio 12.2" no FORUM do Tidia e meu email usp é ryansouza@usp.br

void qnt_divisores(long long int num, long long int *vet){

    long long int i;
    int x=0;

    vet = (long long int*) calloc(20, sizeof(long long int));

    if (vet == NULL){
        printf("** Erro: Memoria Insuficiente **");
        exit(1);
    }

    for(i = 0LL; i < num-1; i++){

        if ((num % (i+1LL) == 0LL) && (x <= 19)){
            vet[x] = (i+1);
            x++;
        }
        if (x > 19){
            break;
        }
    }

    for(i = x; i > 0LL; i--){
        printf("%lld ", vet[i-1]);
    }

    free(vet);

}

int main(){

    long long int num;
    long long int vet;

    scanf("%lld", &num);

    qnt_divisores(num, &vet);

    return 0;
    system("pause");
}
