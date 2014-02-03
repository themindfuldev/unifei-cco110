#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct registro
 {
   int Matr;
   char Nome[30];
   registro *ante;       // guarda o endereco do anterior na pilha
 };
 registro *reg,*pilha;   // reg guarda um registro e pilha guarda a pilha toda
 int i,n;

 void empilha ()
 {
   reg->ante = NULL;  // No inicio tanto o registro quanto a pilha estao vazios
   pilha = NULL;
   printf ("Empilhando tres nomes e matriculas:\n");
   for (i=0;i<3;i++)
   {                 // reserva uma posicao na memoria para o registro
     reg = (registro *) malloc (sizeof (registro));
     reg->ante = pilha;   // o campo ante aponta para o anterior da pilha
     pilha = reg;        // todo o registro e inserido na pilha (ainda com dados em branco)
     printf("%da. Matricula: ",i+1);// os campos de dados sao preenchidos
     scanf("%d",&reg->Matr);
     printf("%do. Nome     : ",i+1);
     scanf("%s",&reg->Nome);
   }
 }
 void desempilha()
 {
   printf ("Desempilhando os tres nomes e matriculas:\n");
   for (i=0;i<3;i++)
    {
      reg = pilha;        // o ponteiro reg recebe o ultimo elemento da pilha
      pilha = reg->ante;  // elimina da pilha o ultimo registro
      free(reg);          // libera a memoria para o SO
      printf("\t%d\t%s\n ",reg->Matr,reg->Nome); // mostra o conteudo da memoria liberada
    }
 }
 void main()
 {
   clrscr();
   empilha();
   desempilha();
   getch();
 }