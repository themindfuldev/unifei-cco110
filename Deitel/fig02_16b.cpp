// Repetição controlada por contador
#include <iostream.h>
#include <conio.h>

int main()
{
  int counter = 0;             // inicialização

  while (++counter<=10)       // condição de repetição com incremento
    cout << counter << "\n";

  getch();
  return 0;
}

