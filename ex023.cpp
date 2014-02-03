#include <stdio.h>
#include <conio.h>

void main()
{
  char A[]={"Unifei "}, t;  // ou char *A = "Unifei";
  int i;
  clrscr();
  for (i=0; i<6; i++)
    if (A[i]>A[i+1])
    {
      t = A[i];
      A[i] = A[i+1];
      A[i+1] = t;
      i = -1;
    }
  printf("Como string de caracteres: %s\n\nComo um vetor:\n", A);
  for (i=0; i<7; i++)
    printf("\tA[%d] = %c\n", i, A[i]);
  getch();
}
