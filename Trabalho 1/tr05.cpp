#include <stdio.h>
#include <conio.h>

void main()
{
  // Variáveis
  int a;

  // Leitura e Escrita
  printf("\n\tDigite o numero: ");
  scanf("%d", &a);

  if (a>0)
    printf("\n\t%d e positivo.\n", a);
   else if (a<0)
     printf("\n\t%d e negativo.\n", a);
   else if (a==0)
     printf("\n\t%d e zero.\n", a);
  getch();
}