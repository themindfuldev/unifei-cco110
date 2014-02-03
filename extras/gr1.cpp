#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int IniciaModoGrafico();

void main()
{
  int x;
  IniciaModoGrafico();
  randomize();
  for (x=100; x<=400; x++) {
    putpixel (rand()%700, rand()%500, WHITE);
    putpixel (rand()%700, rand()%500, WHITE);
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