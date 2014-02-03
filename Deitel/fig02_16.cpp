// Repetição controlada por contador
#include <iostream.h>
#include <conio.h>

int main()
{
  int counter = 1;            // inicialização

  while (counter<=10) {       // condição de repetição
    cout << counter << "\n";
    ++counter;                // incremento
  }

  getch();
  return 0;
}

