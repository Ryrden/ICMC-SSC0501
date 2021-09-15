#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *arq;
    int cont = 0;

    if ((arq = fopen("texto.txt", "r")) == NULL) {
        printf("Erro de abertura\n");
        exit(0);
    }
    char palavraA[256], palavraB[256];

    scanf("%s", palavraA);
    scanf("%s", palavraB);

    char temp[256];
    while (fscanf(arq, "%s", temp) != EOF) {
        if (strcmp(temp, palavraA) == 0) {
            char temp2[256];
            if (fscanf(arq, "%s", temp2) != 1){
                break;
            }
            if (strcmp(palavraB, temp2) == 0) {
                cont++;
            } else {
                fseek(arq, -(strlen(temp2)), SEEK_CUR);
            }
        }
    }
    printf("%d", cont);

    fclose(arq);
    return 0;
}
