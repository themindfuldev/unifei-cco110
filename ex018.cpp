#include <iostream.h>
#include <conio.h>

void main()
{
  int soma[100], n, i;
  do {
    cout << ("\tN= ");
    cin >> n;
    if ((n<0)||(n>=100)) {
      cout << "\n\tN deve ser entre 1 e 100!\n\t[Pressione qualqer tecla para continuar...]\n\n";
      getch();
    }
  }
  while ((n<0)&&(n>=100));
  cout << "\n";
  for (i=0; i<n; i++) {
    soma[i] = i*2+(i*2+1);
    cout << "\t" << (i+1) << "o. impar (" << (i*2+1) << ") + " << (i+1) << "o. par (" << (i*2) << ") = " << soma[i] << "\n";
  }
  getch();
}