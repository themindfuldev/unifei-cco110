#include <iomanip.h>
#include <conio.h>
#include <iostream.h> // substitui stdio.h

void main()
{
  int A, B, C, D;

  clrscr();
  cout << "\tA= ";      // escreve na tela
  cin >> A;           // le de teclado
  do
  {
    cout << "\tB= ";
    cin >> B;
    if (B!=0)
    {
      C = A/B;
      D = A%B;
    }
    else
      cout << "\tB nao pode ser zero!\n\t[Pressione qualquer tecla para continuar...]\n\n";
  }
  while(B==0);
  cout << "\n\tA divisao e: " << setprecision(2) << C
       << "\n\tO resto e: " << D << "\n";
  getch();
}
