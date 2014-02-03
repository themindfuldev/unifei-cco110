#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int *p;
void main()
{
  p = malloc (10);
  &p = 1234;
  printf(" %s \n",p);
  free(p);
}
