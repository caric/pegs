#include "hole.hpp"

ostream &operator << ( ostream &os, const Hole &h )
{
  os << "  ";
  os << (char)h.contents_;
  os << " ";
  return os;
}

const int Hole::se_ = 0;
const int Hole::e_ = 1;
const int Hole::ne_ = 2;
const int Hole::nw_ = 3;
const int Hole::w_ = 4;
const int Hole::sw_ = 5;

Hole::Hole(): contents_(Full)
{
  for ( int i = 0; i < numDirs; i++ )
  {
    adj_[i] = NULL;
  }
}

Hole::Hole( contents c ): contents_(c)
{
  for ( int i = 0; i < numDirs; i++ )
  {
    adj_[i] = NULL;
  }
}

Hole::Hole( const Hole &h ): contents_( h.contents_ )
{
  for ( int i = 0; i < numDirs; i++ )
  {
    adj_[i] = NULL;
  }
}

void Hole::operator=( const Hole &h )
{
  contents_ = h.contents_;
}

Hole::~Hole()
{
}
