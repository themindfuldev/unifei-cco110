// Análise dos resultados do teste
#include <iostream>
#include <conio.h>

int main()
{
  // iniclializa as variáveis nas declarações
  int passes = 0,         // número de aprovações
      failures = 0,       // número de reprovações
      studentCounter = 1, // contador de estudantes
      result;             // um resultado do teste

  // processa 10 estudantes; ciclo controlado por contador
  while (studentCounter<=10) {
    cout << "Forneca resultado (1=aprovado, 2=reprovado): ";
    cin >> result;

    if (result==1)           // if/else aninhado no while
      passes = passes +1;
    else
      failures = failures+1;

    studentCounter = studentCounter+1;
  }

  // fase de término
  cout << "Aprovados: " << passes
       << "\nReprovados: " << failures << "\n";

  if (passes>8)
    cout << "Aumente o preco do curso.\n";

  getch();
  return 0; // indica que o programa terminou com sucesso
}