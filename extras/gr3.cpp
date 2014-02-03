#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

int IniciaModoGrafico();
void PiscaLinha (int x, int y, int cor);

void main()
{
  IniciaModoGrafico();
  PiscaLinha (320, 140, CYAN);
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

void PiscaLinha (int x, int y, int cor)
{
  int k;
  for (k=0; k<=5; k++)
  {
    setcolor (cor);
    setlinestyle (DOTTED_LINE, 0, 1);
    line (x, y, x, y+200);
    delay (300);
    setcolor (BLACK);
    setlinestyle (DOTTED_LINE, 0, 1);
    line (x, y, x, y+200);
    delay(300);
  }
  setcolor (cor);
  setlinestyle (DOTTED_LINE, 0, 1);
  line (x, y, x, y+200);
}