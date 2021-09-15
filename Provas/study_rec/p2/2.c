#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int quantasvezes(char *S, char *A, char *B, int *contB) {
    int cont = 0;
    char *str;

    str = strstr(S, A);
    while (str != NULL) {
        cont++;
        str = strstr(str + 1, A);
    }

    str = strstr(S, B);
    while (str != NULL) {
        (*contB)++;
        str = strstr(str + 1, B);
    }
    return cont;
}

int main() {
    char S[50], A[50], B[50];
    int contA = 0, contB = 0;

/* FUNCIONA!
    scanf("%[^\n]s", S);
    setbuf(stdin, NULL);
    scanf("%s", A);
    setbuf(stdin, NULL);
    scanf("%s", B);
    setbuf(stdin, NULL);
*/

/* FUNCIONA Parcialmente (tem problemas [desconhecido])
    fgets(S, 50, stdin);
    S[strlen(S) - 1] = '\0';
    scanf("%s", A);
    setbuf(stdin, NULL); //Sempre limpar o buffer após um scanf caso a próxima leitura seja um fgets
    fgets(B, 50, stdin);
    B[strlen(B) - 1] = '\0';
*/

/* FUNCIONA! (porém não é indicado ler strings somente com scanf [segurança])
    scanf("%[^\n]s", S);
    scanf("%s", A);
    scanf("%s", B);
*/

/* NAO FUNCIONA!
    scanf("%s", S); //Se o scanf não for da forma: scanf("%[^\n]s", S); a leitura para no primeiro caractere especial ' '
    scanf("%s", A);
    scanf("%s", B);
*/

/* NAO FUNCIONA! (No RunCodes)
    fgets(S, 50, stdin);
    S[strlen(S) - 1] = '\0';
    setbuf(stdin, NULL);
    fgets(A, 50, stdin);
    A[strlen(A) - 1] = '\0';
    setbuf(stdin, NULL);
    fgets(B, 50, stdin);
    B[strlen(B) - 1] = '\0';
    setbuf(stdin, NULL);
*/

/* NAO FUNCIONA (No RunCodes)
    fgets(S, 50, stdin);
    S[strlen(S) - 1] = '\0';
    fgets(A, 50, stdin);
    A[strlen(A) - 1] = '\0';
    fgets(B, 50, stdin);
    B[strlen(B) - 1] = '\0';
*/
    fgets(S, 50, stdin);
    S[strlen(S) - 1] = '\0';
    scanf("%s", A);
    scanf("%s", B);

    contA = quantasvezes(S, A, B, &contB);

    printf("%d %d", contA, contB);

    return 0;
}
