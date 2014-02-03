// Pré-icrementando e pós incrementando
#include <iostream.h>
#include <conio.h>

int main()
{
  int c;

  c = 5;
  cout << c << "\n";        // imprime 5
  cout << c++ << "\n";      // imprime 5 e então pós-incrementa
  cout << c << "\n\n";      // imprime 6

  c = 5;
  cout << c << "\n";        // imprime 5
  cout << ++c << "\n";      // pré-incrementa e então imprime 6
  cout << c << "\n";        // imprime 6

  getch();
}