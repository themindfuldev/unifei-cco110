// Usando a estrutura de repeti��o do/while
#include <iostream.h>
#include <conio.h>

int main()
{
  int counter = 1;

  do {
    cout << counter << " ";
  } while (++counter<=10);

  cout << "\n";
  
  getch();
  return 0;
}

