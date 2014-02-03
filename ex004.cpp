/* Diretivas de controle do cursor
   \n - nova linha
   \t - tab
   \b - backspace

   Máscaras
   %i - inteiro
   %d - inteiro base 10
   %c - caractere
   %s - palavra
   %f - flutuante

   Casas decimais
   Ex: %3.2f - 3 algarismos antes da vírgula e 2 depois da vírgula.
*/

#include <stdio.h>

void main()
{
  float A, B, C;
  int i=1;
  while (i<=3)
  {
    printf("\nDigite o valor de A: ");
    scanf("%f", &A);
    printf("Digite o valor de B: ");
    scanf("%f", &B);
    C = A+B;
    printf("\nO valor da soma eh: %3.2f\n", C);
    C = A-B;
    printf("O valor da subtracao eh: %3.2f\n", C);
    C = A*B;
    printf("O valor da multiplicacao eh: %3.2f\n", C);
    if (B!=0)
    {
      C = A/B;
      printf("O valor da divisao eh: %3.2f\n", C);
    }
    else
      printf("Nao eh possivel efetuar a divisao.\n");
    i++;
  }
  scanf("%d", &A);
}