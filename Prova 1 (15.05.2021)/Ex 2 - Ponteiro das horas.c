#include <stdio.h>
#include <stdlib.h>

//Ryan Souza Sá Teles
//nUSP: 12822062

//falta 2minutos para entregar, o raciocinio está correto mas no runCodes está dando erro.
//a resposta é do ponteiro A até o B no sentido anti horario, a resposta está em graus e sem o sinal.

int main(){

    float horas_a, minutos_a;
    float horas_b, minutos_b;

    float angulo_horas_a, angulo_minutos_a;
    float angulo_horas_b, angulo_minutos_b;

    float resposta;

    scanf("%f", &horas_a);
    while(horas_a < 0 && horas_a > 12){scanf("%f", &horas_a);}
    scanf("%f", &minutos_a);
    while(minutos_a < 0 && minutos_a > 59){scanf("%f", &minutos_a);}

    scanf("%f", &horas_b);
    while(horas_b < 0 && horas_b > 12){scanf("%f", &horas_b);}
    scanf("%f", &minutos_b);
    while(minutos_b < 0 && minutos_b > 59){scanf("%f", &minutos_b);}

    angulo_horas_a = (horas_a*30);
    angulo_horas_b = (horas_b*30);

    angulo_minutos_a = (minutos_a*6);
    angulo_minutos_b = (minutos_b*6);

    if (angulo_minutos_a != 0){

        angulo_horas_a = angulo_horas_a + ((30*angulo_minutos_a)/360);
    }

    if (angulo_minutos_b != 0){

        angulo_horas_b = angulo_horas_b + ((30*angulo_minutos_b)/360);
    }

    resposta = abs(360 - (angulo_horas_b - angulo_horas_a));

    printf("%.1f", resposta);



    return 0;
    system("pause");
}
