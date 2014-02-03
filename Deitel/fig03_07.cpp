// Inteiros em uma escala ajustada e deslocada gerados por 1+rand()
#include <iostream.h>
#include <iomanip.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
  for (int i=1; i<=20; i++) {
    cout << setw(10) << 1+(rand()%6);

    if (i%5==0)
      cout << "\n";
  }

  getch();
  return 0;
}

