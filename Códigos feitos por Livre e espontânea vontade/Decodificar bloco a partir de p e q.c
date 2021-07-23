#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int encontraD(int p, int q){

    int totiene, d, k;

    totiene = (p-1) * (q-1);
    totiene = (int)totiene / 6;

    if (((totiene*6)+6) % 6 == 0){
        k = ((totiene*6)+6) / 6;
        printf("%d - certo\n", k);
    }
    else{
        printf("%d - errado", (((totiene*6)+6) % 6));
    }

    d = 4*k-1;

    return d;
}

int main(){
    setlocale(LC_ALL, "");

    int p,q, d, n;
    long long int pot, decodificado[500];
    int bloco[500], i=0;

    printf("digite p: ");
    scanf("%d", &p);

    printf("digite q: ");
    scanf("%d", &q);

    n = p*q;

    d = encontraD(p,q);

    do{
        printf("Digite 0 para sair\ndigite o bloco: ");

        scanf("%d ", &bloco[i]);
        fflush(stdin);

        i++;
    }while(bloco[i] != 0);


    for(i = 0; bloco[i] != 0; i++){

        pot = pow(bloco[i], d);
        printf("%lld --", pot);

        decodificado[i] = pot % n;
    }

    /*for(i = 0; decodificado[i] != 0; i++){
        printf("%lld ", decodificado[i]);
    }*/

    printf("\n\n");
    system("pause");
 return 0;
}
