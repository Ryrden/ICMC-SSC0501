#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
float segundograu(float a, float b, float c, float *r1, float *r2) {

    float delta = (b * b) - 4 * a * c;

    if (delta > 0) {
        *r1 = ((-b) + sqrt(delta)) / 2 * a;
        *r2 = ((-b) - sqrt(delta)) / 2 * a;
        return 2;
    } else if (delta == 0) {
        *r1 = *r2 = ((-b) / 2 * a);
        return 1;
    }
    return 0;
}
int main() {

    float a, b, c;
    float r1 = 0, r2 = 0;
    scanf("%f %f %f", &a, &b, &c);

    int num_raizes = segundograu(a, b, c, &r1, &r2);

    printf("%f %f %d", r1, r2, num_raizes);

    return 0;
}
