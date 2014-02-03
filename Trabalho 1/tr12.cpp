#include <stdio.h>
#include <conio.h>

void main()
{
  // Variáveis
  int i, n, a=1;

  // Leitura
  do
  {
    printf("\n\tDigite o n-esimo numero impar: ");
    scanf("%d", &n);
    if (n<1)
    {
      printf("\n\tDigite um valor positivo!\n\t[Pressione alguma tecla para continuar...]\n\n");
      getch();
    }
  }
  while (n<1);

  // Calculo e Escrita
  for (i=1; i<n; i++)
    a += 2;

  printf("\n\tO %do. numero impar e: %d.\n", n, a);
  getch();
}
