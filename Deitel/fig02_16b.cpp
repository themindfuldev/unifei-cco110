// Repeti��o controlada por contador
#include <iostream.h>
#include <conio.h>

int main()
{
  int counter = 0;             // inicializa��o

  while (++counter<=10)       // condi��o de repeti��o com incremento
    cout << counter << "\n";

  getch();
  return 0;
}

