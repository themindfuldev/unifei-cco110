#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int IniciaModoGrafico();

void main()
{
  char Texto[] = "E o CHAPOLIM COLORADO!!";
  IniciaModoGrafico();

  moveto (100,90);
  settextstyle (0, 0, 0);
  outtext ("Mais rapido do que uma tartaruga...");
  settextstyle (2, 0, 0);
  outtextxy (100, 100, "Mais inteligente do que um chimpanze...");
  settextstyle (1, 0, 0);
  outtextxy (100, 110, Texto);

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