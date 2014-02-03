#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
  int i, n;
  float soma=0;
  do
  {
    clrscr();
    printf("\tEntre com o limite do somatorio [>0]: ");
    scanf("%d", &n);
    if (n<=0)
    {
      printf("\n\n\tDigite um valor positivo!\n\t[Pressione alguma tecla para continuar...]");
      getch();
    }
  }
  while (n<=0);
  for (i=1; i<=n+1; i++)
  {
    soma += 1/sqrt(i);
  }
  printf("\n\tResultado: %2.2f", soma);
  getch();
}