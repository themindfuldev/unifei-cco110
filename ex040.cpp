#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int pilha[50];    // uma pilha formada por 50 numero inteiros
int *p1, *tam;    // tam marca o inicio da pilha e evita underflow

void op1();
void op2();
void op3();
void empilha(int i);
int desempilha();

void main()
{
  int op;
  p1 = pilha;    // p1 recebe o endereço inicial do valor pilha
  tam = p1;      // tam tambem
  do
  {
    do
    {
      clrscr();
      printf("\n\t\tPilha de 50 numeros");
      printf("\n\n\t\t1. Empilhar\n\t\t2. Desempilhar\n\t\t3. Desempilhar tudo\n\t\t4. Sair");
      printf("\n\n\tEscolha a sua opcao: ");
      scanf("%d", &op);
      if ((op<1)||(op>4)) {
        printf("\n\n\tDigite um valor entre 1 e 4!\n\t[Pressione qualquer tecla para continuar...]\n");
        getch();
      }
    }
    while ((op<1)||(op>4));
    switch(op)
    {
      case 1: op1();
              break;

      case 2: op2();
              break;

      case 3: op3();
              break;

      case 4: break;

      default: printf("Opcao invalida!");
               getch();
               break;
    }
  }
  while (op!=4);
}

void op1()
{
  int valor;
  printf("\n");
  do
  {
    printf("\tDigite um numero ou zero para terminar: ");
    scanf("%d", &valor);
    if (valor!=0)
      empilha(valor);   // um numero diferente de zero é empilhado
  }
  while (valor!=0);
}

void op2()
{
  printf("\tDesempilhei: %d\n", desempilha());
  getch();
}

void op3()
{
  do
  {
    printf("\tDesempilhei: %d\n", desempilha());
    getch();
  }
  while ((p1)>=tam);
}

void empilha(int i)
{
  p1++;   // incrementa a posição de memória para empilhar
  if (p1==(tam+50)) {
    printf("\n\tOverflow da pilha!\n");
    getch();
    exit(1);
  }
  else
    *p1=i;    // p1 recebe o valor a ser empilhado
}

int desempilha()
{
  if((p1)==tam) {
    printf("\n\tUnderflow da pilha\n");      // a pilha está vazia
    getch();
    exit(1);
  }
  else
    p1--;           // decrementa uma posição da pilha
  return *(p1+1);   // retorna a posição decrementada
}
