#include <conio.h>
#include <iostream.h>
#define MAX 10

void main()
{
  float A[MAX][MAX], soma=0, mult=1;
  int m;

  // Inicio
  do {
    clrscr();
    cout << "\n\tDigite as dimensoes da matriz quadrada no formato [A]mxm: ";
    cin >> m;
    if ((m<1)||(m>10)) {
      cout << "\n\tDigite um valor entre 1 e 10!\n\t[Pressione qualquer tecla para continuar...]\n";
      getch();
    }
  }
  while ((m<1)||(m>10));

  // Leitura
  clrscr();
  cout << "\n\tEntre com os valores da matriz [A]" << m << "x" << m << ":";
  for (int i=0; i<m; i++)
    for (int j=0; j<m; j++) {
      gotoxy(10+10*j,4+i); cin >> A[i][j];
    }

  // Cálculo
  for (int i=0; i<m; i++) {
    soma += A[i][i];
    mult *= A[i][m-i-1];
  }

  // Exibição
  cout << "\n\n\tO resultado da soma dos elementos da diagonal principal e: "
       << soma << "\n\tO resultado do produto dos elementos da diagonal secundaria e: "
       << mult << "\n";
  getch();
}