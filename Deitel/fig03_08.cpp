// Lan�ar um dado de seis faces 6000 vezes
#include <iostream.h>
#include <iomanip.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
  int frequency1 = 0, frequency2 = 0, frequency3 = 0,
      frequency4 = 0, frequency5 = 0, frequency6 = 0,
      face;

  for (int roll=1; roll<=6000; roll++) {
    face = 1+rand()%6;

    switch (face) {
      case 1:
        ++frequency1;
        break;

      case 2:
        ++frequency2;
        break;

      case 3:
        ++frequency3;
        break;

      case 4:
        ++frequency4;
        break;

      case 5:
        ++frequency5;
        break;

      case 6:
        ++frequency6;
        break;

      default:
        cout << "Nao deve chegar aqui nunca!";
    }
  }

  cout << "Face" << setw(13) << "Frequencia"
       << "\n   1" << setw(13) << frequency1
       << "\n   2" << setw(13) << frequency2
       << "\n   3" << setw(13) << frequency3
       << "\n   4" << setw(13) << frequency4
       << "\n   5" << setw(13) << frequency5
       << "\n   6" << setw(13) << frequency6 << "\n";

  getch();
  return 0;
}

