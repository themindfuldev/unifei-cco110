#include <stdio.h>
#include <conio.h>

void main()
{
  int n, i, par;
  do
  {
    printf("Quantos numeros pares deseja calcular? ");
    scanf("%d", &n);
    if (n <= 0)
      printf("Digite um numero positivo!\n\n");
  }
  while (n <= 0);
  i = 1;
  par = 0;
  while (i <= n)
  {
    printf("%d ", par);
    par = par+2;
    i = i+1;
  }
  printf("\n");
  getch(); // Espera que uma tecla seja acionada
}