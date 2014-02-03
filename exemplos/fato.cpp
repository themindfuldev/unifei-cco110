#include<stdio.h>
#include<conio.h>
fac(n)
int n;
{  int resp;
   if (n==1)
     return (1);
   resp = fac(n-1) * n;
   return (resp);
}
void main()
{ int num, fatorial;
  printf("Numero = "); scanf("%d",&num);
  fatorial = fac(num);
  printf("O fatorial de %d e: %d\n",num,fatorial);
  getch();
}
