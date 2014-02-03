#include <stdio.h>
#include <conio.h>

int fac(int n)
{
  int resp;
  if (n==1)
    return(1);
  resp = fac(n-1)*n;
  return(resp);
}

void main()
{
  int num, fatorial;
  printf("\n\tEntre com um numero: ");
  scanf("%d", &num);
  fatorial = fac(num);
  printf("\n\tO fatorial de %d e %d", num, fatorial);
  getch();
}
