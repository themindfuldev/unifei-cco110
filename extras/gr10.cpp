#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

void TracaEstrela (int NumPontos, int VetorPontos[]);
int IniciaModoGrafico();

void main()
{
  int VetorPontos[] = {10, 30, 30, 30, 40, 10, 50, 30, 70, 30, 60, 50, 70, 70, 50, 70, 40, 90, 30, 70, 10, 70, 20, 50, 10, 30}, NumPontos=13;
  IniciaModoGrafico();

  TracaEstrela (NumPontos, VetorPontos);

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

void TracaEstrela (int NumPontos, int VetorPontos[])
{
  setfillstyle (7, YELLOW);
  fillpoly (NumPontos, VetorPontos);
}