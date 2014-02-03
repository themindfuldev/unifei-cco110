#include <stdio.h> // header (cabeçalho) - "standard input/output"
#include <conio.h>
/* Funções de stdio.h
   printf  - imprimir (tela, impressora...)
   scanf   - ler (teclado)
   fprintf - imprimir (disco)
   fscanf  - ler (disco)
   getch   - ler (tecla)
   putg    - escrever (palavra)
   gets    - ler (palavra)
*/

void main()                             // função principal
{
  int A, B, C;                          // definição de tipo da variável
  A = 5;                                // atribuindo a A o valor 5
  B = 2;                                // atribuindo a B o valor 2
  C = A+B;                              // atribuindo a C o processo A+B
  printf("O valor da soma e: %d\n", C); // escrevendo o valor da soma
  getch();                              // visualização
}