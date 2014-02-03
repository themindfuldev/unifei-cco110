// Programa de média da turma com repetição controlada por sentinela
#include <iostream>
#include <iomanip>
#include <conio.h>

int main()
{
  int total,        // soma das notas
      gradeCounter, // número de notas digitadas
      grade;        // uma nota
  double average;   // média das notas com ponto decimal

  // fase de inicialização
  total = 0;
  gradeCounter = 0;

  // fase de processamento
  cout << "Forneca nota ou -1 para finalizar: ";
  cin >> grade;

  while (grade!=-1) {
    total = total+grade;
    gradeCounter = gradeCounter+1;
    cout << "Forneca nota ou -1 para finalizar: ";
    cin >> grade;
  }

  // fase de término
  if (gradeCounter!=0) {
    average = static_cast<double>(total)/gradeCounter;
    cout << "A media da turma e: " << setprecision(2)
         << setiosflags(ios::fixed|ios::showpoint) << average << "\n";
  }
  else
    cout << "Nenhuma nota foi fornecida\n";

  getch();
  return 0; // indica que o programa terminou com sucesso
}