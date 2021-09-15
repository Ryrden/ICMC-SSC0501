#include <stdio.h>
#include <stdlib.h>

//Ryan Souza Sá Teles
//nUSP: 12822062

//Pesquisei antes do exercicio, o cometa halley vai ser visto novamente em 28 de julho de 2061, logo, seu perido orbital é de 75,3 anos,
//como o exercicio dia 76 anos, o valor exibido é 2062.

int main(){

    int ano = 1986;
    int ano_atual;

    scanf("%d", &ano_atual);

    while (ano_atual < 2021){

        scanf("%d", &ano_atual);
    }

    while (ano < ano_atual){ano += 76; }

    printf("%d", ano);



    return 0;
    system("pause");
}
