#include <stdio.h>

void main()
{
  int A, B, C;
  printf("Digite o valor de A: ");
  scanf("%d", &A);                      // atribuindo a A um valor de entrada
  printf("Digite o valor de B: ");
  scanf("%d", &B);                      // atribuindo a B um valor de entrada
  C = A+B;
  printf("O valor da soma e: %d\n", C);
  scanf("%d", &A);
}