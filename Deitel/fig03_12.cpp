// Um exemplo de escopos
#include <iostream.h>
#include <conio.h>

void a(void);  // prot�tipo de fun��o
void b(void);
void c(void);

int x = 1;     // vari�vel global

int main()
{
  int x = 5;  // vari�vel local para main

  cout << "x local no escopo externo de main e: " << x << "\n";

  {           // inicia novo escopo
    int x=7;

    cout << "x local no escopo interno de main e: " << x << "\n";
  }           // encerra novo esopo

  cout << "x local no escopo externo de main e: " << x << "\n";

  a();       // a tem x local automatico
  b();       // b tem x local est�tico
  c();       // c usa x global
  a();       // a reinicializa x local autom�tico
  b();       // x local est�tico conserva seu valor anterior
  c();       // x global tamb�m conserva seu valor

  cout << "x local em main e: " << x << "\n";

  getch();
  return 0;
}

void a(void)
{
  int x = 25;  // inicializa sempre que a � chamada

  cout << "\nx local em a e " << x << " depois de entrar em a\n";
  ++x;
  cout << "x local em a e " << x << " antes de sair de a\n";
}

void b(void)
{
  static int x = 50;  //somente inicializa��o est�tica
                      // na primeira vez que b � chamada

  cout << "\nx local estatico e " << x << " ao entrar em b\n";
  ++x;
  cout << "x local estatico e " << x << " ao sair em b\n";
}

void c(void)
{
  cout << "\nx global e " << x << " ao entrar em c\n";
  x *= 10;
  cout << "x global e " << x << " ao sair em c\n";
}
