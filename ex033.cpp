#include <stdio.h>#include <conio.h>
#include <string.h>

// Estruturas
struct registro
{
  int MAT;
  char NOME[30];
  float B1, B2, MF;
};

// Ponteiros
FILE *fp;

// Variáveis
enum banco {VAZIO, PREENCHIDO};
registro tab[100], troca;
int c=0, i, n;
bool enc;

// Protótipos
int menu();
void cadastrar();
void alterar();
void excluir();
void pesquisar();
void carregar();
void salvar();
void limpar();

// Funções
void main()
{
  int op1;

  do
  {
    // Menu
    op1 = menu();
    switch(op1)
    {
      // 1. Cadastrar
      case 1: cadastrar();
              break;

      // 2. Alterar
      case 2: alterar();
              break;

      // 3. Excluir
      case 3: excluir();
              break;

      // 4. Pesquisar
      case 4: pesquisar();
              break;

      // 5. Carregar banco de dados
      case 5: carregar();
              break;

      // 6. Salvar banco de dados
      case 6: salvar();
              break;

      // 7. Limpar banco de dados
      case 7: limpar();
              break;

      // 8. Sair
      case 8: printf("\n\n\tAte mais!\n");
      		  getch();
              break;

      // Outros
      default: printf("\n\n\tDigite uma opcao valida!\n\t[Pressione qualquer tecla para continuar...]\n");
      	      getch();
               break;
    }
  }
  while (op1!=8);
}

// Menu
int menu()
{
  int op, j;

  for (j=0; j<c; j++)
  {
    if ((tab[j].MAT<tab[j+1].MAT))
    {
      troca = tab[j];
      tab[j] = tab[j+1];
      tab[j+1] = troca;
      j = -1;
    }
  }
  n = 0;
  for (j=0; j<c; j++)
    if (tab[j].MAT!=0)
      n++;
  c = n;

  if (c!=0)
    banco = PREENCHIDO;
  else
    banco = VAZIO;

  do
  {
    clrscr();
    printf("\n\t\tControle de Notas\n\n\tBanco de dados: %d\n\tAlunos cadastrados: %d\n\n", banco, c);
    printf("\t\t1. Cadastrar\n\t\t2. Alterar\n\t\t3. Excluir\n\t\t4. Pesquisar\n\t\t5. Carregar banco de dados\n\t\t6. Salvar banco de dados\n\t\t7. Limpar banco de dados\n\t\t8. Sair");
    printf("\n\n\tEscolha a sua opcao: ");
    scanf("%d", &op);
    if ((op<1)||(op>8))
    {
      printf("\n\n\tDigite um valor entre 1 e 8!\n\t[Pressione qualquer tecla para continuar...]\n");
      getch();
    }
  }
  while ((op<1)||(op>8));
  return op;
}

// 1. Cadastrar
void cadastrar()
{
  do
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
    do
    {
      gotoxy(9,8+(i-c)); scanf("%d", &tab[i].MAT);
      if (tab[i].MAT<=0)
      {
        gotoxy(1,20); printf("\tO numero de matricula deve ser positivo!\n\t[Pressione qualquer tecla para continuar...]");
        getch();
        gotoxy(1,20); printf("\t                                   \n\t                                            ");
        gotoxy(49,8+(i-c)); printf("    ");
      }
    }
    while (tab[i].MAT<=0);
    gotoxy(17,8+(i-c)); scanf("%s", &tab[i].NOME);
    do
    {
      gotoxy(49,8+(i-c)); scanf("%f", &tab[i].B1);
      if ((tab[i].B1<0)||(tab[i].B1>100))
      {
        gotoxy(1,20); printf("\tAs notas devem estar entre 0 e 100!\n\t[Pressione qualquer tecla para continuar...]");
        getch();
        gotoxy(1,20); printf("\t                                   \n\t                                            ");
        gotoxy(49,8+(i-c)); printf("    ");
      }
    }
    while ((tab[i].B1<0)||(tab[i].B1>100));
    do
    {
      gotoxy(57,8+(i-c)); scanf("%f", &tab[i].B2);
      if ((tab[i].B2<0)||(tab[i].B2>100))
      {
        gotoxy(1,20); printf("\tAs notas devem estar entre 0 e 100!\n\t[Pressione qualquer tecla para continuar...]");
        getch();
        gotoxy(1,20); printf("\t                                   \n\t                                            ");
        gotoxy(57,8+(i-c)); printf("    ");
      }
    }
    while ((tab[i].B2<0)||(tab[i].B2>100));
    tab[i].MF = (tab[i].B1+tab[i].B2)/2;
    gotoxy(65,8+(i-c)); printf("%2.2f\n\n", tab[i].MF);
  }
  printf("\n\t%d aluno(s) cadastrado(s)!\n", i-c);
  c = i;
  printf("\t%d aluno(s) cadastrado(s) no total!\n\n\t[Pressione qualquer tecla para continuar...]\n", c);
  getch();
}

// 2. Alterar
void alterar()
{
  int mat, op2;
  char nome[30];

  do
  {
    clrscr();
    printf("\n\t\t\tControle de Notas - Alterar\n\n");
    printf("\tPesquisar por matricula ou nome? (1=Matricula, 2=Nome): ");
    scanf("%d", &op2);

    // 4.1. Pesquisar por Matricula
    if (op2==1)
    {
      enc = false;
      printf("\n\tDigite o numero de matricula: ");
      scanf("%d", &mat);
      for (i=0; i<c; i++)
      {
        if (tab[i].MAT==mat)
        {
          enc = true;
          printf("\n\n\tMatricula: %d\n\tNome: %s\n\tB1: %2.2f\n\tB2: %2.2f\n\tMF: %2.2f\n\n", tab[i].MAT, tab[i].NOME, tab[i].B1, tab[i].B2, tab[i].MF);
          printf("\tEntre com os novos valores para a matricula %d: \n\n", tab[i].MAT);
          printf("\tNome: "); scanf("%s", &tab[i].NOME);
          printf("\tB1: "); scanf("%f", &tab[i].B1);
          printf("\tB2: "); scanf("%f", &tab[i].B2);
          tab[i].MF = (tab[i].B1+tab[i].B2)/2;
          printf("\tMF: %2.2f", tab[i].MF);
          printf("\n\n\t[Pressione qualquer tecla para continuar...]\n");
          getch();
        }
      }
      if (enc==false)
      {
        printf("\n\n\tMatricula nao cadastrada!\n\t[Pressione qualquer tecla para continuar...]\n");
        getch();
      }
    }

    // 4.2. Pesquisar por Nome
    else if (op2==2)
    {
      enc = false;
      printf("\n\tDigite o nome: ");
      scanf("%s", &nome);
      for (i=0; i<c; i++)
      {
        if (strcmp(tab[i].NOME,nome)==0)
        {
          enc = true;
          printf("\n\n\tMatricula: %d\n\tNome: %s\n\tB1: %2.2f\n\tB2: %2.2f\n\tMF: %2.2f\n\n", tab[i].MAT, tab[i].NOME, tab[i].B1, tab[i].B2, tab[i].MF);
          printf("\tEntre com os novos valores para a matricula %d: \n\n", tab[i].MAT);
          printf("\tNome: "); scanf("%s", &tab[i].NOME);
          printf("\tB1: "); scanf("%f", &tab[i].B1);
          printf("\tB2: "); scanf("%f", &tab[i].B2);
          tab[i].MF = (tab[i].B1+tab[i].B2)/2;
          printf("\tMF: %2.2f", tab[i].MF);
          printf("\n\n\t[Pressione qualquer tecla para continuar...]\n");
          getch();
        }
      }
      if (enc==false)
      {
        printf("\n\n\tMatricula nao cadastrada!\n\t[Pressione qualquer tecla para continuar...]\n");
        getch();
      }
    }
    else
    {
      printf("\n\tOpcao Invalida!!\n\t[Pressione qualquer tecla para continuar...]");
      getch();
    }
  }
  while ((op2!=1)&&(op2!=2));
}

// 3. Excluir
void excluir()
{
  int mat, op2, op3;
  char nome[30];

  do
  {
    clrscr();
    printf("\n\t\t\tControle de Notas - Excluir\n\n");
    printf("\tPesquisar por matricula ou nome? (1=Matricula, 2=Nome): ");
    scanf("%d", &op2);

    // 4.1. Pesquisar por Matricula
    if (op2==1)
    {
      enc = false;
      printf("\n\tDigite o numero de matricula: ");
      scanf("%d", &mat);
      for (i=0; i<c; i++)
      {
        if (tab[i].MAT==mat)
        {
          enc = true;
          printf("\n\n\tMatricula: %d\n\tNome: %s\n\tB1: %2.2f\n\tB2: %2.2f\n\tMF: %2.2f\n\n", tab[i].MAT, tab[i].NOME, tab[i].B1, tab[i].B2, tab[i].MF);
          printf("\tTem certeza que deseja excluir a matricula %d (1=Sim)? ", tab[i].MAT);
          scanf("%d", &op3);
          if (op3==1)
          {
            tab[i].MAT=0;
            printf("\n\n\tMatricula excluida!\n\t[Pressione qualquer tecla para continuar...]\n");
          }
          getch();
        }
      }
      if (enc==false)
      {
        printf("\n\n\tMatricula nao cadastrada!\n\t[Pressione qualquer tecla para continuar...]\n");
        getch();
      }
    }

    // 4.2. Pesquisar por Nome
    else if (op2==2)
    {
      enc = false;
      printf("\n\tDigite o nome: ");
      scanf("%s", &nome);
      for (i=0; i<c; i++)
      {
        if (strcmp(tab[i].NOME,nome)==0)
        {
          enc = true;
          printf("\n\n\tMatricula: %d\n\tNome: %s\n\tB1: %2.2f\n\tB2: %2.2f\n\tMF: %2.2f\n\n", tab[i].MAT, tab[i].NOME, tab[i].B1, tab[i].B2, tab[i].MF);
          printf("\tTem certeza que deseja excluir a matricula %d (1=Sim)? ", tab[i].MAT);
          scanf("%d", &op3);
          if (op3==1)
          {
            tab[i].MAT=0;
            printf("\n\n\tMatricula excluida!\n\t[Pressione qualquer tecla para continuar...]\n");
          }
          getch();
        }
      }
      if (enc==false)
      {
        printf("\n\n\tMatricula nao cadastrada!\n\t[Pressione qualquer tecla para continuar...]\n");
        getch();
      }
    }
    else
    {
      printf("\n\tOpcao Invalida!!\n\t[Pressione qualquer tecla para continuar...]");
      getch();
    }
  }
  while ((op2!=1)&&(op2!=2));
}

// 4. Pesquisar
void pesquisar()
{
  int mat, op2;
  char nome[30];

  do
  {
    clrscr();
    printf("\n\t\t\tControle de Notas - Pesquisar\n\n");
    printf("\tPesquisar por matricula ou nome? (1=Matricula, 2=Nome): ");
    scanf("%d", &op2);

    // 4.1. Pesquisar por Matricula
    if (op2==1)
    {
      enc = false;
      printf("\n\tDigite o numero de matricula: ");
      scanf("%d", &mat);
      for (i=0; i<c; i++)
      {
        if (tab[i].MAT==mat)
        {
          enc = true;
          printf("\n\n\tMatricula: %d\n\tNome: %s\n\tB1: %2.2f\n\tB2: %2.2f\n\tMF: %2.2f\n\n", tab[i].MAT, tab[i].NOME, tab[i].B1, tab[i].B2, tab[i].MF);
          printf("\t[Pressione qualquer tecla para continuar...]\n");
          getch();
        }
      }
      if (enc==false)
      {
        printf("\n\n\tMatricula nao cadastrada!\n\t[Pressione qualquer tecla para continuar...]\n");
        getch();
      }
    }

    // 4.2. Pesquisar por Nome    else if (op2==2)
    {
      enc = false;
      printf("\n\tDigite o nome: ");
      scanf("%s", &nome);
      for (i=0; i<c; i++)
      {
        if (strcmp(tab[i].NOME,nome)==0)
        {
          enc = true;
          printf("\n\n\tMatricula: %d\n\tNome: %s\n\tB1: %2.2f\n\tB2: %2.2f\n\tMF: %2.2f\n\n", tab[i].MAT, tab[i].NOME, tab[i].B1, tab[i].B2, tab[i].MF);
          printf("\t[Pressione qualquer tecla para continuar...]\n");
          getch();
        }
      }
      if (enc==false)
      {
        printf("\n\n\tMatricula nao cadastrada!\n\t[Pressione qualquer tecla para continuar...]\n");
        getch();
      }
    }
    else
    {
      printf("\n\tOpcao Invalida!!\n\t[Pressione qualquer tecla para continuar...]");
      getch();
    }
  }
  while ((op2!=1)&&(op2!=2));
}

// 5. Carregar banco de dados
void carregar()
{
  if((fp=fopen("banco.dat","r"))==NULL)
    printf("\n\n\tNao e possivel abrir o banco de dados!\n\t[Pressione qualquer tecla para continuar...]\n");
  else
  {
    fscanf(fp, "%d", &c);
    for(i=0; i<c; i++)
    {
      fscanf(fp, "%d", &tab[i].MAT);
      fscanf(fp, "%s", &tab[i].NOME);
      fscanf(fp, "%f", &tab[i].B1);
      fscanf(fp, "%f", &tab[i].B2);
      fscanf(fp, "%f", &tab[i].MF);
    }
    fclose(fp);
    printf("\n\n\tBanco de dados carregado!\n\t[Pressione qualquer tecla para continuar...]\n");
  }
  getch();
}

// 6. Salvar banco de dados
void salvar()
{
  if((fp=fopen("banco.dat","w"))==NULL)
    printf("\n\n\tNao e possivel abrir o banco de dados!\n\t[Pressione qualquer tecla para continuar...]\n");
  else
  {
    fprintf(fp, "%d ", c);
    for(i=0; i<c; i++)
    {
      fprintf(fp, "%d ", tab[i].MAT);
      fprintf(fp, "%s ", tab[i].NOME);
      fprintf(fp, "%f ", tab[i].B1);
      fprintf(fp, "%f ", tab[i].B2);
      fprintf(fp, "%f ", tab[i].MF);
    }
    fclose(fp);
    printf("\n\n\tBanco de dados salvo!\n\t[Pressione qualquer tecla para continuar...]\n");
  }
  getch();
}


// 7. Limpar banco de dados
void limpar()
{
  if((fp=fopen("banco.dat","w"))==NULL)
    printf("\n\n\tNao e possivel abrir o banco de dados!\n\t[Pressione qualquer tecla para continuar...]\n");
  else
  {
    for(i=0; i<c; i++)
    {
      tab[i].MAT = 0;
    }
    fclose(fp);
    printf("\n\n\tBanco de dados limpo!\n\t[Pressione qualquer tecla para continuar...]\n");
  }
  getch();
}
