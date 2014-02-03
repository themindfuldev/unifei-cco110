#include <stdio.h>
#include <conio.h>

void main()
{
  // Variáveis
  int i, m, n, div;
  i = 0;
  n = 2;

  // Leitura
  do
  {
    printf("\n\tDigite o n-esimo numero primo: ");
    scanf("%d", &m);
    if (m<1)
    {
      printf("\n\tDigite um valor positivo!\n\t[Pressione alguma tecla para continuar...]\n\n");
      getch();
    }
  }
  while (m<1);

  // Calculo e Escrita
  printf("\n\tO %do. numero primo e: ", m);
  do
  {
     for (div=2; n%div!=0; div++);
     if (div==n)
     {
       if (i==m-1)
         printf("%d.\n", n);
       i++;
     }
     n++;
  }
  while (i<m);
  getch();
}