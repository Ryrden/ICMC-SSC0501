#include <stdio.h>
#include <stdlib.h>

struct funcionarios{

    int ID;//
    int idade;//
    int telefone;
    float salario;
    char cargo[30];//
    char nome[30]; //

};

int main(){

    int tam;
    printf("(MAX: 100)\nQuantos funcionarios, deseja registrar? ");
    scanf("%d", &tam);

    while (tam>100){
        printf("\nVoce ultrapassou o limite, digite novamente: ");
        scanf("%d", &tam);
    }

    struct funcionarios f[tam];

    for(int i=0; i < tam; i++){
        LeDados(f[i]);
    }


    return 0;
    system("pause");
}

void LeDados(struct funcionarios *f){

    static cont = 1;
    system("CLS");

    printf("Digite o numero(ID) do funcionario %d: ", cont);
    scanf("%d", &f->ID);
    fflush(stdin);

    printf("\nDigite o nome do funcionario %d: ", cont);
    fgets(f->nome, 30, stdin);
    fflush(stdin);

    printf("\nDigite a idade do funcionario %d: ", cont);
    scanf("%d", &f->idade);
    fflush(stdin);

    printf("\nDigite o cargo do funcionario %d: ", cont);
    fgets(f->cargo, 30, stdin);
    fflush(stdin);

    printf("\nDigite o salario do funcionario %d: ", cont);
    scanf("%f", &f->salario);
    fflush(stdin);

    printf("\nDigite o numero de telefone do funcionario %d: ", cont);
    scanf("%d", &f->telefone);
    fflush(stdin);

    cont++;
}
