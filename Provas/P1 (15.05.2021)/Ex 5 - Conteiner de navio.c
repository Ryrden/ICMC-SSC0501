#include <stdio.h>

//Ryan Souza Sá Teles
//nUSP: 12822062

int main(){

    float X, Y, Z;
    float A, B, C;

    int containerA = 0;
    int containerB = 0;
    int containerC = 0;

    scanf("%f %f %f", &X, &Y, &Z);
    scanf("%f %f %f", &A, &B, &C);

    float Base_a = A, Base_b = B, Base_c = C;

    while (A <= X){
        A = A + Base_a;
        containerA++;
    }
    while (B <= Y){
        B = B + Base_b;
        containerB++;
    }
    while (C <= Z){
        C = C + Base_c;
        containerC++;
    }

    printf("%d\n", containerA*containerB*containerC);

}
