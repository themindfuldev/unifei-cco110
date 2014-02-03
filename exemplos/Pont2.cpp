#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main()
{
  int x, *px;
  clrscr();
  printf ("Digite um numero inteiro: ");
  scanf ("%i",&x);
  px = &x;
  printf(" A conteudo da variavel px e o endereco de x........: %li \n", px);
  printf(" O conteudo do endereco de memoria onde esta x e....: %i  \n",*px);
  printf(" O endereco de memoria onde esta px e...............: %li \n",&px);
  printf(" O conteudo da variavel x...........................: %i  \n",  x);
  printf(" O endereco de memoria da variavel x e..............: %li \n", &x);

  getch();
}
