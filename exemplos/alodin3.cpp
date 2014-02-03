#include <stdio.h>
#include <string.h>
#include <alloc.h>

int main(void)
{
   char *str = NULL;

   /* allocate memory for string */
   str = (char *) calloc(10, sizeof(char));

   /* copy "Hello" into string */
   strcpy(str, "Hello");

   /* display string */
   printf("String is %s\n", str);

   /* free memory */
   free(str);

   return 0;
}
