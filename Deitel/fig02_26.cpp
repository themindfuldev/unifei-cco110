// Usando o comando break em uma estrutura for
#include <iostream.h>
#include <conio.h>

int main()
{
  // x é declarado aqui para que possa ser usado após o laço
  int x;

  for (x=1; x<=10; x++) {
    if (x==5)
      break;  // sai do laço somente se x é 5
    cout << x << " ";
    }

  cout << "\nSaiu do laco com x igual a " << x << "\n";

  getch();
  return 0;
}

