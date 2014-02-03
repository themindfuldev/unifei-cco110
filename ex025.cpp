#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
  // Variaveis
  int i, n;
  float s[100], p[100], ts=0.5, tp=1;

  // Entrada
  do
  {
    clrscr();
    printf("\n\tQuantos termos deseja calcular? ");
    scanf("%d", &n);
    if ((n<=0)||(n>100))
    {
      printf("\n\n\tDigite um valor positivo e menor ou igual a 100!\n\t[Pressione qualquer tecla para continuar...]\n");
      getch();
    }
  }
  while ((n<=0)||(n>100));
  for (i=1; i<n; i++)
  {
    s[i] = pow(i,2)/(1-n);
    ts += s[i];
  }
  for (i=1; i<n; i++)
  {
    p[i] = sqrt(i)/pow(i,2);
    tp *= p[i];
  }

  // Saida
  printf("\n\n\tS = ");
  for (i=1; i<n; i++)
  {
    printf("%2.2f ", s[i]);
    if ((i<n-1)&&(s[i]>0))
    {
      printf("+");
    }
  }
  printf("= %2.2f\n\n\tP = ", ts);
  for (i=1; i<n; i++)
  {
    printf("%2.2f ", p[i]);
    if ((i<n-1)&&(p[i]>0))
    {
      printf("+");
    }
  }
  printf("= %2.2f\n", tp);
  getch();
}