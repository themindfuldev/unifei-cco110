// Randomizando o programa de lançamento de um dado
#include <iostream.h>
#include <iomanip.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
  unsigned seed;

  cout << "Forneca a semente: ";
  cin >> seed;
  srand(seed);

  for(int i=1; i<=10; i++) {
    cout << setw(10) << 1+rand()%6;

    if (i%5==0)
      cout << "\n";
  }

  getch();
  return 0;
}

