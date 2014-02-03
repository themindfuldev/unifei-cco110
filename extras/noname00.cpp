#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void main()
{
  char *Vetc, *Pc;
  Vetc = (char *) malloc (100*sizeof(char));
  if (Vetc == NULL) {
    printf("\n\tErro de alocacao de memoria!\n");
    getch();
  }
  else {
    Pc = Vetc;
    printf("\n\tDigite um caracter (para finalizar, digite ?): ");
    scanf("%s", Pc);
    while (*Pc!='?') {
      Pc++;
      printf("\tDigite o proximo caracter (para finalizar, digite ?): ");
      scanf("%s", Pc);
    }
  }
  Pc = Vetc;
  printf("\n\tCaracteres lidos: ");
  while (*Pc!='?') {
    printf("%c", *Pc);
    Pc++;
  }
  printf("\n");
  getch();
  free(Vetc);
}