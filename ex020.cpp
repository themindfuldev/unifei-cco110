#include <iostream.h>
#include <iomanip.h>
#include <conio.h>

void main()
{
  int soma[100], par[100], impar[100], n, i, spar=0, simpar=0, stotal=0;
  do {
    cout << ("\tN= ");
    cin >> n;
    if ((n<0)||(n>=100)) {
      cout << "\n\tN deve ser entre 1 e 100!\n\t[Pressione qualqer tecla para continuar...]\n\n";
      getch();
    }
  }
  while ((n<0)&&(n>=100));
  for (i=0; i<n; i++){
    par[i] = i*2;
    impar[i] = i*2+1;
  }
  cout << "\n\tN     Pares   Impares   Soma\n\t---------------------------\n";
  for (i=0; i<n; i++) {
    soma[i] = par[i]+impar[i];
    spar += par[i];
    simpar += impar[i];
    stotal += soma[i];
    cout << "\t" << (i+1) << "\t" << setiosflags(ios::fixed|ios::showpoint) << par[i] << "   +   " << impar[i] << "   =   " << soma[i] << "\n";
  }
  cout << "\t---------------------------\n\tSoma:\t" << simpar << "\t" << spar << "\t" << stotal << "\n";
  getch();
}