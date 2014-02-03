#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

int IniciaModoGrafico();

void main()
{
  IniciaModoGrafico();

  bar (100, 100, 150, 250);
  setfillstyle (8, BLUE);
  bar3d (200, 100, 250, 250, 15, 1);
  setfillstyle (4, YELLOW);
  bar (300, 100, 350, 250);

  randomize();
  for (int i=1; i<=12; i++)
  {
    setfillstyle (i-1, i);
    bar (400, 100, 450,250);
    delay (1000);
  }

  getch();
  closegraph();
}

int IniciaModoGrafico()
{
  int gdriver = DETECT, gmode;
  initgraph (&gdriver, &gmode, "C:\\ARQUIV~1\\BC5\\BGI");
  if (graphresult() != 0) {
    printf ("\n\tErro da inicializacao do Modo Grafico!\n\tVerifique se os arquivos BGI foram encontrados.\n\n\t[Pressione qualquer tecla pra continuar...]\n");
    getch();
    return 1;
  }
  else
    return 0;
}
