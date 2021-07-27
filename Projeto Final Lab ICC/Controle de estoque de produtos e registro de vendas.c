#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*INFORMA��ES:

    NOME: Ryan Souza S� Teles
    nUSP: 12822062
    Turma: BSI [021]
    Instituto: Instituto de Ci�ncias Matem�ticas e de Computa��o
    Disciplina: Introdu��o a Ci�ncia da Computa��o I
    Professor: Dennis Wolf
*/


struct produtos{

    char nome[256];
    int codigo;
    float preco;
    int estoque;

};

struct vendas{

    //int codigo; esta vari�vel n�o est� sendo utilizada porque o c�digo dela � o mesmo do produto,
    int quantidade;
    char data[11][10]; // formato: DD/MM/AAAA; limite: 10 vendas por item, a ultima sobrep�e
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

//Variaveis globais para contagem ap�s finaliza��o do programa;
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
                printf("\nVoc� n�o pode registrar uma venda sem cadastrar um produto antes!\n\n");
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
                printf("A lista est� vazia! \nCadastre algum produto e sua respectiva venda antes.\n\n");
                system("pause");
                break;
            }
            else{
                ListarProdutos(p, v, cont_prod+1);
                break;
            }

        case 4: //Editar cadastro
            if (cont_prod == -1){
                printf("\nVoc� n�o pode editar uma cadastro sem cadastrar um produto antes!\n\n");
                system("pause");
                break;
            }
            printf("\nQual produto voc� deseja alterar os dados?\n");
            opt = BuscaProduto(p, cont_prod);
            if (opt == -1){break;}

            EditaCadastro(p, v, opt);
            printf("Novos dados do produto: \n\n");
            ListaTodosDados(opt, p, v);
            system("pause");
            break;

        case 5: //Eliminar cadastro
            if (cont_prod == -1){
                printf("\nVoc� n�o pode eliminar um cadastro sem cadastrar um produto antes!\n\n");
                system("pause");
                break;
            }else{
                printf("\nQual produto voc� deseja eliminar do cadastro?\n");
                opt = BuscaProduto(p, cont_prod);
                if (opt == -1){break;}

                EliminaCadastro(p, v, &cont_prod, opt);
                printf("\nSucesso...Salve e Feche o programa para que as altera��es sejam feitas\n");
                sleep(1,5);
                system("pause");
                break;
            }

        case 6: //Relatorio de vendas total
            if (cont_prod == -1){
                printf("\nVoc� n�o pode gerar um relat�rio das vendas sem o cadastrar ao menos um produto antes!\n\n");
                system("pause");
                break;
            }
            else{

                RelatorioVendasT(p, v, cont_prod);
                break;
            }

        case 7: //relatorio de vendas de um determinado produto
            if (cont_prod == -1){
                printf("\nVoc� n�o pode gerar um relat�rio de vendas de um produto sem o cadastrar antes!\n\n");
                system("pause");
                break;
            }
            else{
                printf("\nQual produto voc� deseja gerar um relat�rio?\n");
                opt = BuscaProduto(p, cont_prod);
                if (opt == -1){break;}

                RelatorioVendasP(p, v, cont_prod, opt);
                break;
            }

        case 8: //ranking do produto mais vendido
            if (cont_prod <= 0){
                printf("\nVoc� n�o pode gerar um relat�rio de ranking dos produto mais vendidos sem ter cadastrado ao menos DOIS produtos antes!\n\n");
                system("pause");
                break;
            }
            else{

            RelatorioRanking(p, v, cont_prod);
            return 0;
            break;
            }

        case 9: //Relat�rio de Vendas no M�s especifico
            if (cont_prod == -1){
                printf("\nVoc� n�o pode gerar um relat�rio de vendas no m�s sem ter cadastrado ao menos dois produtos antes!\n\n");
                system("pause");
                break;
            }
            else{
                printf("Digite o n�mero do m�s e o ano no formato: \nM�s  -> MM\n\t\tDigite: ");
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
            printf("\nOp��o inv�lida \n\n");
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

void SalvarAlteracoes(FILE *arq, struct produtos *p, struct vendas *v, int *cont_prod){ //Salvar altera��es

    fseek(arq,0,SEEK_SET);
    fwrite(cont_prod, sizeof(int), 1, arq);
    fwrite(p, sizeof(struct produtos), (1000), arq);
    fwrite(v, sizeof(struct vendas), (1000), arq);

    printf("Salvando...");
    sleep(1);
}

void menu(){ //Menu com op��es

    system("CLS");
    printf("=-=-=-=-=-=-=-=-=-=CONTROLE DE ESTOQUE PRODUTOS E REGISTRO DE VENDAS=-=-=-=-=-=-=-=-=-=");
    printf("\n\nDigite o n�mero que tem respeito a op��o desejada:\n\n");
    printf("1: Cadastrar um ou mais produtos\n");
    printf("2: Registrar vendas de um produto(*)\n");
    printf("3: Listar todos os produtos\n");
    printf("4: Editar cadastro ou registro de venda de um produto(*)\n");
    printf("5: Eliminar cadastro de um produto(*)\n");
    printf("6: Gerar Relat�rio de vendas total\n");
    printf("7: Gerar Relat�rio de vendas de um determinado produto(*)\n");
    printf("8: Gerar Relat�rio de ranking de produtos mais vendidos[FPAE](*)\n");
    printf("9: Gerar Relat�rio de vendas de um determinado m�s\n");
    printf("10: Salvar Altera��es e Sair do programa\n\n");
    printf("\t\t\t[FPAE]: Ap�s a execu��o, finaliza o programa SEM SALVAR altera��es feitas antes (CUIDADO)\n");
    printf("\t\t\t   (*): Necess�rio o c�digo do produto \n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\n       Digite: ");

}

void ListaTodosDados(int opt, struct produtos *p, struct vendas *v){ //Lista nome, c�digo, pre�o, estoque, vendas e data da venda

    printf("\nProduto [%d]\n", opt+1);
    printf("Nome: %s \nC�digo: %d \nPre�o: R$ %.2f", p[opt].nome, p[opt].codigo, p[opt].preco);
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

void CadastraProduto(struct produtos *p){ //cadastra nome, c�digo, pre�o e estoque de um ou mais produtos

    system("CLS");
    int tam;
    int j;

    printf("Quantos produtos voc� deseja cadastrar?: ");
    scanf("%d", &tam);
    lb();

    for(int i=0; i < tam;i++){
        system("CLS");

        cont_prod++;
        printf("Produtos cadastrados: %d/%d\n", i+1, tam);

        printf("\nNome do produto %d: ", cont_prod+1);
        scanf("%[^\n]s", &p[cont_prod].nome);
        lb();

        printf("\nC�digo do produto %d (n�mero): ", cont_prod+1);
        scanf("%d", &p[cont_prod].codigo);
        lb();
        for(j = 0; j < cont_prod; j++){
            while(p[j].codigo == p[cont_prod].codigo || p[cont_prod].codigo < 0){
                printf("\nEsse c�digo j� foi cadastrado antes ou � inv�lido");
                printf("\ndigite novamente: ");
                scanf("%d", &p[cont_prod].codigo);
                lb();
            }
        }

        printf("\nPre�o do produto %d: R$ ", cont_prod+1);
        scanf("%f", &p[cont_prod].preco);
        lb();
        while(p[cont_prod].preco < 0){
            printf("\nEsse pre�o n�o � v�lido");
            printf("\ndigite novamente: ");
            scanf("%f", &p[cont_prod].preco);
            lb();
        }

        printf("\nEstoque do produto %d: ", cont_prod+1);
        scanf("%d", &p[cont_prod].estoque);
        lb();
        while(p[cont_prod].estoque < 0){
            printf("\nEstoque inv�lido");
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
            printf("\nVoc� n�o pode estar devendo vendas ou ter vendido mais do que o h� no estoque: %d", p[index].estoque);
            printf("\nDigite novamente: ");
            scanf("%d", &aux);
            lb();
        }
        v[index].quantidade = v[index].quantidade + aux;

        p[index].estoque -= aux;
        printf("O estoque deste produto agora �: %d", p[index].estoque);

        i=9;
        while (v[index].data[i][3] != '0' && v[index].data[i][3] != '1'){
            i--;
            if (i==0){
                break;
            }
        }
        printf("\n\nDigite a data da venda nesse formato: \nDia M�s Ano -> DD/MM/AAAA\n\t\tDigite: ");
        scanf("%[^\n]s", &v[index].data[i]);
        lb();
        printf("\n\n");

    }
    else{
        printf("\nn�o � poss�vel registrar a venda deste produto porque ele n�o tem estoque!");
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

void RelatorioRanking(struct produtos *p, struct vendas *v, int tam){ //Gera Relat�rio e Finaliza o programa para n�o alterar a ordem de inser��o dos produtos e vendas
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
        printf("\n%d� Lugar: \n", i+1);
        printf("  - PRODUTO: %s - VENDAS: %d - C�DIGO: %d - LUCRO: %.2f\n", p[i].nome, v[i].quantidade, p[i].codigo, ((float)(v[i].quantidade) * (p[i].preco)));
    }

    lb();
    printf("\nAVISO: (Ap�s a resposta, o programa ser� finalizado para a execu��o correta da fun��o)");
    printf("\nDeseja criar um arquivo .txt do relat�rio na pasta original do programa? s/n: ");
    scanf("%[^\n]s", &res);
    lb();

    if (strcmp(res,"s") == 0){
        if ((relat = fopen("Relat�rioRanking.txt", "w+")) == NULL){
            printf("\nErro na cria��o do arquivo!\n");
            system("pause");
        }
        for(i = 0;i <= tam;i++){
            fprintf(relat, "%d� Lugar: \n", i+1);
            fprintf(relat, "  - PRODUTO: %s - VENDAS: %d - C�DIGO: %d - LUCRO: %.2f\n\n", p[i].nome, v[i].quantidade, p[i].codigo, ((float)(v[i].quantidade) * (p[i].preco)));
        }
        printf("\n\nProcessando o relat�rio...");
        sleep(1);
        printf("\n\t\t\tObrigado por utilizar o programa \n\n\t\t\t\t  Saindo...\n");
        sleep(3);
    }
    else{
        printf("\n\t\t\tObrigado por utilizar o programa \n\n\t\t\t\t  Saindo...\n");
        sleep(3);
    }


}

void RelatorioVendasP(struct produtos *p, struct vendas *v, int tam, int index){ //Gera Relat�rio de vendas do produto
    system("CLS");

    char res[3];
    FILE *relat;
    int k;

    printf("Relat�rio de Vendas: \n\nDados que ser�o gerados:\n");

    printf("\nProduto [%d]\n", index+1);
    printf("Nome: %s \nC�digo: %d \nPre�o: R$ %.2f", p[index].nome, p[index].codigo, p[index].preco);
    printf("\nEstoque atual: %d\nLucro: R$ %.2f \n\n", p[index].estoque, ((float)(v[index].quantidade) * (p[index].preco)) );
    printf("\nQuantidade de vendas: %d \nData do �ltimo registro: %s \n\n", v[index].quantidade, v[index].data);

    printf("\nDeseja criar um arquivo .txt do relat�rio do produto na pasta original do programa? s/n: ");
    scanf("%[^\n]s", &res);
    lb();

    if (strcmp(res,"s") == 0){
        char nome[256] = {"Relat�rioProduto - "};
        strcat(nome, p[index].nome);
        strcat(nome, ".txt");
        if ((relat = fopen(nome, "w+")) == NULL){
            printf("\nErro na cria��o do arquivo!\n");
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
        fprintf(relat, "Nome: %s \nC�digo: %d \nPre�o: R$ %.2f", p[index].nome, p[index].codigo, p[index].preco);
        fprintf(relat, "\nEstoque atual: %d\nLucro: %.2f \n\n", p[index].estoque, ((float)(v[index].quantidade) * (p[index].preco)) );
        fprintf(relat, "\nQuantidade de vendas: %d \nData do �ltimo registro: %s \n\n", v[index].quantidade, v[index].data[k]);

        printf("\n\nProcessando o relat�rio...");
        sleep(2);
        printf("\n\t\t\tSucesso!\n\nAVISO: (Encerre o programa pelo menu para a conclus�o do processo)");
        sleep(4);
    }
}

void RelatorioVendasT(struct produtos *p, struct vendas *v, int tam){ //Gera um Relat�rio txt das vendas
    system("CLS");

    FILE *relat;
    char res[3];
    int i,k;
    int vendaT=0;
    float lucroT=0;


    printf("Relat�rio de Vendas Totais: \n\n[NOME, CODIGO] de pelo menos 1 e no m�ximo 10 dos �ltimos \nprodutos cadastrados que estar�o do relat�rio:\n\n\t");

    for(i=tam;i>=(tam-10);i--){
        printf("[%s, %d] ",p[i].nome, p[i].codigo);
        if (i == 0){
            break;
        }
    }
    lb();
    printf("\n\nConfirmar a cria��o do arquivo: Relat�rioVendasTotais.txt na pasta original do programa? s/n: ");
    scanf("%[^\n]s", &res);
    lb();

    if (strcmp(res,"s") == 0){

        if ((relat = fopen("Relat�rioVendasTotais.txt", "w+")) == NULL){
            printf("\nErro na cria��o do arquivo!\n");
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
            fprintf(relat, "   Nome: %s \n   C�digo: %d \n   Pre�o: R$ %.2f", p[i].nome, p[i].codigo, p[i].preco);
            fprintf(relat, "\n   Estoque atual: %d\n   Lucro: R$ %.2f", p[i].estoque, ((float)(v[i].quantidade) * (p[i].preco)) );
            fprintf(relat, "\n   Quantidade de vendas: %d \n   Data do �ltimo registro: %s \n\n", v[i].quantidade, v[i].data[k]);
        }

        printf("\n\nProcessando o relat�rio...");
        sleep(2);
        printf("\n\t\t\tSucesso!\n\nAVISO: (Encerre o programa pelo menu para a conclus�o do processo)");
        sleep(4);
    }

}

void RelatorioVendasM(struct produtos *p, struct vendas *v, int tam, char mes[11]){ //Gera um Relat�rio txt de vendas de um determinado m�s do ano

    system("CLS");

    FILE *relat;
    char res[3];
    int i,j,k;
    int vendaT=0;
    float lucroT=0;

    printf("Relat�rio de Vendas do m�s %s: \n\n[NOME, CODIGO] de pelo menos 1 e no m�ximo 10 dos �ltimos \nprodutos cadastrados no m�s que estar�o do relat�rio:\n\n\t", mes);

    for(i=tam;i>=0;i--){
        for(j=10;j>=0;j--){
            if (mes[0] == v[i].data[j][3] && mes[1] == v[i].data[j][4]){
            printf("[%s, %d] ",p[i].nome, p[i].codigo);

            }
        }
    }

    printf("\n\nConfirmar a cria��o do arquivo: Relat�rioVendasMes.txt na pasta original do programa? s/n: ");
    scanf("%[^\n]s", &res);
    lb();

    if (strcmp(res,"s") == 0){

        if ((relat = fopen("Relat�rioVendaMes.txt", "w+")) == NULL){
            printf("\nErro na cria��o do arquivo!\n");
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
        fprintf(relat,"RESUMO DO M�S %s:\n   Vendas total: %d itens\n   Lucro total: R$ %.2f\n\n",mes, vendaT, lucroT);

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
                    fprintf(relat, "   Nome: %s \n   C�digo: %d \n   Pre�o: R$ %.2f", p[i].nome, p[i].codigo, p[i].preco);
                    fprintf(relat, "\n   Estoque atual: %d\n   Lucro: R$ %.2f", p[i].estoque, ((float)(v[i].quantidade) * (p[i].preco)) );
                    fprintf(relat, "\n   Quantidade de vendas: %d \n   Data do �ltimo registro: %s \n\n", v[i].quantidade, v[i].data[k]);
                    break;
                }
            }
        }

        printf("\n\nProcessando o relat�rio...");
        sleep(2);
        printf("\n\t\t\tSucesso!\n\nAVISO: (Encerre o programa pelo menu para a conclus�o do processo)");
        sleep(4);
    }

}

void ListarProdutos(struct produtos *p, struct vendas *v, int tam){ //Lista produtos e quanto venderam at� o momento
    int opt;
    system("CLS");

    int i;

    printf("\nDigite o n�mero do produto que deseja ver mais\n");

    for(i=0; i < tam; i++){

        printf("\nProduto [%d]\n", (i+1));
        printf("Nome: %s -- C�digo: %d\n", p[i].nome, p[i].codigo);
    }


    printf("\n\nDigite: ");
    scanf("%d", &opt);

    while(opt < 0 || opt > tam){
        printf("\nproduto n�o existe!!\n");
        printf("Digite novamente: ");
        scanf("%d", &opt);

    }
    printf("\nProduto [%d]\n", opt);
    opt--;
    printf("Nome: %s \nC�digo: %d \nPre�o: R$ %.2f", p[opt].nome, p[opt].codigo, p[opt].preco);
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
        printf("Digite o n�mero correspondente ao dado que deseja alterar do Produto %s:\n\n", p[index].nome);
        printf("1: NOME -- 2: C�DIGO -- 3: PRE�O -- 4: ESTOQUE -- 5: N� DE VENDAS -- 6: DATA -- 7: SAIR DA EDI��O\n\n       Digite: ");
        scanf("%d", &opt);
        lb();

        switch(opt){
            case 1:
                printf("Nome atual cadastrado: %s - \nDigite o nome do produto: ", p[index].nome);
                scanf("%[^\n]s", &p[index].nome);
                lb();
                break;

            case 2:
                printf("\nC�digo atual cadastrado: %d - \nDigite o c�digo do produto: ", p[index].codigo);
                scanf("%d", &p[index].codigo);
                lb();
                for(int j = 0; j < cont_prod; j++){
                    if (p[j].codigo == p[index].codigo){
                        while (p[j].codigo == p[index].codigo){
                            printf("\nEsse c�digo j� foi cadastrado antes, pertence ao produto %s", p[j].nome);
                            printf("\nCaso deseje alterar assim mesmo, � necess�rio alterar o c�digo do produto  %s primeiro", p[j].nome);
                            printf("\ndigite qual codigo deseja manter: ");
                            scanf("%d", &p[index].codigo);
                            lb();
                        }
                    }
                }
                break;

            case 3:
                printf("\nPre�o atual cadastrado: %.2f - \nDigite o pre�o do produto: ", p[index].preco);
                scanf("%f", &p[index].preco);
                lb();
                while(p[cont_prod].preco < 0){
                    printf("\nEsse pre�o n�o � v�lido");
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
                printf("\nN� de vendas atual registrado: %d - \nDigite o n�mero de vendas a MAIS(+) ou a MENOS(-) do produto registrado anteriormente:", v[index].quantidade);
                printf("\n[EX:(+) 5 de 20 vendas = 15 vendas ; (-) -5 de 20 vendas = 25 vendas]");
                scanf("%d", &aux);
                lb();
                while (p[index].estoque - aux < 0){
                    printf("\nVoc� n�o pode estar devendo vendas ou ter vendido mais do que o h� no estoque: %d", p[index].estoque);
                    printf("\nDigite novamente: ");
                    scanf("%d", &aux);
                    lb();
                }
                v[index].quantidade = v[index].quantidade - aux;
                p[index].estoque += aux;
                printf("\n\nO estoque deste produto agora �: %d\n", p[index].estoque);
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
                printf("op��o inv�lida, digite novamente");
                sleep(1);
                break;
        }
    }while(opt != 7);
}

int BuscaProduto(struct produtos *p, int tam){ //retorna posi��o do vetor na qual o produto est�

    int cod;
    printf("Digite o c�digo do produto: ");
    scanf("%d", &cod);
    lb();

    for(int i = 0; i <= tam; i++){
        if (cod == p[i].codigo){
            return i;
        }
        else if (i == (tam)){
            printf("\nEsse produto n�o existe");
            sleep(2);
            return -1;
        }
    }
}

int BuscaMes(struct vendas *v, int tam, char mes[11]){ //retorna 1 se o m�s buscado foi registrado

    for(int i = 0; i <= tam; i++){
        for(int j=0; j <10;j++){

            if (mes[0] == v[i].data[j][3] && mes[1] == v[i].data[j][4]){
                return 1;
                break;
            }
        }
    }
    printf("\nNenhuma venda foi registrada nesse m�s\n");
    system("pause");
    return -1;
}
