#include <stdio.h>
#include <conio.h>

void main()
{
  int *end, cont=100, val;
  end = &cont;    // obtem o endereço de cont
  val = *end;     // obtem o valor no endereço
  printf("%d", val);
  getch();
}