#include <stdio.h>
#include <conio.h>

struct registro
  {
    int MAT;
    char NOM[30];
    float MF;
  };

  registro tab[100];
  int i, N;

  void main()
  {
    clrscr();
    printf ("N= ");
    scanf ("%d",&N);
    printf ("Digite os dados separados por tabs e no final de Enter\n");
    printf ("\tMatric\tNome\tMedia Final\n");
    for (i=1;i<N;i++)
    {
       printf("%d-\t",i);
       scanf ("%d %s %f",&tab[i].MAT,&tab[i].NOM,&tab[i].MF);
    }
    clrscr();
    printf ("\tCONTROLE DE NOTAS\n");
    printf ("   MATRICULA\tNOME\t\tMEDIA FINAL\n");
    for (i=1;i<N;i++)
       printf("%d- %d\t\t%s\t\t%3.2f\n",i,tab[i].MAT,tab[i].NOM,tab[i].MF);

    getch();
  }