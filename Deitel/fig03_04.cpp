// Encontrar o maior de tr�s inteiros
#include <iostream.h>
#include <conio.h>

int maximum(int, int, int); // prot�tipo da fun��o

int main()
{
  int a, b, c;

  cout << "Forneca tres inteiros: ";
  cin >> a >> b >> c;

  // a, b e c, abaixo, s�o argumentos para a chamada da fun��o maximum
  cout << "O maior e: " << maximum(a, b, c) << "\n";

  getch();
  return 0;
}

// Defini��o da fun��o maximum
// x, y e z, abaixo, s�o par�metros para a defini��o da fun��o maximum
int maximum(int x, int y, int z)
{
  int max = x;

  if (y>max)
    max = y;
  if (z>max)
    max = z;

  return max;
}
