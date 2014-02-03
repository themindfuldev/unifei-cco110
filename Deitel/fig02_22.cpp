// Contando notas representradas por letras
#include <iostream.h>
#include <conio.h>

int main()
{
  int grade,       // uma nota
      aCount = 0,  // número de As
      bCount = 0,  // número de Bs
      cCount = 0,  // número de Cs
      dCount = 0,  // número de Ds
      fCount = 0;  // número de Fs

  cout << "Forneca as notas representadas por letras.\n"
       << "Digite o caractere EOF para terminar a entrada de dados.\n";

  while ((grade=cin.get())!=EOF) {

    switch (grade) {  // switch aninhado no while

      case 'A':       // nota foi A maiúsculo
      case 'a':       // ou a minúsculo
        ++aCount;
        break;        // necessário para sair do switch

      case 'B':       // nota foi B maiúsculo
      case 'b':       // ou b minúsculo
        ++bCount;
        break;

      case 'C':       // nota foi C maiúsculo
      case 'c':       // ou c minúsculo
        ++cCount;
        break;

      case 'D':       // nota foi D maiúsculo
      case 'd':       // ou d minúsculo
        ++dCount;
        break;

      case 'F':       // nota foi F maiúsculo
      case 'f':       // ou f minúsculo
        ++fCount;
        break;

      case '\n':       // ignora newlines,
      case '\t':       // tabulaçoes
      case ' ':        // e espaços na entrada
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

