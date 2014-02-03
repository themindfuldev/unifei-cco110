#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct registro
 {
   int Matr;
   char Nome[30];
   registro *ante;       // guarda o endereco do anterior na lista
 };
 registro *reg, *ret, *lista, *lis;   // reg guarda um registro e lista guarda a lista toda
 int i=1, N, Mat;

 void insere ()
 {
   printf ("Digite o numero de elementos a inserir:\n");
   scanf ("%d",&N);
   // Insere sempre no fim da lista
   while (i<=N) // Carregamos os dados
   {
     // reserva uma posicao na memoria para o registro
     reg = (registro *) malloc (sizeof (registro));
     reg->ante = lista;  //
     lista = reg;   // todo o registro e inserido na lista (ainda com dados em branco)
     printf("%da. Matricula: ",i);// os campos de dados sao preenchidos
     scanf("%d",&lista->Matr);
     printf("%do. Nome     : ",i);
     scanf("%s",lista->Nome);
     i++;
   }
 }

 void exclui()
 {
   int Mat;
   reg = lista;        // o ponteiro reg recebe o ultimo elemento da lista
   lis = lista;
   printf ("Digite a matricula a excluir: ");
   scanf ("%d", &Mat);
   printf ("Exclui da lista: Matricula    Nome\n");
   while(lis->ante != NULL)
    {
      if (lis->Matr == Mat)
      {
       lis = lis->ante;  // elimina da lista o ultimo registro
       printf("\t\t     %d\t       %s\n ",reg->Matr,reg->Nome); // mostra o conteudo da memoria liberada
       reg->ante = NULL;
       free(reg);          // libera a memoria
      }
    }
 }

 void main()
 {
   clrscr();
   //Inicializando a lista
   reg = (registro *) malloc (sizeof (registro));
   lista = reg;        // todo o registro e inserido na lista (ainda com dados em branco)
   // Na primeira vez o endereco do ponteiro e nulo
   reg->ante = NULL;
   // No primeiro registro nao colocamos nada
   reg->Matr = 0;

   insere();
   exclui();
   getch();
 }


