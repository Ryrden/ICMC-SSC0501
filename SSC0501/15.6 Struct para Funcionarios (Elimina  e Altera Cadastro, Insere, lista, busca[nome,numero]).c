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

    int static tam;
    int opt, i;

    printf("(MAX: 100)\nQuantos funcionarios, deseja registrar? ");
    scanf("%d", &tam);

    while (tam>100){
        printf("\nVoc� ultrapassou o limite, digite novamente: ");
        scanf("%d", &tam);
    }

    struct funcionarios f[tam];

    for(i=0; i < tam; i++){
        LeDados(f + i);
        if (i == tam){printf("\n--Programa Finalizado--\n");}
    }

    MENU(tam, f);

    return 0;
    system("pause");
}

void MENU(int tam, struct funcionarios *f){ //Menu com op��es

    int opt, i;
    printf("\n\nDigite o n�mero que tem respeito a op��o desejada:\n\n");
    printf("1: Listar todos os funcionarios cadastrados\n");
    printf("2: Procurar funcion�rio por ID ou por NOME\n");
    printf("3: Alterar dados de um funcion�rio\n");
    printf("4: Eliminar um cadastro de funcion�rio\n");
    printf("5: Sair\n\n       R: ");

    scanf("%d", &opt);

    switch(opt){

        case 1:
            system("CLS");

            printf("\n Digite o n�mero do funcionario que deseja ver mais:\n");
            ListaDados(tam, &f);

            printf("\n\nDigite: ");
            scanf("%d", &opt);

            system("CLS");
            Lista_Todos_Dados(opt+1, f);

            break;

        case 2:
            Lista_Todos_Dados(BuscaFuncionario(tam, f), f);
            break;

        case 3:
            printf("Qual funcion�rio voc� deseja alterar os dados?");
            i = BuscaFuncionario(tam, f);
            AlteraDados(i, f);

            printf("Novos dados do funcion�rio: \n");
            Lista_Todos_Dados(i, f);
            break;

        case 4:
            printf("Qual funcion�rio voc� deseja eliminar o cadastro?");
            i = BuscaFuncionario(tam, f);
            EliminaCadastro(i, tam, f);
            tam--;

            printf("\nNovos dados dos funcion�rios: \n");
            ListaDados(tam, f);
            break;

        default:
            printf("Saindo...");
            break;

    }

    return 0;
    system("pause");
}

void EliminaCadastro(int posicao,int tam, struct funcionarios *f){

    for(int cont = posicao; cont < tam; cont++){

        f[cont].ID = f[cont+1].ID;
        f[cont].idade = f[cont+1].idade;
        f[cont].telefone = f[cont+1].telefone;
        f[cont].salario = f[cont+1].salario;
        *f[cont].cargo = *f[cont+1].cargo;
        *f[cont].nome = *f[cont+1].nome;
    }
}

void AlteraDados(int i,struct funcionarios *f){ //Altera dados do Funcion�rio

    int opt;
    printf("Digite o n�mero correspondente ao dado que deseja alterar:\n\n");
    printf("1: ID -- 2: NOME -- 3: IDADE -- 4: CARGO -- 5: SAL�RIO -- 6: TELEFONE\n\n       Digite: ");
    scanf("%d", &opt);
    fflush(stdin);

    switch(opt){
        case 1:
            printf("Digite o numero(ID) do funcionario : " );
            scanf("%d", &f[i].ID);
            fflush(stdin);
            break;

        case 2:
            printf("\nDigite o nome do funcionario : " );
            scanf("%[^\n]s", f[i].nome);
            fflush(stdin);
            break;

        case 3:
            printf("\nDigite a idade do funcionario : " );
            scanf("%d", &f[i].idade);
            fflush(stdin);
            break;

        case 4:
            printf("\nDigite o cargo do funcionario : " );
            scanf("%[^\n]s", f[i].cargo);
            fflush(stdin);
            break;

        case 5:
            printf("\nDigite o sal�rio do funcionario : " );
            scanf("%f", &f[i].salario);
            fflush(stdin);
            break;

        case 6:
            printf("\nDigite o n�mero de telefone do funcionario : " );
            scanf("%d", &f[i].telefone);
            fflush(stdin);

            break;
        default:

            break;


    }


}

int BuscaFuncionario(int tam,struct funcionarios *f){ //Busca o funcion�rio e retorna a posi��o na mem�ria em que ele est�

    int i, opt;
    int ID;
    char nome[30];

    printf("\n Deseja Buscar por:\n");
    printf("1: ID \n2: NOME\n       Digite: ");
    scanf("%d", &opt);
    fflush(stdin);

    if (opt == 1){ // ID
        printf("Digite o ID: ");
        scanf("%d", &ID);
        for(i = 0; i < tam; i++){
            if (f[i].ID == ID){
                printf("\n");
                return i;
            }
        }
    }
    if (opt == 2){
        printf("Digite o NOME: ");
        scanf("%[^\n]s", &nome);
        for(i = 0; i < tam; i++){
            if (strcmp(f[i].nome, nome) == 0){
                return i;
            }
        }
    }

}

void ListaDados(int tam, struct funcionarios *f){ //Lista ID e Nome
    for(int i=0; i < tam; i++){

        printf("\nFuncion�rio [%d]\n", (i+1));
        printf("ID: %d -- Nome: %s\n", f[i].ID, f[i].nome);
    }

}

void Lista_Todos_Dados(int opt, struct funcionarios *f){ //Lista ID,Nome,Idade,Cargo,Sal�rio,Telefone
    printf("\nFuncion�rio [%d]\n", opt);
    printf("ID: %d \nNome: %s \nIdade: %d", f[opt].ID, f[opt].nome, f[opt].idade);
    printf("\nCargo: %s \nSal�rio: %.2f \nTelefone: %d", f[opt].cargo, f[opt].salario, f[opt].telefone);

}

void LeDados(struct funcionarios *f){ //Realiza leitura dos dados do funcion�rio


    static cont = 1;
    system("CLS");

    printf("Digite o n�mero(ID) do funcionario %d: ", cont);
    scanf("%d", &f->ID);
    fflush(stdin);

    printf("\nDigite o nome do funcionario %d: ", cont);
    scanf("%[^\n]s", f->nome);
    fflush(stdin);
    /*
    printf("\nDigite a idade do funcionario %d: ", cont);
    scanf("%d", &f->idade);
    fflush(stdin);

    printf("\nDigite o cargo do funcionario %d: ", cont);
    scanf("%[^\n]s", f->cargo);
    fflush(stdin);

    printf("\nDigite o sal�rio do funcionario %d: ", cont);
    scanf("%f", &f->salario);
    fflush(stdin);

    printf("\nDigite o n�mero de telefone do funcionario %d: ", cont);
    scanf("%d", &f->telefone);
    fflush(stdin);
    */
    cont++;
}
