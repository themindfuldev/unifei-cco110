#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void main()
{
  int *p, t;
  clrscr();
  p = (int *) malloc (40*sizeof(int));
  if (!p)
    printf("memoria insuficiente!\n");
   else
    {
      for (t=0;t<60;t++) *(p+t) = t;
      for (t=0;t<60;t++) printf ("%d ",*(p+t));
      free(p);
     }
}
