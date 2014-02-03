#include <stdio.h>
#include <conio.h>

void main()
{
  int x, *p, **q;
  x = 10;
  p = &x;
  q = &p;
  printf("%d\n",**q);
  getch();
}