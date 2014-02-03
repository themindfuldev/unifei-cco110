// Programa de média da turma com repetição controlada por contador
#include <iostream>
#include <conio.h>

int main()
{
  int total,        // soma das notas
      gradeCounter, // número de notas digitadas
      grade,        // uma nota
      average;      // média das notas

  // fase de inicialização
  total = 0;                       // limpa total
  gradeCounter = 1;                // prepara para executar o laço

  // fase de processamento
  while (gradeCounter<=10) {       // repete 10 vezes
    cout << "Forneca nota: ";      // solicita entrada de dados
    cin >> grade;                  // lê a nota digitada
    total = total + grade;         // soma nota ao total
    gradeCounter = gradeCounter+1; // incrementa contador
  }

  // fase de término
  average = total/10;              // divisão inteira
  cout << "A media da turma e: " << average << "\n";

  getch();
  return 0; // indica que o programa terminou com sucesso
}