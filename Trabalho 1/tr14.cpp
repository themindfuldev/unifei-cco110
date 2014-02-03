#include <stdio.h>
#include <conio.h>
#include <string.h>

void main()
{
  // Variáveis
  int i;
  char nome[9][30], troca[30];

  // Leitura
  printf("\n\tEntre com dez nomes, com no maximo 30 caracteres:\n\n");
  for(i=0; i<10; i++)
    do
    {
      printf("\tNome %d: ", i+1);
      gets(nome[i]);
      if (strlen(nome[i])>30)
      {
        printf("\n\tO nome deve ter no maximo 30 caracteres!\n\t[Pressione alguma tecla para continuar...]\n");
        getch();
      }
    }
    while (strlen(nome[i])>30);

  // Ordenacao do vetor
  for (i=0; i<9; i++)
    if (strcmp(nome[i], nome[i+1])>0)
    {
       strcpy(troca, nome[i]);
       strcpy(nome[i], nome[i+1]);
       strcpy(nome[i+1], troca);
       i = -1;
    }

  // Escrita
  printf("\n\tOrdem crescente:\n");
  for (i=0; i<10; i++)
    printf("\t%s\n", nome[i]);
  getch();
}
