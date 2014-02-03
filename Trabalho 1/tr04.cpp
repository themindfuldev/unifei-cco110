#include <stdio.h>
#include <conio.h>

void main()
{
  // Variáveis
  int A[2], i;

  // Leitura
  printf("\n");
  for (i=0; i<2; i++)
  {
    printf("\tDigite o %do. valor: ", i+1);
    scanf("%d", &A[i]);
  }

  // Escrita
  for (i=0; i<2; i++)
    if (A[i]%2==0)
      printf("\n\t%d e par.", A[i]);
     else if (A[i]%2==1)
       printf("\n\t%d e impar.", A[i]);
  printf("\n");
  getch();
}