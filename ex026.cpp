#include <stdio.h>
#include <conio.h>

void main()
{
  int n, i, cod[100], qtd[100];
  char desc[100][10];
  float rsun[100], rstot[100], total=0;

  do
  {
    clrscr();
    printf("\n\tQuantos registros deseja cadastrar? ");
    scanf("%d", &n);
    if ((n<=0)||(n>100))
    {
      printf("\n\n\tDigite um valor positivo e menor ou igual a 100!\n\t[Pressione qualquer tecla para continuar...]\n");
      getch();
    }
  }
  while ((n<=0)||(n>100));
  printf("\n\n                        CONTROLE DE ESTOQUE\n  Codigo    Descricao Quant.    R$ Un.    R$ Total\n");

  for (i=0; i<n; i++)
  {
    gotoxy(6,7+i); scanf("%d", &cod[i]);
    gotoxy(16,7+i); scanf("%s", &desc[i]);
    gotoxy(26,7+i); scanf("%d", &qtd[i]);
    gotoxy(36,7+i); scanf("%f", &rsun[i]);
    rstot[i] = rsun[i]*qtd[i];
    gotoxy(44,7+i); printf("%5.2f", rstot[i]);
    total += rstot[i];
  }
  printf("\n\n  Total\t\t\t\t\t   %5.2f.\n", total);
  getch();
}