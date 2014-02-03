#include <iostream.h>
#include <conio.h>

void main()
{
  int vetor[5], i;
  for (i=0; i<5; i++) {
    cout << "\tVetor [" << i << "]= ";
    cin >> vetor[i];
  }
  getch();
}