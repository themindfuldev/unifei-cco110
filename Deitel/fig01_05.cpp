// Programa de adi��o
#include <iostream>
#include <conio.h>

int main()
{
  int inteiro1, inteiro2, soma;             // declara��o

  cout << "Digite o primeiro inteiro\n";    // prompt
  cin >> inteiro1;                          // l� um inteiro
  cout << "Digite o segundo inteiro\n";     // prompt
  cin >> inteiro2;                          // l� um inteiro
  soma = inteiro1 + inteiro2;               // atribui��o da soma
  cout << "A soma e: " << soma << "\n";     // imprime a soma

  getch();
  return 0; // indica que o programa terminou com sucesso
}