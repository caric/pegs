#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <stdio.h>
#include <fstream.h>

#include "g.hpp"
#include "list.hpp"
#include "board.hpp"

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
  int getMaxNumLeft() const { return maxNumLeft_; }

 private:
  // no copies
  Game( const Board & ){}
  void operator=( const Game & ){}

  List theGame_;

  int numMoves_;
  int numGames_;
  int numWins_;
  int maxNumLeft_;
  int numTopWins_;
  
  friend ostream & operator << ( ostream &, const Game & );
};

ostream & operator << ( ostream &, const Game & );

#endif //  _GAME_HPP_
