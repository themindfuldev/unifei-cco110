#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void main()
{
  int *p, t, *q;
  clrscr();
  p = (int *) malloc (40*sizeof(int));
  if (!p)
    printf("memoria insuficiente!\n");
   else
    {
      printf ("ender t  ");
      for (t=0;t<6;t++)
         {
	    *(p+t) = t;
            q= p+t;
            printf ("%p\t",q);   //%p exibe um endereco de ponteiro em hexa
         }
      printf ("\nvalor \t ");
      for (t=0;t<6;t++) printf ("%d\t",*(p+t));
      free(p);
     }
}
