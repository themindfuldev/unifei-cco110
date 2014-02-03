#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void main()
{
  int N, **p, j, k;
  printf("\n\tDigite um valor (N) para linhas e colunas: ");
  scanf("%d", &N);

  p = (int **) malloc (N*sizeof(int *));
  if (p==NULL) return;
  for (k=0; k<N; k++) {
    p[k] = (int *) malloc (N*sizeof(int));
    if(p[k]==NULL) return;
  }

  for (k=0; k<N; k++) {
    printf("\n\tDigite os %d elementos da linha %d: ", N, k);
    for (j=0; j<N; j++)
      scanf("%d", &p[k][j]);
  }

  printf("\n\t *** Matriz Lida: ");
  for (k=0; k<N; k++) {
    printf("\n");
    for (j=0; j<N; j++)
     printf ("%d ", p[k][j]);
  }

  for (k=0; k<N; k++)
    free(p[k]);
  free(p);
  getch();  
}