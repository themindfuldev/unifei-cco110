#include <stdio.h>
#include <conio.h>

void main()
{
  char A[]={"Unifei"}; // ou char *A="Unifei"
  int i, t;
  clrscr();
  for (i=0; i<5; i++)
    if (A[i]>A[i+1])
    {
      t = A[i];
      A[i] = A[i+1];
      A[i+1] = t;
      i = -1;
    }
  printf("%s\n", A);
  getch();
}
