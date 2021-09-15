#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int MDC(int numero1, int numero2){

    int resto;

    numero1 = abs(numero1);
    numero2 = abs(numero2);

    if (numero1 % numero2 == 0){return numero2;}
    else if (numero2 % numero1 == 0){return numero1;}
    else{

        while (numero2 != 0){

            resto = numero1 % numero2;
            numero1 = numero2;
            numero2 = resto;
        }
        return numero1;
    }
}

int *alocaVetor(int tamanho){

    int *vet;
    vet = (int *) calloc(tamanho, sizeof(int));

    for(int i=0; i < tamanho;i++){
        vet[i] = i + 1;
    }
    return(vet);
}

int *alocaVetorN(int tamanho){

    int *vet;
    int cont = 0;
    vet = (int *) calloc(tamanho, sizeof(int));

    for(int i=0; i < tamanho;i++){
        vet[i] = cont - 1;
        cont--;
    }
    return(vet);
}

int resto_deAB(int a,int b){

    int r = abs(b % a);
    int q = abs(b / a);

    if(a > 0 && b > 0){
        r = b % a;

    }
    else if (a > 0 && b < 0){

        b = abs(b);

        r = b % a;
        q = b / a;
        if (r > 0){
            q = -q - 1;
            r = a - r;

        }
    }

    return r;
}

int verifica_primo(int numero){

    int isPrime = 0;
    int cont = 1;

    if (numero <= 1) {
        return 0;
    }

    while (cont <= numero){

        if (numero % cont == 0){
            isPrime++;
        }
        cont++;
    }
    return isPrime;
}

int main(){
    setlocale(LC_ALL, "");

    int a,b, resto;
    int *inverso, *inversoN;
    int maior;

    printf("Considerando A = X (mod B) e que \no inverso de A � um n�mero tal que Inverso*A = 1 (mod B)");
    printf("\nDigite o A: ");
    scanf("%d", &a);

    printf("\nDigite o B: ");
    scanf("%d", &b);

    maior = abs(b) > abs(a) ? maior=abs(b); : maior=abs(a); //Verifica qual dos n�meros digitados � maior em m�dulo
    //if (abs(b)>abs(a)){maior=abs(b);}else{maior=abs(a);}

    inverso = alocaVetor(maior);
    inversoN = alocaVetorN(maior);

    resto = resto_deAB(b,a); //foi dado invertido porque pelo o algoritmo da divis�o e a congru�ncia, inverte.

    if (MDC(a,b) != 1){
        printf("\n%d n�o tem inverso m�dulo %d", a,b);
        printf("\n\nO resto da divis�o de B por A �: %d", resto);
    }
    else{

        int inversoPositive = 0;
        int inversoNegative = 0;
        int i=0;

        while(i != -1){
            if (1 - b*inverso[i] % a == 0){
                inversoPositive = (1 - b*inverso[i]) / a;
                break;
            }
            i++;
        }
        i=0;
        while(i != -1){
            if ((1 - (b*inversoN[i])) % a == 0){
                inversoNegative = (1 - (b*inversoN[i])) / a;
                break;
            }
            i++;
        }
        system("CLS");
        printf("A: %d B: %d\n", a, b);
        printf("\nTemos as equa��es \n     %d*%d = 1 (mod %d) -Inverso via Testes com n�meros positivos \n", inversoPositive,a,b);
        printf("     %d*%d = 1 (mod %d) -Inverso via Testes com n�meros negativos \n", inversoNegative,a,b);
        printf("     %d = %d (mod %d) \ncom os seguintes resultados: \n", a, resto, b);
        printf("\nO inverso positvo de A m�dulo B �: %d", inversoPositive);
        printf("\nO inverso negativo de A m�dulo B �: %d", inversoNegative);
        printf("\nO resto da divis�o de B por A �: %d", resto);
        printf("\n\n\n\n     encoded by: Ryan S.\n");
    }

    printf("\n\n");
    system("pause");
    return 0;
}
