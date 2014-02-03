#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>

// Definição de tipos locais
typedef struct Data
{
	int Ano;
	int Mes;
	int Dia;
}Data;
typedef struct DadosReg
{
	int Matricula;
	char Nome[16];
	char Raca[16];
	int AnoReg;
}DadosReg;
typedef struct CaoB
{
   DadosReg Dados;
  	Data DataNasc;
	CaoB *ProxB;
}CaoB;
typedef struct CaoA
{
	DadosReg Dados;
  	Data DataNasc;
   CaoA *ProxA;
   CaoB *ProxB;
}CaoA;

// Protótipos das funções
int MenuCaes(void);
CaoA *alocaCaoA(void);
CaoB *alocaCaoB(void);
void insereCaoMestre(CaoA *&caesM);
void insereCaoParente(CaoA *caesM, CaoA *caoAux);
CaoA *PesquisaMat(CaoA *CaesM, int &verPar);
void removePar(CaoB *caoPar, CaoA *caoM);
void removeMestre(CaoA *&caoMestre, CaoA *&caesM);
CaoB *mostraPar(CaoA *caoMestre, int &verPar2);
void imprimeTudo(CaoA *caesM);
void LiberaMemoria(CaoA *&caesM);
void salva(CaoA *caesM);
CaoA *carrega(CaoA *caesM);


// Função main
void main ()
{
	// Definição das variáveis
	CaoA *caesMestres=NULL, *caoAux;
   CaoB *caoAux2;
   int Opcao=0, verPar, verPar2;

   // Início do programa
   while (Opcao!=8)
   {
     	Opcao = MenuCaes();
      switch (Opcao)
      {
        	case 1 : // Insere um novo cao mestre
      	     	insereCaoMestre(caesMestres);
        			if (!caesMestres)
               {
        				printf("\n\tERRO: Nao foi possível alocar o registro na memória.\n\t[Pressione qualquer tecla para continuar...]\n");
           			getch();
					}// Fim if
           		break;

	     	case 2 : // Insere um novo cao parente a partir da matricula do mestre
					if (!caesMestres)
               {
        				printf("\n\tERRO: Nenhum cao mestre encontrado.\n\t[Pressione qualquer tecla para continuar...]\n");
           			getch();
					}
               else
               {
                  caoAux=PesquisaMat(caesMestres,verPar);
                  if (verPar==1)
                  {
	                 	insereCaoParente(caesMestres,caoAux);
                  }
                  else
                  {
                  	printf("\n\tERRO: Matricula nao encontrada.\n\t[Pressione qualquer tecla para continuar...]\n");
     	               getch();
                  }
               }
            	break;

         case 3 : // Remove um cão mestre e a sua família
					if (!caesMestres)
               {
        				printf("\n\tERRO: Nenhum cao mestre encontrado.\n\t[Pressione qualquer tecla para continuar...]\n");
           			getch();
					}
               else
               {
                  caoAux=PesquisaMat(caesMestres,verPar);
                  if (verPar==1)
                  {
	                 	removeMestre(caoAux,caesMestres);
                  }
                  else
                  {
                  	printf("\n\tERRO: Matricula nao encontrada.\n\t[Pressione qualquer tecla para continuar...]\n");
     	               getch();
                  }
               }
            	break;

         case 4 : // Remove um cão parente
					if (!caesMestres)
               {
        				printf("\n\tERRO: Nenhum cao mestre encontrado.\n\t[Pressione qualquer tecla para continuar...]\n");
           			getch();
					}
               else
               {
                  caoAux=PesquisaMat(caesMestres,verPar);
                  if (verPar==1)
                  {
                     caoAux2=mostraPar(caoAux, verPar2);
                     if (verPar2==1)
                     {
                       removePar(caoAux2, caoAux);
                     }
                     else
                     {
                       printf("\n\tERRO: Nenhum parente foi encontrado.\n\t[Pressione qualquer tecla para continuar...]\n");
                       getch();
                     }
                  }
                  else
                  {
                  	printf("\n\tERRO: Matricula nao encontrada.\n\t[Pressione qualquer tecla para continuar...]\n");
     	               getch();
                  }
               }
            	break;


         case 5: // Lista todos os cães e seus parentes
               if (!caesMestres)
               {
        				printf("\n\tERRO: Nenhum cao mestre encontrado.\n\t[Pressione qualquer tecla para continuar...]\n");
           			getch();
					}
               else
                	imprimeTudo(caesMestres);
            	break;

         case 6: // Salva os dados em CAES.DAT
               if (!caesMestres)
               {
        				printf("\n\tERRO: Nenhum cao mestre encontrado.\n\t[Pressione qualquer tecla para continuar...]\n");
           			getch();
					}
               else
                	salva(caesMestres);
            	break;

         case 7: // Carrega os dados de CAES.DAT
              	caesMestres=carrega(caesMestres);
            	break;

			case 8 : // Finaliza o programa
               LiberaMemoria(caesMestres);
					printf("\n\t[Pressione qualquer tecla para continuar...]\n");
					getch();
         		break;

         default : // Escolha inválida
               printf("\n\tERRO: Escolha invalida!\n\t[Pressione qualquer tecla para continuar...]\n");
           		getch();

         }
     	}
}

//	Função MenuCaes: Imprime as opções do menu e retorna a opção escolhida
int MenuCaes()
{
	int Opcao;
   do
   {
     clrscr();
     printf("\n     Trabalho Final de CCO110\n\n");
  	  printf("\tAndre Carvalho Silveira         12616   CCO 2004\n");
  	  printf("\tThiago Felipe de Mello Matias   12642   CCO 2004\n");
     printf("\tTiago Romero Garcia             12643   CCO 2004\n");
     printf("\n     Menu de opcoes:\n");
     printf("\n\t1. Inserir cao mestre.");
     printf("\n\t2. Inserir caes parentes.");
     printf("\n\t3. Remover um cao mestre.");
  	  printf("\n\t4. Remover um cao parente.");
     printf("\n\t5. Listar todos os caes e seus parentes.");
     printf("\n\t6. Salvar os dados em CAES.DAT.");
  	  printf("\n\t7. Carregar os dados de CAES.DAT.");
     printf("\n\t8. Sair do programa.");
     printf("\n\n     Escolha sua opcao: ");
     scanf("%d", &Opcao);
     if ((Opcao<1)||(Opcao>8)) {
       printf("\n\tERRO: Escolha invalida!\n\t[Pressione qualquer tecla para continuar...]\n");
       getch();
     }
   }
   while ((Opcao<1)||(Opcao>8));
   return Opcao;
}

//	Função *alocaCaoA: Reserva dinamicamente memória para a struct do tipo CaoA
CaoA *alocaCaoA()
{
   CaoA *caoNovo;
	caoNovo = (CaoA *)malloc(1*sizeof(struct CaoA));
   caoNovo->ProxA=NULL;
   caoNovo->ProxB=NULL;
   return caoNovo;
}

// Função *alocaCaoB: Reserva dinamicamente memória para a struct do tipo CaoB
CaoB *alocaCaoB(void)
{
   CaoB *caoNovo;
	caoNovo = (CaoB *)malloc(1*sizeof(struct CaoB));
   caoNovo->ProxB=NULL;
   return caoNovo;
}

//	Função insereCaoMestre:	Insere um novo cão mestre na lista de mestres
void insereCaoMestre(CaoA *&caesM)
{
   // Declaração de variáveis
   struct date dataAtual;
   int y=4,r1,r2;
   CaoA *cao, *caesMats;
   CaoB *caesMatsB;

   clrscr();
   printf("\n     Trabalho Final de CCO110 - Inserir cao mestre\n\n");

   // Alocação do novo cão
   cao=alocaCaoA();
   if (cao==NULL)
   {
      printf("\n\tERRO: Nao houve memoria para o cao mestre.\n\t[Pressione qualquer tecla para continuar...]\n");
      getch();
      return;
   }

   // Inserindo na lista
   cao->ProxA=caesM;
   caesM=cao;

   // Coleta dos dados
   printf("     Dados do novo Cao Mestre:\n\n");
   y+=2;
	printf("\tDigite a matricula do cao: ");
   scanf("%d",&cao->Dados.Matricula);

   // Verificação de matrícula existente
 	while(cao->Dados.Matricula<=0)
   {
     gotoxy(1,y);
     clreol();
     printf("\tMatricula invalida, digite outra matricula: ");
     scanf("%d",&cao->Dados.Matricula);
  	}
   do
   {
	   r2=0;
      caesMats=cao;
      caesMats=caesMats->ProxA;
		if(caesMats==NULL)
	   {
      	r1=1;
         r2=1;
      }
		else
	      r1=0;
	   while (caesMats!=NULL)
   	{
	   	if(caesMats->Dados.Matricula==cao->Dados.Matricula)
	      {
		      gotoxy(1,y);
   		   clreol();
				printf("\tMatricula ja existente, digite outra matricula: ");
	         scanf("%d",&cao->Dados.Matricula);
   	      r1=0;
            break;
      	}
	      else
   	   {
            r1=1;
      	   caesMatsB=caesMats->ProxB;
	     		if(caesMatsB==NULL)
			   	r2=1;
      		while(caesMatsB!=NULL)
		      {
   	         if(cao->Dados.Matricula==caesMatsB->Dados.Matricula)
	  		      {
	   			   gotoxy(1,y);
		   		   clreol();
						printf("\tMatricula ja existente, digite outra matricula: ");
		  	         scanf("%d",&cao->Dados.Matricula);
						r2=0;
      			}
	            else
   	         	r2=1;
               if(r2==0)
               	caesMatsB=NULL;
               else
               	caesMatsB=caesMatsB->ProxB;
         	}
	      }
         if(r1==0)
          	caesMats=NULL;
         else
  			   caesMats=caesMats->ProxA;
	   }
   } while ((r1==0)||(r2==0));
   y++;
   printf("\tDigite o nome do cao (15 caracteres): ");
   scanf(" %[^\n]",&cao->Dados.Nome);
   y++;
   printf("\tInserindo a data de nascimento\n");
   y++;
   do
   {
      gotoxy(1,y);
      clreol();
	   printf("\t  Digite o dia(1-31): ");
	   scanf("%d",&cao->DataNasc.Dia);
   } while((cao->DataNasc.Dia<1)||(cao->DataNasc.Dia>31));
	y++;
   do
   {
      gotoxy(1,y);
      clreol();
   	printf("\t  Digite o mes(1-12): ");
	   scanf("%d",&cao->DataNasc.Mes);
	} while((cao->DataNasc.Mes<1)||(cao->DataNasc.Mes>12));
   y++;
   getdate(&dataAtual);
	// Ano de nascimento poderá ser até 30 anos anterior ao atual
   do
   {
      gotoxy(1,y);
      clreol();
	   printf("\t  Digite o ano(%d-%d): ",(dataAtual.da_year)-30,dataAtual.da_year);
   	scanf("%d",&cao->DataNasc.Ano);
   } while(((cao->DataNasc.Ano) < (dataAtual.da_year)-30) || ((cao->DataNasc.Ano) > (dataAtual.da_year)));
   y++;
   printf("\tDigite a raca do cao (15 caracteres): ");
	scanf(" %[^\n]",&cao->Dados.Raca);
   y++;
   do
   {
      gotoxy(1,y);
      clreol();
	  	printf("\tDigite o ano de registro(%d-%d): ",cao->DataNasc.Ano,dataAtual.da_year);
   	scanf("%d",&cao->Dados.AnoReg);
   } while((cao->Dados.AnoReg < cao->DataNasc.Ano) || (cao->Dados.AnoReg > dataAtual.da_year));
   printf("\n\n\tFim da insercao.\n\t[Pressione qualquer tecla para continuar...]\n");
   getch();
}

// Função *PesquisaMat: Função para pesquisar a matrícula de um cao mestre
CaoA *PesquisaMat(CaoA *caesM, int &verPar)
{
   // Declaração de variáveis
   CaoA *caesAux, *caoAux;
   int mats,matP;

 	clrscr();
   printf("\n     Trabalho Final de CCO110 - Localizar cao mestre\n\n");

   // Impressão das matriculas existentes
  	printf("     Matriculas existentes:\n");
   caesAux=caesM;
  	mats=1;
   while(caesAux!=NULL)
	{
      if ((mats-1)%3==0) printf("\n\t");
		printf("Mestre %3d: %4d | ",mats,caesAux->Dados.Matricula);
		caesAux=caesAux->ProxA;
   	mats++;
  	}

   // Leitura da matricula do mestre
  	printf("\n\n     Digite a matricula do mestre: ");
   scanf("%d",&matP);
	caesAux=caesM;
  	verPar=0;
   while((caesAux!=NULL)&&(verPar==0))
	{
     	if(caesAux->Dados.Matricula==matP)
      {
  	      caoAux=caesAux;
     	   verPar=1;
      }
  	   else
     	{
	      caesAux=caesAux->ProxA;
  	   }
   }
   return caoAux;
}

// Função insereCaoParente: Insere um parente na fila de um determinado mestre.
void insereCaoParente(CaoA *caesM, CaoA *caoAux)
{
   // Declaração de variáveis
   struct date dataAtual;
   int y=4,r1,r2;
   CaoA *caesMats;
   CaoB *cao, *caesMatsB;

   clrscr();
   printf("\n     Trabalho Final de CCO110 - Inserir cao parente\n\n");

   // Alocação do novo cão
   cao=alocaCaoB();
   if (cao==NULL)
   {
      printf("\n\tERRO: Nao houve memoria para o cao mestre.\n\t[Pressione qualquer tecla para continuar...]\n");
      getch();
      return;
   }

   // Inserindo na lista
	cao->ProxB=caoAux->ProxB;
   caoAux->ProxB=cao;

   // Coleta dos dados
   printf("     Dados do novo Cao Parente\n\n");
   y+=2;
	printf("\tDigite a matricula do cao: ");
   scanf("%d",&cao->Dados.Matricula);

   // Verificação de matrícula existente
 	while(cao->Dados.Matricula<=0)
   {
     gotoxy(1,y);
     clreol();
     printf("\tMatricula invalida, digite outra matricula: ");
     scanf("%d",&cao->Dados.Matricula);
  	}
   do
   {
	   r2=0;
      caesMats=caesM;
		if(caesMats==NULL)
	   {
      	r1=1;
         r2=1;
      }
		else
	      r1=0;
	   while (caesMats!=NULL)
   	{
	   	if(caesMats->Dados.Matricula==cao->Dados.Matricula)
	      {
		      gotoxy(1,y);
   		   clreol();
				printf("\tMatricula ja existente, digite outra matricula: ");
	         scanf("%d",&cao->Dados.Matricula);
   	      r1=0;
            break;
      	}
	      else
   	   {
            r1=1;
      	   caesMatsB=caesMats->ProxB;
	     		if(caesMatsB==NULL)
			   	r2=1;
      		while(caesMatsB!=NULL)
		      {
   	         if((cao->Dados.Matricula==caesMatsB->Dados.Matricula)&&(cao!=caesMatsB))
	  		      {
	   			   gotoxy(1,y);
		   		   clreol();
						printf("\tMatricula ja existente, digite outra matricula: ");
		  	         scanf("%d",&cao->Dados.Matricula);
						r2=0;
      			}
	            else
   	         	r2=1;
               if(r2==0)
               	caesMatsB=NULL;
               else
               	caesMatsB=caesMatsB->ProxB;
         	}
	      }
         if(r1==0)
          	caesMats=NULL;
         else
  			   caesMats=caesMats->ProxA;
	   }
   } while ((r1==0)||(r2==0));
   y++;
   printf("\tDigite o nome do cao (15 caracteres): ");
   scanf(" %[^\n]",&cao->Dados.Nome);
   y++;
   printf("\tInserindo a data de nascimento\n");
   y++;
   do
   {
      gotoxy(1,y);
      clreol();
	   printf("\t  Digite o dia(1-31): ");
	   scanf("%d",&cao->DataNasc.Dia);
   } while((cao->DataNasc.Dia<1)||(cao->DataNasc.Dia>31));
	y++;
   do
   {
      gotoxy(1,y);
      clreol();
   	printf("\t  Digite o mes(1-12): ");
	   scanf("%d",&cao->DataNasc.Mes);
	} while((cao->DataNasc.Mes<1)||(cao->DataNasc.Mes>12));
   y++;
   getdate(&dataAtual);
	// Ano de nascimento poderá ser até 30 anos anterior ao atual
   do
   {
      gotoxy(1,y);
      clreol();
	   printf("\t  Digite o ano(%d-%d): ",(dataAtual.da_year)-30,dataAtual.da_year);
   	scanf("%d",&cao->DataNasc.Ano);
   } while(((cao->DataNasc.Ano) < (dataAtual.da_year)-30) || ((cao->DataNasc.Ano) > (dataAtual.da_year)));
   y++;
   printf("\tDigite a raca do cao (15 caracteres): ");
	scanf(" %[^\n]",&cao->Dados.Raca);
   y++;
   do
   {
      gotoxy(1,y);
      clreol();
	  	printf("\tDigite o ano de registro(%d-%d): ",cao->DataNasc.Ano,dataAtual.da_year);
   	scanf("%d",&cao->Dados.AnoReg);
   } while((cao->Dados.AnoReg < cao->DataNasc.Ano) || (cao->Dados.AnoReg > dataAtual.da_year));
   printf("\n\n\tFim da insercao.\n\t[Pressione qualquer tecla para continuar...]\n");
   getch();
}

// Função removePar: Remove um cão parente
void removePar(CaoB *caoPar, CaoA *caoM)
{
   // Declaração de variaveis
   CaoB *caoProx, *cao;

   // Impressão
   clrscr();
   printf("\n     Trabalho Final de CCO110 - Excluir cao parente\n\n");
   printf("     Dados do cao parente a ser retirado:\n\n");
   printf("\tMatricula: %d\n", caoPar->Dados.Matricula);
   printf("\tNome: %s\n", caoPar->Dados.Nome);
   printf("\tRaca: %s\n", caoPar->Dados.Raca);
   printf("\tData de Nascimento: %d/%d/%d\n", caoPar->DataNasc.Dia,caoPar->DataNasc.Mes,caoPar->DataNasc.Ano);
   printf("\tAno de Registro: %d\n", caoPar->Dados.AnoReg);

   // Remoção do parente
   caoProx=caoPar->ProxB;
   if (caoM->ProxB==caoPar)
     caoM->ProxB=caoProx;
   else
   {
     cao=caoM->ProxB;
     while (cao!=NULL)
     {
       if (cao->ProxB==caoPar)
         cao->ProxB=caoProx;
       cao=cao->ProxB;
     }
   }
   free(caoPar);
   printf("\n     Cao retirado com sucesso.\n\t[Pressione qualquer tecla para continuar...]\n");
   getch();
}

// Função removeMestre: Remove um cão mestre
void removeMestre(CaoA *&caoMestre, CaoA *&caesM)
{
   // Declaração de variaveis
	CaoA *caoMP;
   CaoB *caoProx, *cao;
   int par=0;

   // Impressão dos resultados
   clrscr();
   printf("\n     Trabalho Final de CCO110 - Remover cao mestre\n\n");
   printf("     Dados do cao mestre a ser retirado\n\n");
   printf("\tMatricula: %d\n", caoMestre->Dados.Matricula);
   printf("\tNome: %s\n", caoMestre->Dados.Nome);
   printf("\tRaca: %s\n",caoMestre->Dados.Raca);
  	printf("\tData de Nascimento: %d/%d/%d\n", caoMestre->DataNasc.Dia,caoMestre->DataNasc.Mes,caoMestre->DataNasc.Ano);
   printf("\tAno de Registro: %d\n", caoMestre->Dados.AnoReg);

   // Remoção dos parentes
   caoProx=caoMestre->ProxB;
   cao=caoMestre->ProxB;
   if (cao!=NULL)
   {
     while (caoProx!=NULL)
     {
       cao=caoProx;
       caoProx=cao->ProxB;
       free(cao);
       par++;
     }
   }

   // Remoção do cão mestre
   caoMP=caesM;
   if (caoMP==caoMestre)
     caesM=caoMP->ProxA;
   else
     while (caoMP!=NULL)
     {
       if (caoMP->ProxA==caoMestre)
         caoMP->ProxA=caoMestre->ProxA;
       caoMP=caoMP->ProxA;
     }
   free(caoMestre);

   printf("\n     Cao retirado com sucesso.");
   if (par>0)
     printf("\n     Foram retirados %d caes parentes a este cao.", par);
   printf("\n     [Pressione qualquer tecla para continuar...]\n");
   getch();
}

// Função LiberaMemoria: Libera para a memória os cães alocados anteriormente
void LiberaMemoria(CaoA *&caesM)
{
	// Declaração de variaveis
   CaoA *caoMes;
   CaoB *caoPar;

   // Liberação da memória
   if(caesM==NULL)
   {
   	printf("\n\tNao haviam caes mestres a serem liberados.");
      return;
   }
   caoMes=caesM;
   while(caoMes!=NULL)
   {
	   caoPar=caoMes->ProxB;
   	while(caoPar!=NULL)
	   {
      	caoMes->ProxB=caoPar->ProxB;
         caoPar->ProxB==NULL;
         free(caoPar);
         caoPar=caoMes->ProxB;
	   }
      caesM=caoMes->ProxA;
		caoMes->ProxA=NULL;
		free(caoMes);
      caoMes=caesM;
   }
   caesM=NULL;
   printf("\n\tMemoria Liberada.");
}

// Função imprimeTudo: Imprime todos os cães
void imprimeTudo(CaoA *caesM)
{
   //variaveis
	CaoB *CaoPar;
   int nPar,nMes,y;

   //exibição dos parentes
	nMes=0;
   while	(caesM!=NULL)
   {
      nPar=0;
      nMes++;
		clrscr();
	   y=1;
      printf("\n     Trabalho Final de CCO110 - Exibir todos os caes\n\n");
		y+=2;
  		printf("Cao mestre numero %d:\n", nMes);
		y+=2;
	   printf("  Matricula: %11d", caesM->Dados.Matricula);
     	gotoxy(30,y);
  		printf("Nome: %s\n", caesM->Dados.Nome);
  		gotoxy(55,y);
 		printf("Ano Reg: %d\n", caesM->Dados.AnoReg);
  		y++;
	  	printf("  Nascimento: %2d/%2d/%d", caesM->DataNasc.Dia,caesM->DataNasc.Mes,caesM->DataNasc.Ano);
  		gotoxy(30,y);
      printf("Raca: %s\n", caesM->Dados.Raca);
      y++;
		printf("--------------------------------------------------------------------------------");
      y++;
      CaoPar=caesM->ProxB;
	   while (CaoPar!=NULL)
   	{
         if ((nPar%4==0)&&(nPar!=1))
         {
		      clrscr();
		    	y=1;
            printf("\n     Trabalho Final de CCO110 - Exibir todos os caes\n\n");
            y+=2;
  				printf(" Cao mestre numero %d:\n", nMes);
		      y+=2;
			   printf("  Matricula: %11d", caesM->Dados.Matricula);
      		gotoxy(30,y);
		  		printf("Nome: %s\n", caesM->Dados.Nome);
      		gotoxy(55,y);
		  		printf("Ano Reg: %d\n", caesM->Dados.AnoReg);
      		y++;
			  	printf("  Nascimento: %2d/%2d/%d", caesM->DataNasc.Dia,caesM->DataNasc.Mes,caesM->DataNasc.Ano);
      		gotoxy(30,y);
		      printf("Raca: %s\n", caesM->Dados.Raca);
		      y++;
				printf("--------------------------------------------------------------------------------");
		      y++;
         }
         nPar++;
  			printf(" Cao parente numero %d:\n", nPar);
	      y++;
	   	printf("  Matricula: %11d", CaoPar->Dados.Matricula);
   	   gotoxy(30,y);
	  		printf("Nome: %s\n", CaoPar->Dados.Nome);
   	   gotoxy(55,y);
	  		printf("Ano Reg: %d\n", CaoPar->Dados.AnoReg);
   	   y++;
		  	printf("  Nascimento: %2d/%2d/%d", CaoPar->DataNasc.Dia,CaoPar->DataNasc.Mes,CaoPar->DataNasc.Ano);
      	gotoxy(30,y);
   	   printf("Raca: %s\n", CaoPar->Dados.Raca);
	      y++;
			printf("--------------------------------------------------------------------------------");
	      y++;
         CaoPar=CaoPar->ProxB;
         if ((nPar%4==0)&&(CaoPar!=NULL))
         {
         	printf("\n     [Para imprimir o restante dos parentes pressione qualquer tecla...]\n");
            getch();
         }
      }
      if (caesM->ProxA!=NULL)
  	  	{
			printf("\n     [Para ver o proximo mestre pressione qualquer tecla...]\n");
   	}
      else
      {
      	printf("\n     Este foi o ultimo mestre encontrado.\n\t[Pressione qualquer tecla para continuar...]\n");
      }
      caesM=caesM->ProxA;
      getch();
   }
}

// Função mostraPar: Exibe os parentes de um determinado mestre
CaoB *mostraPar(CaoA *caoMestre, int &verPar2)
{
   // Declaração de variaveis
	CaoB *CaoPar, *CaoAux;
   int mats=1, matP;

   // Exibição dos parentes
	CaoPar=caoMestre->ProxB;
   if(CaoPar==NULL)
   {
      verPar2=0;
      return CaoPar;
   }
   while (CaoPar!=NULL)
   {
      if ((mats-1)%3==0) printf("\n\t");
	   printf("Parente %d: %4d | ", mats, CaoPar->Dados.Matricula);
      CaoPar=CaoPar->ProxB;
      mats++;
   }

   // Leitura da matricula do parente
  	printf("\n\n     Digite a matricula do parente: ");
   scanf("%d",&matP);
	CaoPar=caoMestre->ProxB;
  	verPar2=0;
   while((CaoPar!=NULL)&&(verPar2==0))
	{
     	if(CaoPar->Dados.Matricula==matP)
      {
  	      CaoAux=CaoPar;
     	   verPar2=1;
      }
  	   else
     	{
	      CaoPar=CaoPar->ProxB;
  	   }
   }
   return CaoAux;
}

void salva(CaoA *caesM)
{
  CaoA *caoM;
  CaoB *caoP;
  FILE *fp;

  caoM=caesM;
  if((fp=fopen("CAES.DAT","w"))==NULL)
  {
    printf("\n\tERRO: Nao e possivel abrir CAES.DAT!\n\t[Pressione qualquer tecla para continuar...]\n");
    getch();
  }
  else
  {
    fprintf(fp, "-1 ");  // Digito de controle: 0=vazio, -1=cheio
    while(caoM!=NULL)
    {
      fprintf(fp, "%d ", caoM->Dados.Matricula);
      fprintf(fp, "%s ", caoM->Dados.Nome);
      fprintf(fp, "%s ", caoM->Dados.Raca);
      fprintf(fp, "%d ", caoM->Dados.AnoReg);
      fprintf(fp, "%d ", caoM->DataNasc.Ano);
      fprintf(fp, "%d ", caoM->DataNasc.Mes);
      fprintf(fp, "%d ", caoM->DataNasc.Dia);
      caoP=caoM->ProxB;
      while (caoP!=NULL)
      {
        fprintf(fp, "%d ", caoP->Dados.Matricula);
        fprintf(fp, "%s ", caoP->Dados.Nome);
        fprintf(fp, "%s ", caoP->Dados.Raca);
        fprintf(fp, "%d ", caoP->Dados.AnoReg);
        fprintf(fp, "%d ", caoP->DataNasc.Ano);
        fprintf(fp, "%d ", caoP->DataNasc.Mes);
        fprintf(fp, "%d ", caoP->DataNasc.Dia);
        caoP=caoP->ProxB;
      }
      fprintf(fp, "0 ");
      caoM=caoM->ProxA;
    }
    fprintf(fp, "0");
    printf("\n\tDados salvos com sucesso.\n\t[Pressione qualquer tecla para continuar...]\n");
    getch();
    fclose(fp);
  }
}

CaoA *carrega(CaoA *caesM)
{
  CaoA *caoM;
  CaoB *caoP, *caesP;
  FILE *fp;
  int ver, farq, flin, npar;
  bool fpeof=false;
  if((fp=fopen("CAES.DAT","r"))==NULL)
  {
    printf("\n\tERRO: Nao e possivel abrir CAES.DAT!\n\t[Pressione qualquer tecla para continuar...]\n");
    getch();
    return caesM;
  }
  else
  {
    fscanf(fp, "%d", &ver);
    if (ver==0)
    {
      printf("\n\tERRO: CAES.DAT esta vazio.\n\t[Pressione qualquer tecla para continuar...]\n");
      getch();
      fclose(fp);
      return caesM;
    }
    else
    {
      while(fpeof==false)
      {
        fscanf(fp, "%d ", &farq);
        if (farq==0)
        {
//          caesM->ProxA=NULL;
          fpeof=true;
        }
        else
        {
          // Alocação do novo cão
          caoM=alocaCaoA();
          if (caoM==NULL)
          {
            printf("\n\tERRO: Nao houve memoria para o cao mestre.\n\t[Pressione qualquer tecla para continuar...]\n");
            getch();
            fclose(fp);
            return caesM;
          }

          // Inserindo na lista
          caoM->ProxA=caesM;
          caesM=caoM;

          caoM->Dados.Matricula=farq;
          fscanf(fp, "%s ", &caoM->Dados.Nome);
          fscanf(fp, "%s ", &caoM->Dados.Raca);
          fscanf(fp, "%d ", &caoM->Dados.AnoReg);
          fscanf(fp, "%d ", &caoM->DataNasc.Ano);
          fscanf(fp, "%d ", &caoM->DataNasc.Mes);
          fscanf(fp, "%d ", &caoM->DataNasc.Dia);
          fscanf(fp, "%d ", &flin);
          if (flin==0)
            caoM->ProxB=NULL;
          else
          {
            npar=0;
            while (flin!=0)
            {
              // Alocação do novo cão
              caoP=alocaCaoB();
              if (caoP==NULL)
              {
                printf("\n\tERRO: Nao houve memoria para o cao parente.\n\t[Pressione qualquer tecla para continuar...]\n");
                getch();
                fclose(fp);
                return caesM;
              }
              npar++;

              // Inserindo na lista
              if (npar==1)
              {
                caoP->ProxB=caoM->ProxB;
                caesP=caoP;
                caoM->ProxB=caesP;
              }
              else
              {
                caoP->ProxB=caesP->ProxB;
                caesP->ProxB=caoP;
              }

              caoP->Dados.Matricula=flin;
              fscanf(fp, "%s ", &caoP->Dados.Nome);
              fscanf(fp, "%s ", &caoP->Dados.Raca);
              fscanf(fp, "%d ", &caoP->Dados.AnoReg);
              fscanf(fp, "%d ", &caoP->DataNasc.Ano);
              fscanf(fp, "%d ", &caoP->DataNasc.Mes);
              fscanf(fp, "%d ", &caoP->DataNasc.Dia);
              fscanf(fp, "%d ", &flin);
              if (flin==0)
                caoP->ProxB=NULL;
            }
          }
        }
      }
      printf("\n\tDados carregados com sucesso.\n\t[Pressione qualquer tecla para continuar...]\n");
      getch();
      fclose(fp);
      return caesM;
    }
  }
}
