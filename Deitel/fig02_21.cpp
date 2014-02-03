// Calculando juros compostos
#include <iostream.h>
#include <iomanip.h>
#include <math.h>
#include <conio.h>

int main()
{
  double amount,              // quantia em deposito
         principal = 1000.0,  // inicializando o capital
         rate = .05;          // taxa de juros

  cout << " Ano    Quantia em deposito\n";

  // ajusta o formato de números em ponto flutuante
  cout << setiosflags(ios::fixed | ios::showpoint) << setprecision(2);

  for (int year=1; year<=10; year++) {
    amount = principal*pow(1.0+rate, year);
    cout << setw(4) << year << "  " << setw(21) << amount << "\n";
  }

  getch();
  return 0;
}

