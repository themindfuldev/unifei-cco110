#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main()
{
  int x, *p1, *p2;
  clrscr();
  p1 = &x;
  p2 = p1;
  printf ("O endereco de x e: %p\t e seu valor: %d\n",p2,x);
  getch();
}
