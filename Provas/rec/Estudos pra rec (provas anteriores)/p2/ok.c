#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct filme {
	char nome[20];
	int avaliacao;
	int ano;
	};

int main() {
struct filme v[5]={
		{"Filme A", 6, 2001},
		{"Filmx B", 2, 2001},
		{"Filmx C", 7, 1999},
		{"Filme D", 6, 1999},
		{"Filme E", 8, 2001},
	};
int i;
FILE *f;

f=fopen("filmes.dat", "wb+");

fwrite(v, sizeof(struct filme), 5, f);

fclose(f);
}