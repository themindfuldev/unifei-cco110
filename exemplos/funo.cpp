#include<stdio.h>
main (argc,argv)
int argc;
char *argv[];
{
  if (argc!=2)
  {
    printf("Voce esqueceu de digitar seu nome!\n");
    return 0;
  }
  printf("Oi %s", argv[1]);
}
