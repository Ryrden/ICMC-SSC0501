#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Foi mas no RunCodes sumiu novamente a caixa de saida

int main(){
    setlocale(LC_ALL, "");

    int vezes1 = 0;
    int vezes2 = 0;
    int igual = 0;

    char string[50];
    char palavra1[50];
    char palavra2[50];

    fgets(string, 50, stdin);

    fgets(palavra1, 50, stdin);

    fgets(palavra2, 50, stdin);


    for(int i=0; string[i] != '\0'; i++){
        if (palavra1[0] == string[i]){
            igual = 1;
            int j = 0;
            for(int cont = i; palavra1[i] != '\0';cont++){

                if (palavra1[j] != string[cont] && palavra1[j] == ' '){
                    igual = 0;
                    break;
                }
                j++;
            }
            if (igual == 1){
                vezes1++;
            }
        }
    }

    for(int i=0; string[i] != '\0'; i++){
        if (palavra2[0] == string[i]){
            igual = 1;
            int j = 0;
            for(int cont = i; palavra2[i] != '\0';cont++){
                if (palavra2[j] != string[cont] && palavra2[j] == ' '){
                    igual = 0;
                    break;
                }
                j++;
            }
            if (igual == 1){
                vezes2++;
            }
        }
    }

    printf("%d %d", vezes1, vezes2);


    printf("\n\n");
    system("pause");
 return 0;
}
