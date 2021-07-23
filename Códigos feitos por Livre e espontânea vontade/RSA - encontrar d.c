#include <stdio.h>
#include <stdlib.h>
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

    //d = 4*k - 1
    //(p-1)(q-1)=6*k - 2

    int p,q, d;

    printf("digite p: ");
    scanf("%d", &p);

    printf("digite q: ");
    scanf("%d", &q);

    d = encontraD(p,q);

    printf("%d -", d);

    printf("\n\n");
    system("pause");
 return 0;
}
