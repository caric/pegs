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
  ~Board();

  void play();

 private:
  void operator=( const Board & ){}

  bool jump( Hole &, Hole *, Hole * );
  void unjump( Hole &, Hole *, Hole * );

  static const int numRows;

  Hole **holes_;

  friend ostream &operator << ( ostream &, const Board & );
  friend class Game;
};

ostream &operator << ( ostream &, const Board & );

#endif //  _BOARD_HPP_
