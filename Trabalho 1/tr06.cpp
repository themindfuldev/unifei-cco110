#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
  // Vari�veis
  float a, res;

  // Leitura, C�lculo e Escrita
  printf("\n\tDigite um x para a funcao y=3x2+2x-6, D=R: ");
  scanf("%f", &a);

  res = (3*pow(a,2))+(2*a)-6;

  printf("\n\tO resultado e y = %0.0f.\n", res);
  getch();
}