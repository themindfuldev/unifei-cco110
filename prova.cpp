#include <stdio.h>
#include <conio.h>

void main()
{
  // Variaveis
  char nome[30][100];
  float b1[100], b2[100], mf[100];
  int c=0, ex, i, n, op, mat[100], menu;

  do
  {

    // Menu
    do
    {
      clrscr();
      printf("\n\t\t\tControle de Notas\n\n");
      printf("\t\t1. Cadastrar\n\t\t2. Alterar\n\t\t3. Excluir\n\t\t4. Pesquisar\n\t\t5. Sair");
      printf("\n\n\tEscolha a sua opcao: ");
      scanf("%d", &op);
      if ((op<1)||(op>5))
      {
        printf("\n\n\tDigite um valor entre 1 e 5!\n\t[Pressione qualquer tecla para continuar...]\n");
        getch();
      }
    }
    while ((op<1)||(op>5));
    switch(op)
    {

      // 1. Cadastrar
      case 1: do
              {
                clrscr();
                printf("\n\t\t\tControle de Notas - Cadastrar\n\n");
                printf("\tQuantas matriculas deseja cadastrar? ");
                scanf("%d", &n);
                if ((n<1)||(n>100-c))
                {
                  printf("\n\n\tDigite um valor entre 1 e %d!\n\t[Pressione qualquer tecla para continuar...]\n", 100-c);
                  getch();
                }
              }
              while ((n<1)||(n>100));
              printf("\n\tMAT\tNOME\t\t\t\tB1\tB2\t  MF\n");
              for (i=c; i<n+c; i++)
              {
                gotoxy(9,8+(i-c)); scanf("%d", &mat[i]);
                gotoxy(17,8+(i-c)); scanf("%s", &nome[i]);
                gotoxy(49,8+(i-c)); scanf("%f", &b1[i]);
                gotoxy(57,8+(i-c)); scanf("%f", &b2[i]);
                mf[i] = (b1[i]+b2[i])/2;
                gotoxy(65,8+(i-c)); printf("%2.2f\n\n", mf[i]);
              }
              printf("\n\t%d aluno(s) cadastrado(s)!\n", i-c);
              c = i;
              printf("\t%d aluno(s) cadastrado(s) no total!\n\n\t[Pressione qualquer tecla para continuar...]\n", c);
              getch();
              break;

      // 2. Alterar
      case 2: clrscr();
              printf("\n\t\t\tControle de Notas - Alterar\n\n");
              printf("\tDigite o numero de matricula: ");
              scanf("%d", &menu);
              for (i=0; i<c; i++)
              {
                if (mat[i]==menu)
                {
                  printf("\n\n\tMatricula: %d\n\tNome: %s\n\tB1: %2.2f\n\tB2: %2.2f\n\tMF: %2.2f\n\n", mat[i], nome[i], b1[i], b2[i], mf[i]);
                  printf("\tEntre com os novos valores para a matricula %d: \n\n", mat[i]);
                  printf("\tNome: "); scanf("%s", &nome[i]);
                  printf("\tB1: "); scanf("%f", &b1[i]);
                  printf("\tB2: "); scanf("%f", &b2[i]);
                  mf[i] = (b1[i]+b2[i])/2;
                  printf("\tMF: %2.2f", mf[i]);
                  printf("\n\n\t[Pressione qualquer tecla para continuar...]\n");
                  getch();
                  break;                  
                }
                else if (i==c-1)
                {
                  printf("\n\n\tMatricula nao cadastrada!\n\t[Pressione qualquer tecla para continuar...]\n");
                  getch();
                }
              }
              break;

      // 3. Excluir
      case 3: clrscr();
              printf("\n\t\t\tControle de Notas - Excluir\n\n");
              printf("\tDigite o numero de matricula: ");
              scanf("%d", &menu);
              for (i=0; i<c; i++)
              {
                if (mat[i]==menu)
                {
                  printf("\n\n\tMatricula: %d\n\tNome: %s\n\tB1: %2.2f\n\tB2: %2.2f\n\tMF: %2.2f\n\n", mat[i], nome[i], b1[i], b2[i], mf[i]);
                  printf("\tTem certeza que deseja excluir a matricula %d (digite 1 caso sim)? ", mat[i]);
                  scanf("%d", &ex);
                  if (ex==1)
                  {
                    mat[i]=0;
                    b1[i]=0;
                    b2[i]=0;
                    mf[i]=0;
                  }
                  printf("\n\n\tMatricula excluida!\n\t[Pressione qualquer tecla para continuar...]\n");
                  getch();
                  break;
                }
                else if (i==c-1)
                {
                  printf("\n\n\tMatricula nao cadastrada!\n\t[Pressione qualquer tecla para continuar...]\n");
                  getch();
                }
              }
              break;

      // 4. Pesquisar
      case 4: clrscr();
              printf("\n\t\t\tControle de Notas - Pesquisar\n\n");
              printf("\tDigite o numero de matricula: ");
              scanf("%d", &menu);
              for (i=0; i<c; i++)
              {
                if (mat[i]==menu)
                {
                  printf("\n\n\tMatricula: %d\n\tNome: %s\n\tB1: %2.2f\n\tB2: %2.2f\n\tMF: %2.2f\n\n", mat[i], nome[i], b1[i], b2[i], mf[i]);
                  printf("\t[Pressione qualquer tecla para continuar...]\n");
                  getch();
                  break;
                }
                else if (i==c-1)
                {
                  printf("\n\n\tMatricula nao cadastrada!\n\t[Pressione qualquer tecla para continuar...]\n");
                  getch();
                }
              }
              break;

      // 5. Sair
      case 5: printf("\n\n\tAte mais!\n");
      		  getch();
              break;

      // Outros
      default: printf("\n\n\tDigite uma opcao valida!\n\t[Pressione qualquer tecla para continuar...]\n");
    		  	   getch();
               break;
    }
  }
  while (op!=5);
}