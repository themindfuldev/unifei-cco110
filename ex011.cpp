#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
  int i, j, n;
  float soma=0,k;
  do
  {
    clrscr();
    printf("\tEntre com o limite do somatorio [>0]: ");
    scanf("%d", &n);
    if (n<1)
    {
      printf("\n\n\tDigite um valor positivo e maior que 0!\n\t[Pressione alguma tecla para continuar...]");
      getch();
    }
  }
  while (n<1);
  for (i=1; i<=n; i++)
  {
    k = 1;
    for (j=1; j<=i; j++)
      k = k*i;
    soma += 1/k;
  }
  printf("\n\tResultado: %2.2f", soma);
  getch();
}