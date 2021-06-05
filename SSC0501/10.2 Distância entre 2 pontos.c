#include <stdio.h>
#include <math.h>

double dist(int x1, int y1, int x2, int y2){

    double distancia;

    distancia = sqrt(pow((x2 - x1),2) + pow((y2-y1),2));

    return (distancia);
}

int main(){

    int x1,y1,x2,y2;
    double resultado;

    scanf("%d %d %d %d", &x1,&y1,&x2,&y2);

    resultado = dist(x1,y1,x2,y2);

    printf("%f", resultado);

    return 0;
}
