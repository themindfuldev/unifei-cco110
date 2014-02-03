#include <stdio.h>
#include <conio.h>

void main()
{
  // Variáveis
  int i;
  float a=1, b=0;

  // Leitura, Calculo e Escrita
  printf("\n\t20 primeiros numeros da serie:\n\t");

  for (i=0; i<20; i+=2)
  {
    a = a+b;
    printf("%0.0f ", a);
    b = a+b;
    printf("%0.0f ", b);
  }

  printf("\n");
  getch();
}