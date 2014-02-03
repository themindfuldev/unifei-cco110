#include <stdio.h>
#include <conio.h>

void main()
{
  char str[30], *p;

  printf("\n\tDigite seu nome: ");
  gets(str);
  printf("\n\n\tBom dia, ");
  p = str;
  while (*p)
    printf("%c", *p++);
  printf("!\n");
  getch();
}
