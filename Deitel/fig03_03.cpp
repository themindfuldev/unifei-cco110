// Criando e usando uma fun��o definida pelo programador
#include <iostream.h>
#include <conio.h>

int square(int); // prot�tipo da fun��o

int main()
{
  for(int x=1; x<=10; x++)
    cout << square(x) << " ";

  cout << "\n";

  getch();
  return 0;
}

// Defini��o da fun��o
int square(int y)
{
  return y*y;
}
