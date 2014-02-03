#include <stdio.h>
#include <conio.h>

void main()
{
  int A[100], n, i, j, l, par=0, imp=0, pri=0, spar=0, simp=0;

  // receber e guardar em um vetor N numeros inteiros
  do
  {
    clrscr();
    printf("\n\tEntre com a dimensao do vetor (entre 1 e 100): ");
    scanf("%d", &n);
    if ((n<1)||(n>100))
    {
      printf("\n\n\tO valor da dimensao deve ser entre 1 em 100!\n\t[Pressione qualquer tecla para continuar...]\n");
      getch();
    }
  }
  while ((n<1)||(n>100));
  printf("\n");
  for (i=0; i<n; i++)
  {
    printf("\tA[%d]: ", i);
    scanf("%d", &A[i]);
  }

  // dizer quantos sao pares, impares e primos
  for (i=0; i<n; i++)
  {
    l = 0;
    if (A[i]%2==0)
      par++;
    else if (A[i]%2==1)
      imp++;
    if (A[i]>=2)
    {
      for (j=2; A[i]%j!=0; j++);
      if (j==A[i])
      {
          pri++;
      }
    }
  }
  printf("\n\tPares: %d\n\tImpares: %d\n\tPrimos: %d\n", par, imp, pri);

  // calcular a somatoria dos pares e dos impares
  for (i=0; i<n; i++)
  {
    if (A[i]%2==0)
      spar += A[i];
    else if (A[i]%2==1)
      simp += A[i];
  }

  // mostrar as somatorias na tela
  printf("\n\tSomatoria dos pares: ");
  for (i=0; i<n; i++)
  {
    if (A[i]%2==0)
    {
      printf("%d ", A[i]);
      if (i<n-2)
        printf("+ ");
    }
  }
  printf("= %d\n\tSomatoria dos impares: ", spar);
  for (i=0; i<n; i++)
  {
    if (A[i]%2==1)
    {
      printf("%d ", A[i]);
      if (i<n-2)
        printf("+ ");
    }
  }
  printf("= %d", simp);
  getch();
}
