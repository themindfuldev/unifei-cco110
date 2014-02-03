// Contando notas representradas por letras
#include <iostream.h>
#include <conio.h>

int main()
{
  int grade,       // uma nota
      aCount = 0,  // n�mero de As
      bCount = 0,  // n�mero de Bs
      cCount = 0,  // n�mero de Cs
      dCount = 0,  // n�mero de Ds
      fCount = 0;  // n�mero de Fs

  cout << "Forneca as notas representadas por letras.\n"
       << "Digite o caractere EOF para terminar a entrada de dados.\n";

  while ((grade=cin.get())!=EOF) {

    switch (grade) {  // switch aninhado no while

      case 'A':       // nota foi A mai�sculo
      case 'a':       // ou a min�sculo
        ++aCount;
        break;        // necess�rio para sair do switch

      case 'B':       // nota foi B mai�sculo
      case 'b':       // ou b min�sculo
        ++bCount;
        break;

      case 'C':       // nota foi C mai�sculo
      case 'c':       // ou c min�sculo
        ++cCount;
        break;

      case 'D':       // nota foi D mai�sculo
      case 'd':       // ou d min�sculo
        ++dCount;
        break;

      case 'F':       // nota foi F mai�sculo
      case 'f':       // ou f min�sculo
        ++fCount;
        break;

      case '\n':       // ignora newlines,
      case '\t':       // tabula�oes
      case ' ':        // e espa�os na entrada
        break;

      default:         // pega todos os outros caracteres
        cout << "Fornecida nota representada por letra incorreta."
             << " Digite uma nova nota.\n";
        break;         // opcional
    }
  }

  cout << "\n\nOs totais para cada nota representada por letra sao:"
       << "\nA: " << aCount
       << "\nB: " << bCount
       << "\nC: " << cCount
       << "\nD: " << dCount
       << "\nF: " << fCount << "\n";

  getch();
  return 0;
}

