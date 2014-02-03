#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
  float a, b, c, d;
  printf("\tEntre com o valor de A: ");
  scanf("%f", &a);
  do
  {
    printf("\n\tEntre com o valor de B: ");
    scanf("%f", &b);
    if ((a-b)<0)
    {
      printf("\n\n\tDigite um valor menor ou igual a %2.2f!\n\t[Pressione alguma tecla para continuar...]\n", a);
      getch();
    }
  }
  while((a-b)<0);
  printf("\n\tEntre com o valor de C: ");
  scanf("%f", &c);
  do
  {
    printf("\n\tEntre com o valor de D: ");
    scanf("%f", &d);
    if ((c-d)==0)
    {
      printf("\n\n\tDigite um valor diferente de %2.2f!\n\t[Pressione alguma tecla para continuar...]\n", d);
      getch();
    }
  }
  while((c-d)==0);
  printf("\n\n\tResultado de (raiz quadrada de A-B) / (C-D): %2.2f", sqrt(a-b)/(c-d));
  getch();
}