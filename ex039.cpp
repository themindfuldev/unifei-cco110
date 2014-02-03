#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int pilha[50];    // uma pilha formada por 50 numero inteiros
int *p1, *tam;    // tam marca o inicio da pilha e evita underflow

void empilha(int i);
int desempilha();

void main()
{
  int valor;
  p1 = pilha;    // p1 recebe o endereço inicial do valor pilha
  tam = p1;      // tam tambem
  do {
    printf("\tDigite um numero ou zero para terminar: ");
    scanf("%d", &valor);
    if (valor!=0)
      empilha(valor);   // um numero diferente de zero é empilhado
    else {
      printf("\tDesempilhei: %d\n", desempilha());
      getch();
    }
  }
  while (valor!=0);
}

void empilha(int i)
{
  p1++;   // incrementa a posição de memória para empilhar
  if (p1==(tam+50)) {
    printf("Overflow da pilha!\n");                                                   
    getch();
    exit(1);
  }
  else
    *p1=i;    // p1 recebe o valor a ser empilhado
}

int desempilha()
{
  if((p1)==tam) {
    printf("Underflow da pilha\n");      // a pilha está vazia
    getch();
    exit(1);
  }
  else
    p1--;           // decrementa uma posição da pilha
  return *(p1+1);   // retorna a posição decrementada
}
