#include "hole.hpp"

ostream &operator << ( ostream &os, const Hole &h )
{
  os << "  ";
  os << (char)h.contents_;
  os << " ";
  return os;
}

Hole::Hole(): contents_(Full), se_(NULL), e_(NULL), ne_(NULL), nw_(NULL), 
  w_(NULL), sw_(NULL)
{
}

Hole::Hole( contents c ): contents_(c), se_(NULL), e_(NULL), ne_(NULL), 
  nw_(NULL), w_(NULL), sw_(NULL)
{
}
