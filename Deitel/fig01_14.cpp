// Usando comandos if, operadores relacionais e operadores de igualdade
#include <iostream>
#include <conio.h>

int main()
{
  int num1, num2;

  cout << "Digite dois inteiros e lhe direi\n"
       << "quais os relacionamentos que eles satisfazem: ";
  cin >> num1 >> num2;                          // lê dois inteiros

  if (num1==num2)
    cout << num1 << " e igual a " << num2 << "\n";

  if (num1!=num2)
    cout << num1 << " nao e igual a " << num2 << "\n";

  if (num1<num2)
    cout << num1 << " e menor que " << num2 << "\n";

  if (num1>num2)
    cout << num1 << " e maior que " << num2 << "\n";

  if (num1<=num2)
    cout << num1 << " e menor que ou igual a " << num2 << "\n";

  if (num1>=num2)
    cout << num1 << " e maior que ou igual a " << num2 << "\n";

  getch();
  return 0; // indica que o programa terminou com sucesso
}