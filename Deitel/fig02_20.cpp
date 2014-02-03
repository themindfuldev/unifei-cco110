// Somatório com for
#include <iostream.h>
#include <conio.h>

int main()
{
  int sum = 0;

  for (int number=2; number<=100; number+=2)
    sum += number;

  cout << "A soma e: " << sum << "\n";

  getch();
  return 0;
}

