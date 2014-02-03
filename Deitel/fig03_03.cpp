// Criando e usando uma função definida pelo programador
#include <iostream.h>
#include <conio.h>

int square(int); // protótipo da função

int main()
{
  for(int x=1; x<=10; x++)
    cout << square(x) << " ";

  cout << "\n";

  getch();
  return 0;
}

// Definição da função
int square(int y)
{
  return y*y;
}
