#include "game.hpp"

ostream &operator << ( ostream &os, const Game &g )
{
  int i, n = g.theGame_.size();
  list<Board>::const_iterator p = g.theGame_.begin();

  #ifdef DEBUG
    cout << "trying to print a game." << endl;
  #endif

  cout << "=====================================Game Number: " << g.getNumWins() << endl;
  for ( i = 0; (i < n) && (p != g.theGame_.end()); i++, ++p )
  {
    os << *p;
  }
  return os;
}

Game::Game(): numMoves_(0), numGames_(0), numWins_(0)
{
  int i;
  for ( i = 0; i < numHoles(); i++ )
    stats[i] = 0;
  theGame_.push_back ( Board() );
}

Game::~Game()
{
}

void Game::play()
{
  int i, j, k;
  int numPegsLeft = 0;
  int numMoves = 0;
  Board q, p;

#ifdef DEBUG
  cout << "in Game.play" << endl;
#endif

  if ( theGame_.size() == 0 )
  {
    cout << "No back!" << endl;
    exit(0);
  }

  p = theGame_.back();

  for ( i = 0; i < Board::numRows; i++ )
  {
    for ( j = 0; j < i+1; j++ )
    {
      if ( p.holes_[i][j].contents_ == Empty )
        continue;
      else if ( p.holes_[i][j].contents_ == Full )
        numPegsLeft++;
      else
        continue;
      
      for ( k = 0; k < Hole::numDirs; k++ )
      {
        #ifdef DEBUG
          cout << "checking " << k << ". i:" << i << " j:" << j << endl;
        #endif

        if ( p.holes_[i][j].adj_[k] != NULL ) 
        {
          if ( p.holes_[i][j].adj_[k]->adj_[k] != NULL )
          {
            // make copy of the board
            q = p;
  
            if ( q.jump( q.holes_[i][j], q.holes_[i][j].adj_[k], 
              q.holes_[i][j].adj_[k]->adj_[k] ) )
            {
              // add it to the list
              theGame_.push_back( q );
              play();
              numMoves_++;
              numMoves++;
              // remove that last board position
              theGame_.pop_back();
            }
          }
        }
      }
    }
  }
  #ifdef DEBUG
    cout << "finished all directions" << endl;
  #endif

  if ( numMoves == 0 ) // end of game
  {
    numGames_++;
    stats[ numPegsLeft ]++;
    //if ( numPegsLeft > maxNumLeft_ )
      //maxNumLeft_ = numPegsLeft;
  }
  if ( numPegsLeft == 1 ) // we win!
  {
    numWins_++;
    cout << *this;
  }

  #ifdef DEBUG
    cout << "Exiting Game.play" << endl;
  #endif
}
