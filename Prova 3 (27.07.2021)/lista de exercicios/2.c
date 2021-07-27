#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct aluno{

    char nome[265];
    int nUSP;
    float media;

};

void Divide(struct aluno *a, struct aluno *aprovado, struct aluno *reprovado, int *n1, int *n2){

    int ap;
    int cont1=0;
    int cont2=0;

    for(int i=0;i<10;i++){
        if (a[i].media >= 5){
            ap++;
        }
    }

    n1=ap;
    n2=(10-ap);

    aprovado = (struct aluno*) malloc(ap * sizeof(struct aluno));
    reprovado = (struct aluno*) malloc((10-ap) * sizeof(struct aluno));

    for(int i=0;i<10;i++){
        if (a[i].media >= 5){
            strcpy(aprovado[cont1].nome,a[i].nome);
            aprovado[cont1].nUSP = a[i].nUSP;
            aprovado[cont1].media = a[i].media;
            cont1++;
        }
        else{
            strcpy(reprovado[cont2].nome,a[i].nome);
            reprovado[cont2].nUSP = a[i].nUSP;
            reprovado[cont2].media = a[i].media;
            cont2++;
        }
    }

}

int main(){
    setlocale(LC_ALL, "");

    struct aluno a[10];
    struct aluno *aprovados;
    struct aluno *reprovados;
    int n1,n2;

    for(int i=0;i<10;i++){

        scanf("%[^\n]s", &a[i].nome);
        fflush(stdin);
        scanf("%d", &a[i].nUSP);
        fflush(stdin);
        scanf("%f", &a[i].media);
        fflush(stdin);
        printf("PROX\n");
    }

    Divide(a,aprovados, reprovados, &n1,&n2);

    for(int i=0;i<n1;i++){
        printf("Aprovado: \n\t%s, %d, %f\n", aprovados[i].nome, aprovados[i].nUSP, aprovados[i].media);
    }

    for(int i=0;i<n1;i++){
        printf("\nReprovados: \n\t%s, %d, %f", reprovados[i].nome, reprovados[i].nUSP, reprovados[i].media);
    }



    free(aprovados);
    free(reprovados);
    printf("\n\n");
    system("pause");
    return 0;
}
