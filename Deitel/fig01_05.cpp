// Programa de adição
#include <iostream>
#include <conio.h>

int main()
{
  int inteiro1, inteiro2, soma;             // declaração

  cout << "Digite o primeiro inteiro\n";    // prompt
  cin >> inteiro1;                          // lê um inteiro
  cout << "Digite o segundo inteiro\n";     // prompt
  cin >> inteiro2;                          // lê um inteiro
  soma = inteiro1 + inteiro2;               // atribuição da soma
  cout << "A soma e: " << soma << "\n";     // imprime a soma

  getch();
  return 0; // indica que o programa terminou com sucesso
}