#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct produtos{

    char nome[256];
    int codigo;
    float preco;
    int estoque;

};

struct vendas{

    //int codigo; esta variável não está sendo utilizada porque o código dela é o mesmo do produto,
    int quantidade;
    int dia;
    int mes;
    int ano;
};

int BuscaProduto();

void menu();
void CadastraProduto();
void Registravendas();
void EditaCadastro();
void ListarProdutos();
void ListaTodosDados();
void EliminaCadastro();
void RelatorioVendasT();
void RelatorioVendasP();
void RelatorioRanking();
void FinalizaPrograma();
void lb(); //Limpa Buffer

//Variaveis globais para contagem após finalização do programa;
int cont_prod = -1;

int main(){
    setlocale(LC_ALL, "");

    FILE *arq;
    struct produtos p[1000];
    struct vendas v[1000];
    int opt;

    if ((arq = fopen("Base de dados.txt", "ab+")) == NULL){

        printf("\nErro na abertura de arquivo!\n");
        return 0;
    }

    fread(&cont_prod, sizeof(int), 1, arq);
    fread(p, sizeof(struct produtos), (cont_prod+1), arq);
    fread(v, sizeof(struct vendas), (cont_prod+1), arq);

    do{
        menu();
        scanf("%d", &opt);

        switch(opt){

        case 1: //Cadastrar produtos
            CadastraProduto(p);
            break;

        case 2: //Registrar vendas de um produto
            opt = BuscaProduto(p, cont_prod);
            if (opt == -1){break;}
            Registravendas(p, v, opt);
            break;

        case 3: //Listar produtos e vendas
            ListarProdutos(p, v, cont_prod+1);
            break;

        case 4: //Editar cadastro
            printf("\nQual produto você deseja alterar os dados?\n");
            opt = BuscaProduto(p, cont_prod);
            if (opt == -1){break;}

            EditaCadastro(p, v, opt);
            printf("Novos dados do produto: \n\n");
            ListaTodosDados(opt,p,v);
            break;

        case 5: //Eliminar cadastro
            break;

        case 6: //Relatorio de vendas total
            break;

        case 7: //relatorio de vendas de um determinado produto
            break;

        case 8: //ranking do produto mais vendido
            break;

        case 9: //fecha programa
            arq = fopen("Base de dados.txt", "w");
            FinalizaPrograma(arq ,p, v, &cont_prod);
            return 0;
            break;

        default:
            printf("\nOpção inválida \n\n");
            system("pause");
            break;

        }

    }while(opt != 9);

    fclose(arq);
    printf("\n\n");
    system("pause");
    return 0;
}

void lb(){ //Limpa buffer

    char c;
    while((c = getchar()) != '\n' && c != EOF){
        printf("Pressione Enter\n");
    }
}

void FinalizaPrograma(FILE *arq, struct produtos *p, struct vendas *v, int *cont_prod){ //Salva o arquivo em um documento txt

    fseek(arq,0,SEEK_SET);
    fwrite(cont_prod, sizeof(int), 1, arq);
    fwrite(p, sizeof(struct produtos), (*cont_prod+1), arq);
    fwrite(v, sizeof(struct vendas), (*cont_prod+1), arq);

    printf("\n\t\t\tObrigado por utilizar o programa \n\n\t\t\t\t  Saindo...\n");

}

void menu(){ //Menu com opções

    system("CLS");
    printf("=-=-=-=-=-=-=-=-=-=CONTROLE DE ESTOQUE PRODUTOS E REGISTRO DE VENDAS=-=-=-=-=-=-=-=-=-=");
    printf("\n\nDigite o número que tem respeito a opção desejada:\n\n");
    printf("1: Cadastrar um ou mais produtos\n");
    printf("2: Registrar vendas de um produto\n");
    printf("3: Listar todos os produtos\n");
    printf("4: Editar cadastro ou registro de venda de um produto (necessário código))\n");
    printf("5: Eliminar cadastro de um produto\n");
    printf("6: Gerar Relatório de vendas total\n");
    printf("7: Gerar Relatório de vendas de um determinado produto\n");
    printf("8: Gerar Relatório de ranking de produtos mais vendidos\n");
    printf("9: Salvar Alterações e Sair do programa\n\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\n       Digite: ");

}

void ListaTodosDados(int opt, struct produtos *p, struct vendas *v){ //Lista nome, código, preço, estoque, vendas e data da venda

    printf("\nProduto [%d]\n", opt);
    printf("Nome: %s \nCódigo: %d \nPreço: R$ %.2f", p[opt].nome, p[opt].codigo, p[opt].preco);
    printf("\nEstoque: %d\n\n", p[opt].estoque);
    printf("\nVendas: %d \nData: %d/%d/%d \n\n", v[opt].quantidade, v[opt].dia, v[opt].mes, v[opt].ano);
    system("pause");
}

void CadastraProduto(struct produtos *p){ //cadastra nome, código, preço e estoque de um ou mais produtos


    system("CLS");
    int tam;
    int j;

    printf("Quantos produtos você deseja cadastrar?: ");
    scanf("%d", &tam);
    lb();

    for(int i=0; i<tam;i++){
        system("CLS");
        cont_prod++;
        printf("Produtos cadastrados: %d/%d\n", i+1, tam);

        printf("\nNome do produto %d: ", cont_prod+1);
        scanf("%[^\n]s", &p[cont_prod].nome);
        lb();

        printf("Código do produto %d: ", cont_prod+1);
        scanf("%d", &p[cont_prod].codigo);
        lb();

        for(int j = 0; j < cont_prod; j++){
            while(p[j].codigo == p[cont_prod].codigo){
                printf("\n\nEsse código já foi cadastrado antes");
                printf("\ndigite novamente: ");
                scanf("%d", &p[cont_prod].codigo);
                lb();
            }
        }

        printf("Preço do produto %d: R$ ", cont_prod+1);
        scanf("%f", &p[cont_prod].preco);
        lb();

        printf("Estoque do produto %d: ", cont_prod+1);
        scanf("%d", &p[cont_prod].estoque);
        lb();

        }

    }

void Registravendas(struct produtos *p, struct vendas *v, int index){ //registra quantidade e data de venda

    if (p[index].estoque > 0){
        printf("\n Digite quantos itens do produto %s foram vendidos até o momento: ", p[index].nome);
        scanf("%d", &v[index].quantidade);
        lb();
        while (v[index].quantidade < 0){
            scanf("%d", &v[index].quantidade);
            lb();
        }

        printf("\n\nDigite a data da venda nesse formato: \nDia Mes Ano -> xx xx xxxx\n\t\tDigite: ");
        scanf("%d %d %d", &v[index].dia , &v[index].mes, &v[index].ano);
        lb();
        printf("\n\n");

    }
    else{
        printf("não é possível registrar a venda deste produto porque ele não tem estoque!");
        printf("edite o cadastro dele antes");
    }
}


void ListarProdutos(struct produtos *p, struct vendas *v, int tam){ //Lista produtos e quanto venderam até o momento
    int opt;
    system("CLS");

    printf("\nDigite o número do produto que deseja ver mais\n");

    for(int i=0; i < tam; i++){

        printf("\nProduto [%d]\n", (i+1));
        printf("Nome: %s -- Código: %d\n", p[i].nome, p[i].codigo);
    }


    printf("\n\nDigite: ");
    scanf("%d", &opt);

    while(opt < 0 || opt > tam){
        printf("\nproduto não existe!!\n");
        printf("Digite novamente: ");
        scanf("%d", &opt);

    }
    printf("\nProduto [%d]\n", opt);
    opt--;
    printf("Nome: %s \nCódigo: %d \nPreço: R$ %.2f", p[opt].nome, p[opt].codigo, p[opt].preco);
    printf("\nEstoque: %d\n\n", p[opt].estoque);
    if (v[opt].quantidade > 0){
        printf("\nVendas: %d \nData: %d/%d/%d \n\n", v[opt].quantidade, v[opt].dia, v[opt].mes, v[opt].ano);
    }

    system("pause");


}

void EditaCadastro(struct produtos *p, struct vendas *v, int index){ //Edita cadastro e ou venda do produto
    system("CLS");
    int opt;

    do{
        printf("Digite o número correspondente ao dado que deseja alterar:\n\n");
        printf("1: NOME -- 2: CÓDIGO -- 3: PREÇO -- 4: ESTOQUE -- 5: Nº DE VENDAS -- 6: DATA -- 7: SAIR DA EDIÇÃO\n\n       Digite: ");
        scanf("%d", &opt);
        lb();

        switch(opt){
            case 1:
                printf("Digite o nome do produto: ");
                scanf("%[^\n]s", &p[index].nome);
                lb();
                break;

            case 2:
                printf("\nDigite o código do produto: ");
                scanf("%d", &p[index].codigo);
                lb();
                break;

            case 3:
                printf("\nDigite o preço do produto: ");
                scanf("%f", &p[index].preco);
                lb();
                break;

            case 4:
                printf("\nDigite o estoque do produto: ");
                scanf("%d", &p[index].estoque);
                lb();
                break;

            case 5:
                printf("\nDigite o número de vendas do produto: ");
                scanf("%d", &v[index].quantidade);
                lb();
                break;

            case 6:
                printf("\nDigite a data da venda do produto no formato: xx xx xxxx\n\t\tDigite: ");
                scanf("%d %d %d", &v[index].dia , &v[index].mes, &v[index].ano);
                lb();
                break;

            case 7:
                break;

            default:
                printf("opção inválida, digite novamente");
                sleep(1);
                break;
        }
    }while(opt != 7);
}

int BuscaProduto(struct produtos *p, int tam){ //retorna posição do vetor na qual o produto está

    int cod;
    printf("Digite o código do produto: ");
    scanf("%d", &cod);
    lb();

    for(int i = 0; i < tam; i++){

        if (cod == p[i+1].codigo){
            return i+1;
        }
        else{
            printf("\nEsse produto não existe");
            sleep(2);
            return -1;
        }
    }
}
