#include <stdio.h>
#include <conio.h>

void main()
{
  // Vari�veis
  int i=0, n=2, div;

  // C�lculo e Escrita
  printf("\n\t20 primeiros numeros primos:\n\t");
  do
  {
     for (div=2; n%div!=0; div++);
     if (div==n)
     {
       printf("%d ", n);
       i++;
     }
     n++;
  }
  while (i<20);
  printf("\n");
  getch();
}