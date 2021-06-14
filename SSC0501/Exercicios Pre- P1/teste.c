#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
 setlocale(LC_ALL, "");


 int main(){
	int anoi,anof;
	printf("\n insira o ano inicial");
	scanf("%u",&anoi);
	printf("insira o ano final");
	scanf("%u",&anof);
	while (anoi<=anof) {
		if(anoi % 4 == 0) {
			printf("%u é ano bissexto",anoi);
			anoi=anoi+1;
		}
		else if (anoi%4!=0) {
			anoi=anoi+1;
		}
	}

 printf("\n\n");
 system("pause");
 return 0;
}
