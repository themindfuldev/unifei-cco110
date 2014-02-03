
/* Programa 11
   Objetivo: Exemplo D Sdnei - Apontadores e Arranjos de Estrutura
*/
#include <conio.h>
#include <stdio.h>
#include <string.h>

struct TAluno {
	char nome[30];
	int nota[3];
	float media;
};

const int max=10;

void main()
{
	TAluno Aluno[max], *p1, *p2;
	int k;
	// inicializa ponteiro
	p1 =  &Aluno[0];
	printf("\nDigite os dados dos alunos:");
	// le primeira matricula
	printf("\nNome (digite fim para terminar): ");
	scanf(" %[^\n]",p1->nome);
	while (strcmp(p1->nome,"fim")!=0) {
		printf("Digite as 3 notas do aluno:");
		for (k=0;k<3;k++) {
			scanf("%d",&p1->nota[k]);
		}
		p1++;
		// le proximo registro
		printf("\nNome (digite fim para terminar): ");
		scanf(" %[^\n]",p1->nome);
	}
	// guarda endereco final
	p2 = p1;
	// calcula media
	for (p1=&Aluno[0];p1!=p2;p1++) {
		p1->media = 0.;
		for (k=0;k<3;k++) {
			p1->media += p1->nota[k];
		}
		p1->media /= 3;
	}
	// imprime dados lidos e a media de cada aluno
	for (p1=&Aluno[0];p1!=p2;p1++) {
		printf("\nNome : %s",p1->nome);
		printf("\nNotas :");
	    for (k=0;k<3;k++) {
		   printf("\t%d",p1->nota[k]);
		}
	    printf("\nMedia: %5.2f",p1->media);
	}

	printf( "\n\nF I M");
	getch();
}
