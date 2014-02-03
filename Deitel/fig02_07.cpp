// Programa de m�dia da turma com repeti��o controlada por contador
#include <iostream>
#include <conio.h>

int main()
{
  int total,        // soma das notas
      gradeCounter, // n�mero de notas digitadas
      grade,        // uma nota
      average;      // m�dia das notas

  // fase de inicializa��o
  total = 0;                       // limpa total
  gradeCounter = 1;                // prepara para executar o la�o

  // fase de processamento
  while (gradeCounter<=10) {       // repete 10 vezes
    cout << "Forneca nota: ";      // solicita entrada de dados
    cin >> grade;                  // l� a nota digitada
    total = total + grade;         // soma nota ao total
    gradeCounter = gradeCounter+1; // incrementa contador
  }

  // fase de t�rmino
  average = total/10;              // divis�o inteira
  cout << "A media da turma e: " << average << "\n";

  getch();
  return 0; // indica que o programa terminou com sucesso
}