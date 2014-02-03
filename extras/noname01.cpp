#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void main()
{
  int *Pinicio, *Pi, N;
  printf("\n\tDigite o numero de elementos (N): ");
  scanf("%d", &N);
  Pi = (int *) malloc (100);
  if (Pi==NULL) printf("\n\tErro de reserva de memoria.\n");
  else {
    int k;
    for (Pinicio=Pi; Pinicio<(Pi+N); Pinicio++) {
      printf("\tDigite um valor inteiro: ");
      scanf("%d", Pinicio);
    }
    if (N>0) {
      printf("\n ******** Valores lidos:\n");
      for (k=0, Pinicio=Pi; Pinicio<(Pi+N); k++, Pinicio++)
        printf("[%d]=%d, ", k, *Pinicio);
      free(Pi);
    }
  }
  getch();
}

