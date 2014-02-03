#include <stdio.h>
#include <conio.h>

void main()
{
  int i, n;
  float a, b;
  do
  {
    printf("Quantos numeros deseja calcular? ");
    scanf("%d", &n);
    if (n <= 0)
      printf("Digite um numero positivo!\n\n");
  }
  while (n <= 0);
  a = 2;
  b = 1;
  i = 1;
  printf("1 ");
  while (i <= n)
  {
    b = (a*b)+1;
    printf("%0.0f ", a);
    a = (a*b)+1;
    printf("%0.0f ", b);
    i += 2;
  }
  printf("\n");  
  getch();
}