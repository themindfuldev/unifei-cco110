// Usando o comando break em uma estrutura for
#include <iostream.h>
#include <conio.h>

int main()
{
  for (int x=1; x<=10; x++) {
    if (x==5)
      continue;  // salta o restante do código no laço somente se x é 5

    cout << x << " ";
  }

  cout << "\nUsou continue para pular a impressao do valor 5.\n";

  getch();
  return 0;
}

