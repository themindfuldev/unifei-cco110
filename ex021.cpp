#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
  int op;
  float l, res;
  clrscr();
  printf("\n\tEntre com o lado do quadrado: ");
  scanf("%f", &l);
  do
  {
    clrscr();
    printf("\n\tLado do quadrado = %2.2f\n\n\t1. Area\n\t2. Perimetro\n\t3. Volume\n\t4. Sair\n\n\tOpcao: ", l);
    scanf("%d", &op);
    switch(op)
    {
      case 1:  res = pow(l,2);
               printf("\n\n\tArea = %2.2f\n", res);
               break;
      case 2:  res = 4*l;
               printf("\n\n\tPerimetro = %2.2f\n", res);
               break;
      case 3:  res = pow(l,3);
               printf("\n\n\tVolume = %2.2f\n", res);
               break;
      case 4:  break;
      default: printf("\n\n\tOpcao invalida!\n\t[Pressione qualquer tecla para continuar...]");
               break;
    }
    getch();    
  }
  while (op!=4);
}
