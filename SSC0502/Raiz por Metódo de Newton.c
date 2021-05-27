#include <stdio.h>
#include <stdlib.h>


int main(){


    float R1, R2, E;
    int n;

    scanf("%f", &E);
    scanf("%d", &n);

    R1 = E/2;


    while (n > 1){

        R2 = R1;

        R1++;

        R1 = (R2 + (E/R2))/2;

        n--;

    }

    printf("%0.5f", R1);



    return 0;
    system("pause");
}
