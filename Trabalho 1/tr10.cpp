#include <stdio.h>
#include <conio.h>

void main()
{
  // Variáveis
  int i=0;
  float a, b, maior, menor;

  // Leitura, Cálculo e Escrita
  printf("\n\tEntre com os 20 numeros:\n");
  scanf("%f", &a);
  scanf("%f", &b);
  if (a>=b)
  {
    maior = a;
    menor = b;
  }
   else if (a<b)
   {
     maior = b;
     menor = a;
   }
  while (i<18)
  {
    scanf("%f", &a);
    if (a>maior)
      maior = a;
     else if (a<menor)
       menor = a;
    i++;
  }

  printf("\tO maior numero e %0.0f e o menor e %0.0f.\n", maior, menor);
  getch();
}