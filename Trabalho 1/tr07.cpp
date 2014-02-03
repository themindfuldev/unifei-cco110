#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
  // Variáveis
  float a, res;

  // Leitura
  do
  {
    clrscr();
    printf("\n\tDigite um x para a funcao y2=(1-x), D={xeR|x<=1}: ");
    scanf("%f", &a);
    if (a>1)
    {
      printf("\n\tDigite um valor dentro do dominio da funcao!\n\t[Pressione alguma tecla para continuar...]\n\n");
      getch();
    }
  }
  while (a>1);

  // Cálculo e Escrita
  res = sqrt(1-a);
  
  printf("\n\tO resultado e y = %0.0f.\n", res);
  getch();
}