#include <stdio.h> // header (cabe�alho) - "standard input/output"
#include <conio.h>
/* Fun��es de stdio.h
   printf  - imprimir (tela, impressora...)
   scanf   - ler (teclado)
   fprintf - imprimir (disco)
   fscanf  - ler (disco)
   getch   - ler (tecla)
   putg    - escrever (palavra)
   gets    - ler (palavra)
*/

void main()                             // fun��o principal
{
  int A, B, C;                          // defini��o de tipo da vari�vel
  A = 5;                                // atribuindo a A o valor 5
  B = 2;                                // atribuindo a B o valor 2
  C = A+B;                              // atribuindo a C o processo A+B
  printf("O valor da soma e: %d\n", C); // escrevendo o valor da soma
  getch();                              // visualiza��o
}