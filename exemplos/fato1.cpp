#include<stdio.h>
#include<conio.h>
fac(n)
int n;
{  int t,resp;
   resp = 1;
   for (t=1;t<=n;t++)
     resp = resp * t;
   return (resp);
}
void main()
{ int num, fatorial;
  clrscr();
  printf("Numero = "); scanf("%d",&num);
  fatorial = fac(num);
  printf("O fatorial de %d e: %d\n",num,fatorial);
  getch();
}
