#include <stdio.h>
#include <conio.h>

void main()
{
  // Variáveis
  int i;
  float A[3], t;

  // Leitura
  printf("\n");
  for (i=0; i<3; i++)
  {
    printf("\tDigite o %do. valor: ", i+1);
    scanf("%f", &A[i]);
  }

  // Cálculo e escrita
  for (i=0; i<2; i++)
  {
    if (A[i+1]>A[i])
    {
      t = A[i];
      A[i] = A[i+1];
      A[i+1] = t;
      i = -1;
    }
  }
  
  printf("\n\n\tOrdem decrescente: %0.2f, %0.2f, %0.2f.\n", A[0], A[1], A[2]);
  getch();
}
