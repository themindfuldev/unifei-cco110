#include <stdio.h>
#include <conio.h>

void main()
{
  int *end, cont=100, val;
  end = &cont;    // obtem o endere�o de cont
  val = *end;     // obtem o valor no endere�o
  printf("%d", val);
  getch();
}