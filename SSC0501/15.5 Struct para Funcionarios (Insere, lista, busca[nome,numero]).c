#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <strings.h>

struct funcionarios{

    int ID; //
    int idade;//
    int telefone;//
    float salario;//
    char cargo[30];//
    char nome[30]; //

};

int main(){
    setlocale(LC_ALL, "");

    int tam, opt;
    printf("(MAX: 100)\nQuantos funcionarios, deseja registrar? ");
    scanf("%d", &tam);

    while (tam>100){
        printf("\nVocê ultrapassou o limite, digite novamente: ");
        scanf("%d", &tam);
    }

    struct funcionarios f[tam];

    for(int i=0; i < tam; i++){
        LeDados(f + i);
        if (i == tam){printf("\n--Programa Finalizado--\n");}
    }

    printf("\n\nDigite o número que tem respeito a opção desejada:\n\n");
    printf("1: Listar todos os funcionarios cadastrados\n");
    printf("2: Procurar funcionario por Nome ou por ID\n\nR: ");

    scanf("%d", &opt);

    switch(opt){

    case 1:
        system("CLS");

        printf("\n Digite o número do funcionario que deseja ver mais:\n");
        ListaDados(tam, &f);

        printf("\n\nDigite: ");
        scanf("%d", &opt);

        system("CLS");
        Lista_Todos_Dados(opt, f);

        break;

    case 2:
        printf("\n Deseja Buscar por:\n");
        printf("1: ID \n2: NOME\n       Digite: ");
        scanf("%d", &opt);
        fflush(stdin);
        BuscaFuncionario(tam, opt, f);
        break;

    default:
        printf("Saindo...");
        break;

    }

    return 0;
    system("pause");
}

void BuscaFuncionario(int tam, int opt,struct funcionarios *f){

    int i;
    int ID;
    char nome[30];

    if (opt == 1){ // ID
        printf("Digite o ID: ");
        scanf("%d", &ID);
        for(i = 0; i < tam; i++){
            if (f[i].ID == ID){
                printf("\n");
                Lista_Todos_Dados(i+1, f);
                break;
            }
        }

    }
    if (opt == 2){
        printf("Digite o NOME: ");
        scanf("%[^\n]s", &nome);
        for(i = 0; i < tam; i++){
            if (strcmp(f[i].nome, nome) == 0){
                Lista_Todos_Dados(i+1, f);
            }
        }
    }

}

void ListaDados(int tam, struct funcionarios *f){
    for(int i=0; i < tam; i++){

        printf("\nFuncionário [%d]\n", (i+1));
        printf("ID: %d -- Nome: %s\n", f[i].ID, f[i].nome);
    }

}

void Lista_Todos_Dados(int opt, struct funcionarios *f){
    printf("\nFuncionário [%d]\n", opt);
    printf("ID: %d \nNome: %s \nIdade: %d", f[opt-1].ID, f[opt-1].nome, f[opt-1].idade);
    printf("\nCargo: %s \nSalário: %.2f \nTelefone: %d", f[opt-1].cargo, f[opt-1].salario, f[opt-1].telefone);

}

void LeDados(struct funcionarios *f){

    static cont = 1;
    system("CLS");

    printf("Digite o numero(ID) do funcionario %d: ", cont);
    scanf("%d", &f->ID);
    fflush(stdin);

    printf("\nDigite o nome do funcionario %d: ", cont);
    scanf("%[^\n]s", f->nome);
    fflush(stdin);

    printf("\nDigite a idade do funcionario %d: ", cont);
    scanf("%d", &f->idade);
    fflush(stdin);

    printf("\nDigite o cargo do funcionario %d: ", cont);
    scanf("%[^\n]s", f->cargo);
    fflush(stdin);

    printf("\nDigite o salario do funcionario %d: ", cont);
    scanf("%f", &f->salario);
    fflush(stdin);

    printf("\nDigite o numero de telefone do funcionario %d: ", cont);
    scanf("%d", &f->telefone);
    fflush(stdin);

    cont++;
}
