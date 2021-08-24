#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// vm = s/t

int economica(float pe, float pg, float ce, float cg) {

    float Gasolina_preco_Km, Etanol_preco_Km;

    Gasolina_preco_Km = pg / cg;
    Etanol_preco_Km = pe / ce;

    if (Gasolina_preco_Km > Etanol_preco_Km) {
        return 1;
    }
    return 0;
}

int main() {

    float precoEtanol; //Litro
    float precoGasolina; //Litro
    float consumoEtanol; // (Km/l)
    float consumoGasolina; // (Km/l)

    scanf("%f %f %f %f", &precoEtanol, &precoGasolina, &consumoEtanol, &consumoGasolina);

    printf("%d", economica(precoEtanol, precoGasolina, consumoEtanol, consumoGasolina));

    return 0;
}
