#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int IniciaModoGrafico();

void main()
{
  IniciaModoGrafico();

  rectangle (100, 100, 300, 160);
  outtextxy (400, 130, "Retangulo 1");
  setfillstyle (SOLID_FILL, YELLOW);
  bar (100, 200, 300, 260);
  outtextxy (400, 230, "Retangulo 2");

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