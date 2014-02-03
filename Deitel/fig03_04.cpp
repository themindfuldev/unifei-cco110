// Encontrar o maior de três inteiros
#include <iostream.h>
#include <conio.h>

int maximum(int, int, int); // protótipo da função

int main()
{
  int a, b, c;

  cout << "Forneca tres inteiros: ";
  cin >> a >> b >> c;

  // a, b e c, abaixo, são argumentos para a chamada da função maximum
  cout << "O maior e: " << maximum(a, b, c) << "\n";

  getch();
  return 0;
}

// Definição da função maximum
// x, y e z, abaixo, são parâmetros para a definição da função maximum
int maximum(int x, int y, int z)
{
  int max = x;

  if (y>max)
    max = y;
  if (z>max)
    max = z;

  return max;
}
