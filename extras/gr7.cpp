#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

void PiscaTexto (int x, int y);
int IniciaModoGrafico();

void main()
{
  IniciaModoGrafico();

  PiscaTexto (100, 100);

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

void PiscaTexto (int x, int y)
{
  int k, u;
  randomize();
  for (k=0; k<=10; k++)
  {
    u = rand()%10;
    setcolor(u);
    settextstyle(u, HORIZ_DIR, u);
    outtextxy (x, y, "UAI TA LOCO FII");
    delay (300);
    setcolor (BLACK);
    settextstyle(u, HORIZ_DIR, u);
    outtextxy (x, y, "UAI TA LOCO FII");
    delay (300);
  }
  setcolor (rand()%10);
  settextstyle(rand()%10, HORIZ_DIR, rand());
  outtextxy (x, y, "UAI TA LOCO FII");
}