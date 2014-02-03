#include <stdio.h>
#include <conio.h>

void main()
{
  int *p, *end, cont=100, val;
  end = &cont;       // obtem o endereço de cont
  val = *end;        // obtem o valor no endereço
  p = end;
  printf("\n\tVal: %d\n\tEndereco: %p\n", val, p);
  getch();
}