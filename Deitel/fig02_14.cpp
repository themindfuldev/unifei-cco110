// Pr�-icrementando e p�s incrementando
#include <iostream.h>
#include <conio.h>

int main()
{
  int c;

  c = 5;
  cout << c << "\n";        // imprime 5
  cout << c++ << "\n";      // imprime 5 e ent�o p�s-incrementa
  cout << c << "\n\n";      // imprime 6

  c = 5;
  cout << c << "\n";        // imprime 5
  cout << ++c << "\n";      // pr�-incrementa e ent�o imprime 6
  cout << c << "\n";        // imprime 6

  getch();
}