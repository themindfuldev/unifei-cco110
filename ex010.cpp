#include <stdio.h>
#include <conio.h>

void main()
{
  int n, i, mat, rep=0, mtb1m, mtb2m, mtmfa1=0, mtmfa2;
  float b1, b2, mf, b1m=100, b2m=100, mfa1=0, mfa2=0, mb1=0, mb2=0, mmf=0;
  do
  {
    clrscr();
    printf("\tQuantas matriculas deseja cadastrar? ");
    scanf("%d/", &n);
    if (n<1)
    {
      printf("\n\n\tDigite um numero positivo!\n\t[Pressione alguma tecla para continuar...]");
      getch();
    }
  }
  while(n<1);
  for (i=1; i<=n; i++)
  {
    printf("\n\tMatricula: ");
    scanf("%d", &mat);
    printf("\tB1: ");
    scanf("%f", &b1);
    if (b1<b1m)
    {
      b1m = b1;
      mtb1m = mat;
    }
    printf("\tB2: ");
    scanf("%f", &b2);
    if (b2<b2m)
    {
      b2m = b2;
      mtb2m = mat;
    }
    mf = ((2*b1)+(3*b2))/5;
    printf("\tMF: %2.2f\n", mf);
    if (mf>mfa1)
    {
      mfa2 = mfa1;
      mtmfa2 = mtmfa1;
      mfa1 = mf;
      mtmfa1 = mat;
    }
    else
      if (mf>mfa2)
      {
        mfa2 = mf;
        mtmfa2 = mat;
      }
    mb1 += b1;
    mb2 += b2;
    mmf += mf;
    if (mf<70)
      rep++;
  }
  mb1 = mb1/n;
  mb2 = mb2/n;
  mmf = mmf/n;
  printf("\n\tMedias -> B1: %2.2f, B2: %2.2f e MF: %2.2f.\n\tBimestrais mais baixas -> B1: %d - %2.2f e B2: %d - %2.2f.\n\tFinais mais altas -> %d - %2.2f e %d - %2.2f.\n\tAlunos reprovados: %d.", mb1, mb2, mmf, mtb1m, b1m, mtb2m, b2m, mtmfa1, mfa1, mtmfa2, mfa2, rep);
  getch();
}