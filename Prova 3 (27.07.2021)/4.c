#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *arq1, *arq2;
    char s[256];
    char r[256];

    if ((arq1 = fopen("arq1.txt", "r")) == NULL){
        printf("\nErro de abertura");
        exit(0);
    }
    if ((arq2 = fopen("arq2.txt", "r")) == NULL){
        printf("\nErro de abertura");
        exit(0);
    }

    while(feof(arq1) == 0){
        fscanf(arq1,"%s",s);
        fseek(arq2,0,SEEK_SET);

        while(feof(arq2) == 0){
            fscanf(arq2,"%s",r);

            if (strcmp(r,s)==0){
                printf("%s ",s);
            }
        }

    }

    fclose (arq1);
    fclose (arq2);
    return 0;
}
