#include <stdio.h>
#include <stdlib.h>


int main(){

    int matriz[5][5], lin, col;
    int A, B;
    int contador = 0;

    for (lin = 0; lin < 5; lin++){

        for (col = 0; col < 5; col++){

            scanf("%d", &matriz[lin][col]);
        }
    }

    scanf("%d %d", &A, &B);


    while (A >= B){
        scanf("%d %d", &A, &B);
    }


    for (lin = 0; lin < 5; lin++){

        for (col = 0; col < 5; col++){

            if (matriz[lin][col] >= (A+1) && matriz[lin][col] <= (B-1))

                contador++;
        }
    }

    printf("%d", (contador+2));

    return 0;
    system("pause");
}
