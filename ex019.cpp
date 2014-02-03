#include <stdio.h>
#include <conio.h>

void main()
{
  char vetor[7];
  int i;
  for (i=0; i<6; i++) {
    printf("\tDigite a %da. letra: ", i+1);
    scanf("%s", &vetor[i]);
  }
  vetor[7] = '\0';
  printf("\n\n\tVoce digitou: %s", vetor);
  getch();
}