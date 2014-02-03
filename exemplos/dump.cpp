#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
      //unsigned long int serve para ler um endereco muito grande (maior que 65535)
void dump (unsigned long int inicio)
{
  char far *p;     // far e palavra reservada do C e permite que os ponteiros facam 
  int t;           // referencia a localizacoes  que nao estejam no mesmo segmento de 
  p = (char far *) inicio;       // memoria do ponteiro
  for(t=0;;t++,p++)
   {
     if (!(t%16)) printf("\n");
     printf("%2x ",*p);     // %x manda exibir em hexa minusculo %X hexa maiusculo
     if (kbhit()) return;  //kbhit recebe o valor digitado pelo teclado
   }
}

void main()
{
  unsigned long int inicio;
  printf("Digite o endereco inicial: ");
  scanf("%lu", &inicio);  //%lu estou lendo um inteiro longo e sem sinal
  dump(inicio);
}