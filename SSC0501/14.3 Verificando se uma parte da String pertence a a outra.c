#include <stdio.h>
#include <stdlib.h>

int main(){

    int igual = 0;

    char palavra1[255] = {'Namorada'};
    char palavra2[255] = {'amor'};

    printf("Digite a palavra 1: ");
    fgets(palavra1, 255, stdin);

    printf("Digite a palavra 2: ");
    fgets(palavra2, 255, stdin);

    for(int i=0; palavra1[i] != '\0'; i++){
        if (palavra1[i] == palavra2[0]){
            igual = 1;
            for(int cont = i; palavra2[cont] != '\0'; cont++){

                if (palavra1[cont] != palavra2[cont]){
                    igual = 0;
                    break;
                }
            }
        }
    }

    printf("%d", igual);



    return 0;
    system("pause");
}
