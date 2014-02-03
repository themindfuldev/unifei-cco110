#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

void EscreveTexto (int x, int y);
int IniciaModoGrafico();

void main()
{
  IniciaModoGrafico();

  EscreveTexto (200, 200);

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

void EscreveTexto (int x, int y)
{
  int style, u, size=1;
  char *fname[]={"DEFAULT_FONT", "TRIPLEX_FONT", "SMALL_FONT", "SANS_SERIF_FONT", "GOTHIC_FONT", "SCRIPT_FONT", "SIMPLEX_FONT", "TRIPLEX_SCRIPT_FONT", "COMPLEX_FONT", "EUROPEAN_FONT", "BOLD_FONT"};
  randomize();
  settextjustify (CENTER_TEXT, CENTER_TEXT);
  for (style=0; style<=10; style++)
  {
    cleardevice();
    if (style==1) size = 4;
    u = rand()%10;
    setcolor(u);
    settextstyle(style, HORIZ_DIR, size);
    outtextxy (x, y, fname[style]);
    delay (1000);
  }
}