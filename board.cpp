#include "board.hpp"

ostream &operator << ( ostream &os, const Board &b )
{
  const int width = 2;
  int i, j, k, m;

  for ( i = 0; i < b.numRows; i++ )
  {
    for ( k = b.numRows - i; k > 0; k-- )
    {
      for ( m = 0; m < width; m++ )
        os << ' ';
    }
    for ( j = 0; j < i+1; j++ )
      os << b.holes_[i][j];
    os << endl;
  }
  return os;
}

Board::Board()
{
  int i, j;

  ////////
  // allocate memory

  for ( i = 0; i < numRows; i++ )
  {
    holes_[i] = new Hole[ i+1 ];
    if ( holes_[i] == NULL )
    {
      cerr << "Error allocating memory for the holes.\n";
      exit( -1 );
    }
  }
  holes_[0][0].contents_ = Empty;
  //holes_[1][1].contents_ = Empty;
  //holes_[2][2].contents_ = Empty;

  setUpAdjacencies();
}

Board::Board( const Board &b )
{
  int i, j;
  #ifdef DEBUG2
    cout << "Entering board copy constructor" << endl;
  #endif


  for ( i = 0; i < numRows; i++ )
  {
    ////////
    // allocate memory
    holes_[i] = new Hole[ i+1 ];
    if ( holes_[i] == NULL )
    {
      cerr << "Error allocating memory for the holes.\n";
      exit( -1 );
    }
  }

  setUpAdjacencies();

  for ( i = 0; i < numRows; i++ )
  {
    for ( j = 0; j < i+1; j++ )
    {
      holes_[i][j] = b.holes_[i][j];
    }
  }
  #ifdef DEBUG2
    cout << "leaving board copy constructor" << endl;
  #endif
}

void Board::operator=( const Board &b )
{
  int i, j;

  for ( i = 0; i < numRows; i++ )
  {
    for ( j = 0; j < i+1; j++ )
    {
      holes_[i][j].contents_ = b.holes_[i][j].contents_;
    }
  }
}

Board::~Board()
{
  for ( int i = 0; i < numRows; i++ )
  {
    delete[] holes_[i];
  }
}

void Board::setUpAdjacencies()
{
  int i, j;

  for ( i = 0; i < numRows; i++ )
  {
    for ( j = 0; j < i+1; j++ )
    {
      // southeast
      if ( i < numRows-1 )
        holes_[i][j].adj_[Hole::se_] = &(holes_[i+1][j+1]);

      // east
      if ( j < i )
        holes_[i][j].adj_[Hole::e_] = &(holes_[i][j+1]);
  
      // northeast
      if ( j < i )
        holes_[i][j].adj_[Hole::ne_] = &(holes_[i-1][j]);
  
      // northwest
      if ( j > 0 )
        holes_[i][j].adj_[Hole::nw_] = &(holes_[i-1][j-1]);
  
      // west
      if ( j > 0 )
        holes_[i][j].adj_[Hole::w_] = &(holes_[i][j-1]);
  
      // southwest
      if ( i < numRows-1 )
        holes_[i][j].adj_[Hole::sw_] = &(holes_[i+1][j]);
    }
  }
}

bool Board::jump( Hole &src, Hole *route, Hole *dest )
{
  if ( src.contents_ == Empty )
  {
    return false;
  }
  if ( route->contents_ == Empty )
  {
    return false;
  }
  if ( dest->contents_ == Full )
  {
    return false;
  }
  
  src.contents_ = Empty;
  route->contents_ = Empty;
  dest->contents_ = Full;
  
  return true;
}

void Board::unjump( Hole &src, Hole *route, Hole *dest )
{
  src.contents_ = Full;
  route->contents_ = Full;
  dest->contents_ = Empty;
}
