#include <fstream.h>

#include "g.hpp"
#include "game.hpp"

void main()
{
  Game pegs;

  pegs.play();
 
  cout << "number of moves examined: " << pegs.getNumMoves() << endl;
  cout << "number of games played: " << pegs.getNumGames() << endl;
  cout << "worst score: " << pegs.getMaxNumLeft() << endl;
  cout << "number of wins: " << pegs.getNumWins() << endl;
  cout << "percentage: " << (double)(pegs.getNumWins()) / 
    (double)(pegs.getNumGames()) << endl;
}
