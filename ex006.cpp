#include <stdio.h>
#include <conio.h>

void main()
{
  int i, n;
  float a, b, c;
  do
  {
    printf("Quantos numeros deseja calcular? ");
    scanf("%d", &n);
    if (n <= 0)
      printf("Digite um numero positivo!\n\n");
  }
  while (n <= 0);
  a = 1;
  b = 2;
  i = 1;
  while (i <= n)
  {
    printf("%0.0f ", a);
    c = (a*b)+1;
    a = b;
    b = c;
    i++;
  }
  printf("\n");
  getch();
}