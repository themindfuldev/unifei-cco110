#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void main()
{
  int *p, t, N, num, *troca;
  clrscr();
  do
  {
    printf ("Quantos numeros quer ordenar: ");
    scanf ("%d",&N);
    if (N<1) printf ("Numero de elementos inv lido!\n");
  } while (N<1);
  p = (int *) malloc (N*sizeof(int));
  if (!p)
    printf("memoria insuficiente!\n");
   else
    {
      for (t=0;t<N;t++)
        {
          printf("Digite o %do. numero: ",t+1);
	  scanf ("%d",&num);
	  *(p+t) = num;
         }
      for (t=0;t<N-1;t++)
        if ( *(p+t) < *(p+t+1) )
	  {
            *troca = *(p+t);
            *(p+t) = *(p+t+1);
            *(p+t+1) = *troca;
            t=-1;
          }
      for (t=0;t<N;t++) printf ("%d ",*(p+t));
      free(p);
     }

     getch();
}
