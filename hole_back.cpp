#include "hole.hpp"

ostream &operator << ( ostream &os, const Hole &h )
{
  os << "  ";
  os << (char)h.contents_;
  os << " ";
  return os;
}

Hole::Hole(): contents_(Empty), se_(0), e_(0), ne_(0), nw_(0), w_(0), sw_(0)
{
}

Hole::Hole( contents c ): contents_(c), se_(0), e_(0), ne_(0), nw_(0), 
  w_(0), sw_(0)
{
}
