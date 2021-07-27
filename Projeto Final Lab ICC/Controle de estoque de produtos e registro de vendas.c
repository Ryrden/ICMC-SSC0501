#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*INFORMAÇÕES:

    NOME: Ryan Souza Sá Teles
    nUSP: 12822062
    Turma: BSI [021]
    Instituto: Instituto de Ciências Matemáticas e de Computação
    Disciplina: Introdução a Ciência da Computação I
    Professor: Dennis Wolf
*/


struct produtos{

    char nome[256];
    int codigo;
    float preco;
    int estoque;

};

struct vendas{

    //int codigo; esta variável não está sendo utilizada porque o código dela é o mesmo do produto,
    int quantidade;
    char data[11][10]; // formato: DD/MM/AAAA; limite: 10 vendas por item, a ultima sobrepõe
};

int BuscaProduto();
int BuscaMes();

void menu();
void CadastraProduto();
void Registravendas();
void EditaCadastro();
void ListarProdutos();
void ListaTodosDados();
void EliminaCadastro();
void RelatorioVendasT();
void RelatorioVendasM();
void RelatorioVendasP();
void RelatorioRanking();
void SalvarAlteracoes();
void lb(); //Limpa Buffer

//Variaveis globais para contagem após finalização do programa;
int cont_prod = -1;

int main(){
    setlocale(LC_ALL, "");

    FILE *arq;
    struct produtos p[1000];
    struct vendas v[1000];
    int opt;
    char res[11];

    if ((arq = fopen("Base de dados.txt", "ab+")) == NULL){

        printf("\nErro na abertura de arquivo!\n");
        return 0;
    }

    fread(&cont_prod, sizeof(int), 1, arq);
    fread(&p, sizeof(struct produtos), (1000), arq);
    fread(&v, sizeof(struct vendas), (1000), arq);

    do{
        menu();
        scanf("%d", &opt);
        lb();

        switch(opt){

        case 1: //Cadastrar produtos
            CadastraProduto(p);
            break;

        case 2: //Registrar vendas de um produto
            if (cont_prod == -1){
                printf("\nVocê não pode registrar uma venda sem cadastrar um produto antes!\n\n");
                system("pause");
                break;
            }
            opt = BuscaProduto(p, cont_prod);
            if (opt == -1){break;}
            system("CLS");
            printf("Dados do Produto: ");
            ListaTodosDados(opt, p, v);
            Registravendas(p, v, opt);
            break;

        case 3: //Listar produtos e vendas
            if (cont_prod == -1){
                printf("A lista está vazia! \nCadastre algum produto e sua respectiva venda antes.\n\n");
                system("pause");
                break;
            }
            else{
                ListarProdutos(p, v, cont_prod+1);
                break;
            }

        case 4: //Editar cadastro
            if (cont_prod == -1){
                printf("\nVocê não pode editar uma cadastro sem cadastrar um produto antes!\n\n");
                system("pause");
                break;
            }
            printf("\nQual produto você deseja alterar os dados?\n");
            opt = BuscaProduto(p, cont_prod);
            if (opt == -1){break;}

            EditaCadastro(p, v, opt);
            printf("Novos dados do produto: \n\n");
            ListaTodosDados(opt, p, v);
            system("pause");
            break;

        case 5: //Eliminar cadastro
            if (cont_prod == -1){
                printf("\nVocê não pode eliminar um cadastro sem cadastrar um produto antes!\n\n");
                system("pause");
                break;
            }else{
                printf("\nQual produto você deseja eliminar do cadastro?\n");
                opt = BuscaProduto(p, cont_prod);
                if (opt == -1){break;}

                EliminaCadastro(p, v, &cont_prod, opt);
                printf("\nSucesso...Salve e Feche o programa para que as alterações sejam feitas\n");
                sleep(1,5);
                system("pause");
                break;
            }

        case 6: //Relatorio de vendas total
            if (cont_prod == -1){
                printf("\nVocê não pode gerar um relatório das vendas sem o cadastrar ao menos um produto antes!\n\n");
                system("pause");
                break;
            }
            else{

                RelatorioVendasT(p, v, cont_prod);
                break;
            }

        case 7: //relatorio de vendas de um determinado produto
            if (cont_prod == -1){
                printf("\nVocê não pode gerar um relatório de vendas de um produto sem o cadastrar antes!\n\n");
                system("pause");
                break;
            }
            else{
                printf("\nQual produto você deseja gerar um relatório?\n");
                opt = BuscaProduto(p, cont_prod);
                if (opt == -1){break;}

                RelatorioVendasP(p, v, cont_prod, opt);
                break;
            }

        case 8: //ranking do produto mais vendido
            if (cont_prod <= 0){
                printf("\nVocê não pode gerar um relatório de ranking dos produto mais vendidos sem ter cadastrado ao menos DOIS produtos antes!\n\n");
                system("pause");
                break;
            }
            else{

            RelatorioRanking(p, v, cont_prod);
            return 0;
            break;
            }

        case 9: //Relatório de Vendas no Mês especifico
            if (cont_prod == -1){
                printf("\nVocê não pode gerar um relatório de vendas no mês sem ter cadastrado ao menos dois produtos antes!\n\n");
                system("pause");
                break;
            }
            else{
                printf("Digite o número do mês e o ano no formato: \nMês  -> MM\n\t\tDigite: ");
                scanf("%[^\n]s", &res);
                lb();
                opt = BuscaMes(v, cont_prod, res);
                if (opt == -1){break;}

                RelatorioVendasM(p, v, cont_prod, res);
                break;
            }

        case 10: //fecha programa
            arq = fopen("Base de dados.txt", "wb+");
            SalvarAlteracoes(arq , p, v, &cont_prod);
            printf("\n\t\t\tObrigado por utilizar o programa \n\n\t\t\t\t  Saindo...\n");
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

void SalvarAlteracoes(FILE *arq, struct produtos *p, struct vendas *v, int *cont_prod){ //Salvar alterações

    fseek(arq,0,SEEK_SET);
    fwrite(cont_prod, sizeof(int), 1, arq);
    fwrite(p, sizeof(struct produtos), (1000), arq);
    fwrite(v, sizeof(struct vendas), (1000), arq);

    printf("Salvando...");
    sleep(1);
}

void menu(){ //Menu com opções

    system("CLS");
    printf("=-=-=-=-=-=-=-=-=-=CONTROLE DE ESTOQUE PRODUTOS E REGISTRO DE VENDAS=-=-=-=-=-=-=-=-=-=");
    printf("\n\nDigite o número que tem respeito a opção desejada:\n\n");
    printf("1: Cadastrar um ou mais produtos\n");
    printf("2: Registrar vendas de um produto(*)\n");
    printf("3: Listar todos os produtos\n");
    printf("4: Editar cadastro ou registro de venda de um produto(*)\n");
    printf("5: Eliminar cadastro de um produto(*)\n");
    printf("6: Gerar Relatório de vendas total\n");
    printf("7: Gerar Relatório de vendas de um determinado produto(*)\n");
    printf("8: Gerar Relatório de ranking de produtos mais vendidos[FPAE](*)\n");
    printf("9: Gerar Relatório de vendas de um determinado mês\n");
    printf("10: Salvar Alterações e Sair do programa\n\n");
    printf("\t\t\t[FPAE]: Após a execução, finaliza o programa SEM SALVAR alterações feitas antes (CUIDADO)\n");
    printf("\t\t\t   (*): Necessário o código do produto \n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\n       Digite: ");

}

void ListaTodosDados(int opt, struct produtos *p, struct vendas *v){ //Lista nome, código, preço, estoque, vendas e data da venda

    printf("\nProduto [%d]\n", opt+1);
    printf("Nome: %s \nCódigo: %d \nPreço: R$ %.2f", p[opt].nome, p[opt].codigo, p[opt].preco);
    printf("\nEstoque: %d\n\n", p[opt].estoque);
    int i = 9;
    while (v[opt].data[i][3] != '0' && v[opt].data[i][3] != '1'){
        i--;
        if ( i == 0){
            break;
        }
    }
    printf("\nVendas totais: %d \nData: %s \n\n", v[opt].quantidade, v[opt].data[i]);
}

void CadastraProduto(struct produtos *p){ //cadastra nome, código, preço e estoque de um ou mais produtos

    system("CLS");
    int tam;
    int j;

    printf("Quantos produtos você deseja cadastrar?: ");
    scanf("%d", &tam);
    lb();

    for(int i=0; i < tam;i++){
        system("CLS");

        cont_prod++;
        printf("Produtos cadastrados: %d/%d\n", i+1, tam);

        printf("\nNome do produto %d: ", cont_prod+1);
        scanf("%[^\n]s", &p[cont_prod].nome);
        lb();

        printf("\nCódigo do produto %d (número): ", cont_prod+1);
        scanf("%d", &p[cont_prod].codigo);
        lb();
        for(j = 0; j < cont_prod; j++){
            while(p[j].codigo == p[cont_prod].codigo || p[cont_prod].codigo < 0){
                printf("\nEsse código já foi cadastrado antes ou é inválido");
                printf("\ndigite novamente: ");
                scanf("%d", &p[cont_prod].codigo);
                lb();
            }
        }

        printf("\nPreço do produto %d: R$ ", cont_prod+1);
        scanf("%f", &p[cont_prod].preco);
        lb();
        while(p[cont_prod].preco < 0){
            printf("\nEsse preço não é válido");
            printf("\ndigite novamente: ");
            scanf("%f", &p[cont_prod].preco);
            lb();
        }

        printf("\nEstoque do produto %d: ", cont_prod+1);
        scanf("%d", &p[cont_prod].estoque);
        lb();
        while(p[cont_prod].estoque < 0){
            printf("\nEstoque inválido");
            printf("\ndigite novamente: ");
            scanf("%f", &p[cont_prod].estoque);
            lb();
        }
    }
}

void Registravendas(struct produtos *p, struct vendas *v, int index){ //registra quantidade e data de venda

    int aux, i;

    if (p[index].estoque > 0){
        printf("\n Digite quantos itens do produto %s foram vendidos: ", p[index].nome);
        scanf("%d", &aux);
        lb();
        while (aux < 0 || (p[index].estoque - aux < 0)){
            printf("\nVocê não pode estar devendo vendas ou ter vendido mais do que o há no estoque: %d", p[index].estoque);
            printf("\nDigite novamente: ");
            scanf("%d", &aux);
            lb();
        }
        v[index].quantidade = v[index].quantidade + aux;

        p[index].estoque -= aux;
        printf("O estoque deste produto agora é: %d", p[index].estoque);

        i=9;
        while (v[index].data[i][3] != '0' && v[index].data[i][3] != '1'){
            i--;
            if (i==0){
                break;
            }
        }
        printf("\n\nDigite a data da venda nesse formato: \nDia Mês Ano -> DD/MM/AAAA\n\t\tDigite: ");
        scanf("%[^\n]s", &v[index].data[i]);
        lb();
        printf("\n\n");

    }
    else{
        printf("\nnão é possível registrar a venda deste produto porque ele não tem estoque!");
        printf("\nedite o cadastro dele antes\n");
        sleep(3);
        system("pause");
    }
}

void EliminaCadastro(struct produtos *p, struct vendas *v, int *tam, int index){ //Elimina cadastro de um produto

    for(int cont = index; cont <= *tam; cont++){

        *p[cont].nome = *p[cont+1].nome;
        p[cont].codigo = p[cont+1].codigo;
        p[cont].preco = p[cont+1].preco;
        p[cont].estoque = p[cont+1].estoque;
        v[cont].quantidade = v[cont+1].quantidade;
        for(int j=0;j<10;j++){
            *v[cont].data[j] = *v[cont+1].data[j];
        }
    }
    (*tam)--;

}

void RelatorioRanking(struct produtos *p, struct vendas *v, int tam){ //Gera Relatório e Finaliza o programa para não alterar a ordem de inserção dos produtos e vendas
    system("CLS");

    FILE *relat;
    int i, aux;
    char res[3];

    for (i = 0; i < tam; i++){
        for(int k = i+1; k <= tam; k++){

            if (v[i].quantidade < v[k].quantidade){

                aux = v[i].quantidade;
                v[i].quantidade = v[k].quantidade;
                v[k].quantidade = aux;

                aux = p[i].nome;
                strcpy(p[i].nome, p[k].nome);
                strcpy(p[k].nome, aux);

                aux = p[i].codigo;
                p[i].codigo = p[k].codigo;
                p[k].codigo = aux;

                aux = p[i].preco;
                p[i].preco = p[k].preco;
                p[k].preco = aux;
            }
        }
    }
    printf("Ranking dos Produtos mais vendidos:\n\n");
    for(i = 0;i <= tam;i++){
        printf("\n%dº Lugar: \n", i+1);
        printf("  - PRODUTO: %s - VENDAS: %d - CÓDIGO: %d - LUCRO: %.2f\n", p[i].nome, v[i].quantidade, p[i].codigo, ((float)(v[i].quantidade) * (p[i].preco)));
    }

    lb();
    printf("\nAVISO: (Após a resposta, o programa será finalizado para a execução correta da função)");
    printf("\nDeseja criar um arquivo .txt do relatório na pasta original do programa? s/n: ");
    scanf("%[^\n]s", &res);
    lb();

    if (strcmp(res,"s") == 0){
        if ((relat = fopen("RelatórioRanking.txt", "w+")) == NULL){
            printf("\nErro na criação do arquivo!\n");
            system("pause");
        }
        for(i = 0;i <= tam;i++){
            fprintf(relat, "%dº Lugar: \n", i+1);
            fprintf(relat, "  - PRODUTO: %s - VENDAS: %d - CÓDIGO: %d - LUCRO: %.2f\n\n", p[i].nome, v[i].quantidade, p[i].codigo, ((float)(v[i].quantidade) * (p[i].preco)));
        }
        printf("\n\nProcessando o relatório...");
        sleep(1);
        printf("\n\t\t\tObrigado por utilizar o programa \n\n\t\t\t\t  Saindo...\n");
        sleep(3);
    }
    else{
        printf("\n\t\t\tObrigado por utilizar o programa \n\n\t\t\t\t  Saindo...\n");
        sleep(3);
    }


}

void RelatorioVendasP(struct produtos *p, struct vendas *v, int tam, int index){ //Gera Relatório de vendas do produto
    system("CLS");

    char res[3];
    FILE *relat;
    int k;

    printf("Relatório de Vendas: \n\nDados que serão gerados:\n");

    printf("\nProduto [%d]\n", index+1);
    printf("Nome: %s \nCódigo: %d \nPreço: R$ %.2f", p[index].nome, p[index].codigo, p[index].preco);
    printf("\nEstoque atual: %d\nLucro: R$ %.2f \n\n", p[index].estoque, ((float)(v[index].quantidade) * (p[index].preco)) );
    printf("\nQuantidade de vendas: %d \nData do último registro: %s \n\n", v[index].quantidade, v[index].data);

    printf("\nDeseja criar um arquivo .txt do relatório do produto na pasta original do programa? s/n: ");
    scanf("%[^\n]s", &res);
    lb();

    if (strcmp(res,"s") == 0){
        char nome[256] = {"RelatórioProduto - "};
        strcat(nome, p[index].nome);
        strcat(nome, ".txt");
        if ((relat = fopen(nome, "w+")) == NULL){
            printf("\nErro na criação do arquivo!\n");
            system("pause");
        }

        k = 9;
        while (v[index].data[k][3] != '0' && v[index].data[k][3] != '1'){
            k--;
            if (k==0){
                break;
            }
        }

        fprintf(relat, "Produto [%d]\n", index+1);
        fprintf(relat, "Nome: %s \nCódigo: %d \nPreço: R$ %.2f", p[index].nome, p[index].codigo, p[index].preco);
        fprintf(relat, "\nEstoque atual: %d\nLucro: %.2f \n\n", p[index].estoque, ((float)(v[index].quantidade) * (p[index].preco)) );
        fprintf(relat, "\nQuantidade de vendas: %d \nData do último registro: %s \n\n", v[index].quantidade, v[index].data[k]);

        printf("\n\nProcessando o relatório...");
        sleep(2);
        printf("\n\t\t\tSucesso!\n\nAVISO: (Encerre o programa pelo menu para a conclusão do processo)");
        sleep(4);
    }
}

void RelatorioVendasT(struct produtos *p, struct vendas *v, int tam){ //Gera um Relatório txt das vendas
    system("CLS");

    FILE *relat;
    char res[3];
    int i,k;
    int vendaT=0;
    float lucroT=0;


    printf("Relatório de Vendas Totais: \n\n[NOME, CODIGO] de pelo menos 1 e no máximo 10 dos últimos \nprodutos cadastrados que estarão do relatório:\n\n\t");

    for(i=tam;i>=(tam-10);i--){
        printf("[%s, %d] ",p[i].nome, p[i].codigo);
        if (i == 0){
            break;
        }
    }
    lb();
    printf("\n\nConfirmar a criação do arquivo: RelatórioVendasTotais.txt na pasta original do programa? s/n: ");
    scanf("%[^\n]s", &res);
    lb();

    if (strcmp(res,"s") == 0){

        if ((relat = fopen("RelatórioVendasTotais.txt", "w+")) == NULL){
            printf("\nErro na criação do arquivo!\n");
            system("pause");
        }

        for(i=0;i<=tam;i++){ //Loop p/ descobrir a venda e lucro total
            vendaT += v[i].quantidade;
            lucroT += (float)(v[i].quantidade) * (p[i].preco);
        }
        fprintf(relat,"RESUMO:\n   Vendas total: %d itens\n   Lucro total: R$ %.2f\n\n", vendaT, lucroT);

        for(i=0;i<=tam;i++){
            k=9;
            while (v[i].data[k][3] != '0' && v[i].data[k][3] != '1'){
                k--;
                if (k==0){
                    break;
                }
            }

            fprintf(relat, "Produto [%d]\n", i+1);
            fprintf(relat, "   Nome: %s \n   Código: %d \n   Preço: R$ %.2f", p[i].nome, p[i].codigo, p[i].preco);
            fprintf(relat, "\n   Estoque atual: %d\n   Lucro: R$ %.2f", p[i].estoque, ((float)(v[i].quantidade) * (p[i].preco)) );
            fprintf(relat, "\n   Quantidade de vendas: %d \n   Data do último registro: %s \n\n", v[i].quantidade, v[i].data[k]);
        }

        printf("\n\nProcessando o relatório...");
        sleep(2);
        printf("\n\t\t\tSucesso!\n\nAVISO: (Encerre o programa pelo menu para a conclusão do processo)");
        sleep(4);
    }

}

void RelatorioVendasM(struct produtos *p, struct vendas *v, int tam, char mes[11]){ //Gera um Relatório txt de vendas de um determinado mês do ano

    system("CLS");

    FILE *relat;
    char res[3];
    int i,j,k;
    int vendaT=0;
    float lucroT=0;

    printf("Relatório de Vendas do mês %s: \n\n[NOME, CODIGO] de pelo menos 1 e no máximo 10 dos últimos \nprodutos cadastrados no mês que estarão do relatório:\n\n\t", mes);

    for(i=tam;i>=0;i--){
        for(j=10;j>=0;j--){
            if (mes[0] == v[i].data[j][3] && mes[1] == v[i].data[j][4]){
            printf("[%s, %d] ",p[i].nome, p[i].codigo);

            }
        }
    }

    printf("\n\nConfirmar a criação do arquivo: RelatórioVendasMes.txt na pasta original do programa? s/n: ");
    scanf("%[^\n]s", &res);
    lb();

    if (strcmp(res,"s") == 0){

        if ((relat = fopen("RelatórioVendaMes.txt", "w+")) == NULL){
            printf("\nErro na criação do arquivo!\n");
            system("pause");
        }
        for(i=0;i<=tam;i++){for(int j=0; j <10;j++){if (mes[0] == v[i].data[j][3] && mes[1] == v[i].data[j][4]){ //Loop p/ descobrir a venda e lucro total
            k=9;
            while (v[i].data[k][3] != '0' && v[i].data[k][3] != '1'){
                k--;
                if (k==0){
                    break;
            }}
            vendaT += v[i].quantidade;
            lucroT += (float)(v[i].quantidade) * (p[i].preco);
        }}}
        fprintf(relat,"RESUMO DO MÊS %s:\n   Vendas total: %d itens\n   Lucro total: R$ %.2f\n\n",mes, vendaT, lucroT);

        for(i=0;i<=tam;i++){
            for(int j=0; j <10;j++){
                if (mes[0] == v[i].data[j][3] && mes[1] == v[i].data[j][4]){

                    k=9;
                    while (v[i].data[k][3] != '0' && v[i].data[k][3] != '1'){
                        k--;
                        if (k==0){
                            break;
                        }
                    }

                    fprintf(relat, "Produto [%d]\n", i+1);
                    fprintf(relat, "   Nome: %s \n   Código: %d \n   Preço: R$ %.2f", p[i].nome, p[i].codigo, p[i].preco);
                    fprintf(relat, "\n   Estoque atual: %d\n   Lucro: R$ %.2f", p[i].estoque, ((float)(v[i].quantidade) * (p[i].preco)) );
                    fprintf(relat, "\n   Quantidade de vendas: %d \n   Data do último registro: %s \n\n", v[i].quantidade, v[i].data[k]);
                    break;
                }
            }
        }

        printf("\n\nProcessando o relatório...");
        sleep(2);
        printf("\n\t\t\tSucesso!\n\nAVISO: (Encerre o programa pelo menu para a conclusão do processo)");
        sleep(4);
    }

}

void ListarProdutos(struct produtos *p, struct vendas *v, int tam){ //Lista produtos e quanto venderam até o momento
    int opt;
    system("CLS");

    int i;

    printf("\nDigite o número do produto que deseja ver mais\n");

    for(i=0; i < tam; i++){

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
        i=9;
        while (v[opt].data[i][3] != '0' && v[opt].data[i][3] != '1'){
            i--;
            if(i==0){
                break;
            }
        }
        printf("\nVendas totais: %d \nData: %s \n\n", v[opt].quantidade, v[opt].data[i]);
    }

    system("pause");

}

void EditaCadastro(struct produtos *p, struct vendas *v, int index){ //Edita cadastro e ou venda do produto
    system("CLS");
    int opt;
    int aux;
    int i;

    do{
        printf("Digite o número correspondente ao dado que deseja alterar do Produto %s:\n\n", p[index].nome);
        printf("1: NOME -- 2: CÓDIGO -- 3: PREÇO -- 4: ESTOQUE -- 5: Nº DE VENDAS -- 6: DATA -- 7: SAIR DA EDIÇÃO\n\n       Digite: ");
        scanf("%d", &opt);
        lb();

        switch(opt){
            case 1:
                printf("Nome atual cadastrado: %s - \nDigite o nome do produto: ", p[index].nome);
                scanf("%[^\n]s", &p[index].nome);
                lb();
                break;

            case 2:
                printf("\nCódigo atual cadastrado: %d - \nDigite o código do produto: ", p[index].codigo);
                scanf("%d", &p[index].codigo);
                lb();
                for(int j = 0; j < cont_prod; j++){
                    if (p[j].codigo == p[index].codigo){
                        while (p[j].codigo == p[index].codigo){
                            printf("\nEsse código já foi cadastrado antes, pertence ao produto %s", p[j].nome);
                            printf("\nCaso deseje alterar assim mesmo, é necessário alterar o código do produto  %s primeiro", p[j].nome);
                            printf("\ndigite qual codigo deseja manter: ");
                            scanf("%d", &p[index].codigo);
                            lb();
                        }
                    }
                }
                break;

            case 3:
                printf("\nPreço atual cadastrado: %.2f - \nDigite o preço do produto: ", p[index].preco);
                scanf("%f", &p[index].preco);
                lb();
                while(p[cont_prod].preco < 0){
                    printf("\nEsse preço não é válido");
                    printf("\ndigite novamente: ");
                    scanf("%f", &p[cont_prod].preco);
                    lb();
                }
                break;

            case 4:
                printf("\nEstoque atual cadastrado: %d - \nDigite o estoque do produto: ", p[index].estoque);
                scanf("%d", &p[index].estoque);
                lb();
                while(p[cont_prod].estoque < 0){
                    printf("\nEstoque invalido");
                    printf("\ndigite novamente: ");
                    scanf("%f", &p[cont_prod].estoque);
                    lb();
                }
                break;

            case 5:
                printf("\nNº de vendas atual registrado: %d - \nDigite o número de vendas a MAIS(+) ou a MENOS(-) do produto registrado anteriormente:", v[index].quantidade);
                printf("\n[EX:(+) 5 de 20 vendas = 15 vendas ; (-) -5 de 20 vendas = 25 vendas]");
                scanf("%d", &aux);
                lb();
                while (p[index].estoque - aux < 0){
                    printf("\nVocê não pode estar devendo vendas ou ter vendido mais do que o há no estoque: %d", p[index].estoque);
                    printf("\nDigite novamente: ");
                    scanf("%d", &aux);
                    lb();
                }
                v[index].quantidade = v[index].quantidade - aux;
                p[index].estoque += aux;
                printf("\n\nO estoque deste produto agora é: %d\n", p[index].estoque);
                break;

            case 6:
                i=9;
                while (v[index].data[i][3] != '0' && v[index].data[i][3] != '1'){
                    i--;
                    if (i==0){
                        break;
                    }
                }

                printf("\nData atual registrada: %s - \nDigite a data da venda do produto no formato: DD/MM/AAAA\n\t\tDigite: ", v[index].data[i]);
                scanf("%[^\n]s", &v[index].data[i]);
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

    for(int i = 0; i <= tam; i++){
        if (cod == p[i].codigo){
            return i;
        }
        else if (i == (tam)){
            printf("\nEsse produto não existe");
            sleep(2);
            return -1;
        }
    }
}

int BuscaMes(struct vendas *v, int tam, char mes[11]){ //retorna 1 se o mês buscado foi registrado

    for(int i = 0; i <= tam; i++){
        for(int j=0; j <10;j++){

            if (mes[0] == v[i].data[j][3] && mes[1] == v[i].data[j][4]){
                return 1;
                break;
            }
        }
    }
    printf("\nNenhuma venda foi registrada nesse mês\n");
    system("pause");
    return -1;
}
