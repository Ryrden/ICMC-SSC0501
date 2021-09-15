#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    char nome[265];
    int nUSP;
    float media;

} aluno;

void Divide(aluno *a, aluno *aprovado, aluno *reprovado, int *n1, int *n2){

    int ap;
    int cont1=0;
    int cont2=0;

    for(int i=0;i<3;i++){
        if (a[i].media >= 5){
            ap++;
        }
    }

    *n1=ap;
    *n2=(3-ap);

    aprovado = (aluno*) calloc(*n1, sizeof(aluno));
    reprovado = (aluno*) calloc(*n2, sizeof(aluno));

    for(int i=0;i<3;i++){
        if (a[i].media >= 5){
            *aprovado[cont1].nome = *a[i].nome;
            printf("%s", aprovado[cont1].nome);
            aprovado[cont1].nUSP = a[i].nUSP;
            aprovado[cont1].media = a[i].media;
            cont1++;
        }
        else{
            *reprovado[cont2].nome = *a[i].nome;
            reprovado[cont2].nUSP = a[i].nUSP;
            reprovado[cont2].media = a[i].media;
            cont2++;
            printf("\nReprovados: \n\t %s, %d, %f", reprovado[cont2].nome, reprovado[cont2].nUSP, reprovado[cont2].media);
        }
    }

}

int main(){

    aluno a[3];
    aluno *aprovados;
    aluno *reprovados;
    int n1,n2;

    for(int i=0;i<3;i++){

        scanf("%[^\n]", a[i].nome);
        fflush(stdin);
        scanf("%d", &a[i].nUSP);
        fflush(stdin);
        scanf("%f", &a[i].media);
        printf("PROX\n");
        fflush(stdin);
    }

    Divide(a, aprovados, reprovados, &n1, &n2);

    for(int i=0; i<n1; i++){
        printf("Aprovados: \n\t %s, %d, %f\n", aprovados[i].nome, aprovados[i].nUSP, aprovados[i].media);
    }

    for(int i=0; i<n2; i++){
        printf("\nReprovados: \n\t %s, %d, %f", reprovados[i].nome, reprovados[i].nUSP, reprovados[i].media);
    }

    free(aprovados);
    free(reprovados);
    printf("\n\n");
    system("pause");
    return 0;
}
