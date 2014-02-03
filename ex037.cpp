#include <stdio.h>
#include <conio.h>

void main()
{
  int *p, *end, cont, val;
  printf("\n\tCont: ");
  scanf("%d", &cont);
  end = &cont;       // obtem o endereço de cont
  val = *end;        // obtem o valor no endereço
  p = end;
  printf("\n\tVal: %d\n\tEndereco: %p\n", val, p);
  p++; printf("\n\tp++ - %p - %d", p, *p);
  (*p)++; printf("\n\t(*p)++ - %p - %d", p, *p);
  printf("\n\t*(p++) - %p - %d\n", ++p, *(++p));
  getch();
}