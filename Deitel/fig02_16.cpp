// Repeti��o controlada por contador
#include <iostream.h>
#include <conio.h>

int main()
{
  int counter = 1;            // inicializa��o

  while (counter<=10) {       // condi��o de repeti��o
    cout << counter << "\n";
    ++counter;                // incremento
  }

  getch();
  return 0;
}

