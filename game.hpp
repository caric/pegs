#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <stdio.h>
#include <iostream>
using namespace std;

#include <list>

#include "g.hpp"
#include "board.hpp"

class Game;
ostream & operator << ( ostream &, const Game & );
class Game
{
 public:
  // constructors
  Game();
  ~Game();
  
  void play();

  int getNumMoves() const { return numMoves_; }
  int getNumGames() const { return numGames_; }
  int getNumWins() const { return numWins_; }
  //int getMaxNumLeft() const { return maxNumLeft_; }
  int numHoles() const { return Board::numHoles; }

  int stats[Board::numHoles];

 private:
  // no copies
  Game( const Board & ){}
  void operator=( const Game & ){}

  list<Board> theGame_;

  int numMoves_;
  int numGames_;
  int numWins_;
  int numTopWins_;
  
  friend ostream & operator << ( ostream &, const Game & );
};

#endif //  _GAME_HPP_
