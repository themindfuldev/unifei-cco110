// Craps
#include <iostream.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int rollDice (void); // Protótipo da função

int main()
{
  enum Status {CONTINUE, WON, LOST};
  int sum, myPoint;
  Status gameStatus;

  srand(time(0));
  sum = rollDice();            // primeira jogada dos dados

  switch (sum) {
    case 7:
    case 11:                   // vence na primeira jogada
      gameStatus = WON;
      break;

    case 2:
    case 3:
    case 12:
      gameStatus = LOST;       // perde na primeira jogada
      break;

    default:
      gameStatus = CONTINUE;
      myPoint = sum;
      cout << "Pontos: " << myPoint << "\n";
    break;
  }

  while (gameStatus==CONTINUE) { // continua jogando
    sum = rollDice();

    if (sum==myPoint)
      gameStatus = WON;        // vence fazendo o ponto
    else
      if (sum==7)
        gameStatus = LOST;     // perde obtendo o valor 7
  }

  if (gameStatus==WON)
    cout << "Jogador ganha\n";
  else
    cout << "Jogador perde\n";

  getch();
  return 0;
}

int rollDice (void)
{
  int die1, die2, workSum;

  die1 = 1+rand()%6;
  die2 = 2+rand()%6;
  workSum = die1+die2;
  cout << "Jogador fez " << die1 << " + " << die2 << " = " << workSum << "\n";

  return workSum;
}