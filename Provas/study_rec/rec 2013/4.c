#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    float a, b, c;
    float x, y, z;

    scanf("%f %f %f", &a, &b, &c);
    scanf("%f %f %f", &x, &y, &z);

    float comprimento = y / b;
    float largura = x / a;
    float altura = z / c;

    int res = (int)(comprimento * largura * altura);

    printf("%d", res);
    return 0;
}
