#ifndef _BOARD_HPP_
#define _BOARD_HPP_

#include <stdio.h>
#include <stdlib.h>
#include <fstream.h>

#include "g.hpp"
#include "hole.hpp"

class Game;

class Board
{
 public:
  // constructors
  Board();
  Board( const Board & );
  void operator=( const Board & );
  ~Board();

  void play();

 private:

  bool jump( Hole &, Hole *, Hole * );
  void unjump( Hole &, Hole *, Hole * );

  void setUpAdjacencies();

  static const int numRows = 5;
  static const int numHoles = 15;

  Hole *holes_[numRows];

  friend ostream &operator << ( ostream &, const Board & );
  friend class Game;
};

ostream &operator << ( ostream &, const Board & );

#endif //  _BOARD_HPP_
