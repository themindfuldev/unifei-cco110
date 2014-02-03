#include <stdio.h>
#include <conio.h>

void main()
{
  // Variáveis
  int i;

  // Leitura, Calculo e Escrita
  printf("\n\t50 primeiros numeros impares:\n\t");

  for (i=1; i<100; i+=2)
  {
    printf("%d ", i);
  }

  printf("\n");
  getch();
}
