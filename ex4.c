#include <stdio.h>
#include <string.h>

//Estou mandando novamente pois esqueci de dar close nos arquivos, agora está arrumado

int main(){
    FILE *arq1, *arq2;
    arq1 = fopen("arq1.txt", "r+");
    arq2 = fopen("arq2.txt", "r+");
    
    char palavrasJaImpressas[20][20];
    int localPalavraRepetida = 0;
    char palavra1[20];
    char palavra2[20];

    fseek(arq1,0,SEEK_SET);
    while(!feof(arq1)){
        fscanf(arq1, "%s", palavra1);
        fseek(arq2,0,SEEK_SET);
        while(!feof(arq2)){
            fscanf(arq2, "%s", palavra2);
            if(strcmp(palavra1,palavra2)==0){
                for(int i = 0; i < 20; i++){
                    if(strcmp(palavra2,palavrasJaImpressas[i])==0)
                        break;
                    if(i==19){
                        printf("%s ", palavra2);
                        strcpy(palavrasJaImpressas[localPalavraRepetida], palavra2);
                        localPalavraRepetida++;
                    }
                }
                break;
            }
        }
    }
    fclose(arq1);
    fclose(arq2);
}
