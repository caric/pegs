#include <fstream.h>

#include "g.hpp"
#include "game.hpp"

int main()
{
  int i;
  Game pegs;

  pegs.play();
 
  cout << "number of moves examined: " << pegs.getNumMoves() << endl;
  cout << "number of games played: " << pegs.getNumGames() << endl;
  //cout << "worst score: " << pegs.getMaxNumLeft() << endl;
  cout << "number of wins: " << pegs.getNumWins() << endl;
  cout << "percentage: " << (double)(pegs.getNumWins()) / 
    (double)(pegs.getNumGames()) << endl;

  for ( i = 0; i < pegs.numHoles(); i++ )
  {
    printf( "Number of Pegs left: %2d; Frequency of occurence: %6d\n", 
      i, pegs.stats[i] );
  }
  return 0;
}
