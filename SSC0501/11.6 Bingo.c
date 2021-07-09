#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <time.h>

int OrdenaCartela(int BINGO[5][5]){

    int lin, col;
    int aux;
    int col2;

    //Ordenando a Cartela
    for (lin = 0; lin < 5; lin++){

        for (col = 0; col < 5; col++){
            col2 = col;

            for (int j = lin; j < 5; j++){

                for(int k = col2; k < 5; k++){

                    if (BINGO[lin][col] > BINGO[j][k]){

                        aux = BINGO[lin][col];
                        BINGO[lin][col] = BINGO[j][k];
                        BINGO[j][k] = aux;
                    }
                }
                col2 = 0;
            }
        }
    }

}

int GeraCartela(int BINGO[5][5]){

    int lin, col;

    //Gerando Cartela
    for (lin = 0; lin < 5; lin++){

        for (col = 0; col < 5; col++){

            BINGO[lin][col] = rand() % 99;

        }
    }

    return(BINGO[5][5]);
}

int TiraRepetido(int BINGO[5][5]){

    int lin, col;

    for (lin = 0; lin < 5; lin++){

        for (col = 0; col < 5; col++){

            if (BINGO[lin][col+1] == BINGO[lin][col]){
                BINGO[lin][col] = rand() % 99;
            }

        }
    }

    return (BINGO[5][5]);
}

int main(){
 setlocale(LC_ALL, "");
 srand(time(NULL));

    int BINGO[5][5];
    int lin, col;
    int aux;
    int col2;

    //Gerando Cartela
    GeraCartela(BINGO);

    //Ordenando a Cartela
    OrdenaCartela(BINGO);

    //Removendo elementos Repetidos
    //da Cartela (repetindo 10x para ter certeza)
    for( int i = 0; i < 10; i++){

        TiraRepetido(BINGO);
        OrdenaCartela(BINGO);

    }


    //Imprimindo Cartela
    for (lin = 0; lin < 5; lin++){

        for (col = 0; col < 5; col++){

            printf("%d ", BINGO[lin][col]);

        }
        printf("\n");
    }

 printf("\n\n");
 system("pause");
 return;
}
