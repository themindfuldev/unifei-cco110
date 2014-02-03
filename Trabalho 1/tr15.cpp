#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
  // Variáveis
  float a, b, c, delta, x1, x2;
  char *sinb, *sinc;

  // Leitura
  do
  {
    clrscr();
    printf("\n\tDigite os valores de a, b e c para ax2+bx+c=0.\n\n\ta = ");
    scanf("%f", &a);
    if (a==0)
    {
      printf("\n\tO valor de a nao pode ser zero!\n\t[Pressione alguma tecla para continuar...]");
      getch();
    }
  }
  while (a==0);
  printf("\tb = ");
  scanf("%f", &b);
  printf("\tc = ");
  scanf("%f", &c);

  // Sinal de b e c
  if (b>=0)
    sinb = "+";
   else
     sinb = "";
  if (c>=0)
    sinc = "+";
   else
     sinc = "";

  // Calculo e Escrita
  delta = pow(b,2)-(4*a*c);
  if (delta<0)
     printf("\n\n\tA equacao %0.0fx2%s%0.0fx%s%0.0f nao tem resultado em R.\n", a, sinb, b, sinc, c);
   else if (delta==0)
   {
     x1 = (-b)/(2*a);
     printf("\n\n\tA equacao %0.0fx2%s%0.0fx%s%0.0f tem como resultado: x1 = x2 = %0.0f.\n", a, sinb, b, sinc, c, x1);
   }
   else if (delta>0)
   {
     x1 = ((-b)+sqrt(delta))/(2*a);
     x2 = ((-b)-sqrt(delta))/(2*a);
     printf("\n\n\tA equacao %0.0fx2%s%0.0fx%s%0.0f tem como resultado: x1 = %0.0f e x2 = %0.0f.\n", a, sinb, b, sinc, c, x1, x2);
   }
  getch();
}