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
  Hole( const Hole & );
  void operator=( const Hole & );
  ~Hole();

 private:
  contents contents_;
  static const int numDirs = 6;
  Hole *adj_[numDirs];
  static const int se_;
  static const int e_;
  static const int ne_;
  static const int nw_;
  static const int w_;
  static const int sw_;

  friend ostream &operator << ( ostream &, const Hole & );
  friend class Board;
  friend class Game;
};

ostream& operator << ( ostream &, const Hole & );

#endif _HOLE_HPP_
