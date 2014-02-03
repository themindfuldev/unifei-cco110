#include <conio.h>
#include <iostream.h>
#define MAX 10

void main()
{
  float A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
  int m, n;

  // Inicio
  do {
    clrscr();
    cout << "\n\tDigite as dimensoes das matrizes no formato [A]mxn:\n\tm: ";
    cin >> m;
    if ((m<1)||(m>10)) {
      cout << "\n\tDigite um valor entre 1 e 10!\n\t[Pressione qualquer tecla para continuar...]\n";
      getch();
    }
  }
  while ((m<1)||(m>10));
  do {
    cout << "\tn: ";
    cin >> n;
    if ((n<1)||(n>10)) {
      cout << "\n\tDigite um valor entre 1 e 10!\n\t[Pressione qualquer tecla para continuar...]\n\n";
      getch();
    }
  }
  while ((n<1)||(n>100));

  // Leitura
  clrscr();
  cout << "\n\tEntre com os valores da matriz [A]" << m << "x" << n << ":";
  for (int i=0; i<m; i++)
    for (int j=0; j<n; j++) {
      gotoxy(10+10*j,4+i); cin >> A[i][j];
    }
  clrscr();
  cout << "\n\tEntre com os valores da matriz [B]" << m << "x" << n << ":";
  for (int i=0; i<m; i++)
    for (int j=0; j<n; j++) {
      gotoxy(10+10*j,4+i); cin >> B[i][j];
    }

  // Cálculo
  for (int i=0; i<m; i++)
    for (int j=0; j<n; j++) {
      C[i][j] = A[i][j] + B[i][j];
    }

  // Exibição
  clrscr();
  cout << "\n\tO resultado da matriz [C]" << m << "x" << n << "=[A]+[B] e:";
  for (int i=0; i<m; i++)
    for (int j=0; j<n; j++) {
      gotoxy(10+10*j,4+i); cout << C[i][j];
    }
  cout << "\n\t[Pressione qualquer tecla para continuar...]";
  getch();
  clrscr();
  cout << "\n\tO resultado da matriz [D]" << n << "x" << m << "=[A]t e:";
  for (int i=0; i<n; i++)
    for (int j=0; j<m; j++) {
      gotoxy(10+10*j,4+i); cout << A[j][i];
    }
  cout << "\n";
  getch();
}