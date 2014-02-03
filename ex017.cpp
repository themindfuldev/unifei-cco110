#include <iostream.h>
#include <conio.h>

void main()
{
  char vetor[7];
  int i;
  for (i=0; i<6; i++) {
    cout << "\tDigite a " << (i+1) << "a letra: ";
    cin >> vetor[i];
  }
  vetor[7] = '\0';
  cout << "\n\t" << vetor;
  getch();
}