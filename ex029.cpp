#include <conio.h>
#include <iostream.h>

void main()
{
  float B[2][2], det;

  // Leitura
  clrscr();
  cout << "\n\tEntre com os valores da matriz [B]3x3:";
  for (int i=0; i<3; i++)
    for (int j=0; j<3; j++) {
      gotoxy(10+10*j,4+i); cin >> B[i][j];
    }

  // Cálculo
  det = (B[0][0]*B[1][1]*B[2][2])+(B[0][1]*B[1][2]*B[2][0])+
        (B[0][2]*B[1][0]*B[2][1])-(B[0][2]*B[1][1]*B[2][0])-
        (B[0][0]*B[1][2]*B[2][1])-(B[0][1]*B[1][0]*B[2][2]);

  // Exibição
  cout << "\n\tO resultado da determinante da matriz [B]3x3 e: " << det << "\n";
  getch();
}