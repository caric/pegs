#ifndef _HOLE_HPP_
#define _HOLE_HPP_

#include <fstream.h>

#include "g.hpp"

class Board;
class Game;

typedef enum
{
  Empty = '_', Full = 'O', Invalid = 'X' 
} contents;

class Hole
{
 public:
  Hole();
  Hole( contents );

 private:
  contents contents_;
  Hole *se_;
  Hole *e_;
  Hole *ne_;
  Hole *nw_;
  Hole *w_;
  Hole *sw_;

  friend ostream &operator << ( ostream &, const Hole & );
  friend class Board;
  friend class Game;
};

ostream& operator << ( ostream &, const Hole & );

#endif _HOLE_HPP_
