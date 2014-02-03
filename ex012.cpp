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
    printf("\tEntre com o limite do somatorio [>1]: ");
    scanf("%d", &n);
    if (n<2)
    {
      printf("\n\n\tDigite um valor positivo e maior que 1!\n\t[Pressione alguma tecla para continuar...]");
      getch();
    }
  }
  while (n<2);
  for (i=1; i<n; i++)
  {
    soma += sqrt(i)/(i-n);
  }
  printf("\n\tResultado: %2.2f", soma);
  getch();
}