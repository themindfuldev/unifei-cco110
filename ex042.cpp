#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void main()
{
  int *p, *q, t;
  p = (int *) malloc (6*sizeof(int));
  if (!p) {
    printf("\n\n\tMemoria insuficiente!");
    getch();
  }
  else {
    printf("\n\n\tEndereco de t:  ");
    for(t=0; t<6; t++) {
      *(p+t)=t;           // uma posição de memória recebe o valor de t
      q = p+t;            // q recebe o endereço da posição de memória
      printf("%ld\t",q);  // imprime o endereço
    }
    printf("\n\tValor de t: ");
    for(t=0; t<6; t++)
      printf("%ld \t",*(p+t));    //Imprime o conteudo do endereco
    free(p);                     //libera a memoria
  }
  printf("\n");
  getch();
}

