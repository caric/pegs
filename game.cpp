#include "game.hpp"

ostream &operator << ( ostream &os, const Game &g )
{
  int i, n = g.theGame_.length();
  ListNode *p = g.theGame_.getHead().next_;

  #ifdef DEBUG
    cout << "trying to print a game." << endl;
  #endif

  cout << "Game Number: " << g.getNumWins() << endl;
  for ( i = 0; (i < n) && (p != &(g.theGame_.getHead())); i++, p = p->next_ )
  {
    os << *(p->data_);
  }
  return os;
}

Game::Game(): numMoves_(0), numGames_(0), numWins_(0), maxNumLeft_(0)
{
  theGame_.pushFront ( new Board );
}

Game::~Game()
{
}

void Game::play()
{
  int i, j;
  int numPegsLeft = 0;
  int numMoves = 0;
  Board *q, *p = theGame_.back();

#ifdef DEBUG
  cout << "in Game.play" << endl;
#endif

  if ( p == NULL )
  {
    cout << "No back!" << endl;
    exit(0);
  }

  for ( i = 0; i < p->numRows; i++ )
  {
    for ( j = 0; j < i+1; j++ )
    {
      if ( p->holes_[i][j].contents_ == Empty )
        continue;
      else if ( p->holes_[i][j].contents_ == Full )
        numPegsLeft++;
      else
        continue;

      #ifdef DEBUG
        cout << "checking SE. i:" << i << " j:" << j << endl;
      #endif

      // southeast
      if ( p->holes_[i][j].se_ != NULL ) 
      {
        if ( p->holes_[i][j].se_->se_ != NULL )
        {
          // make copy of the board
          q = new Board ( *p );
          if ( q == NULL ) { cout << "failed alloc of board\n"; exit(0); }
          // add it to the list
          theGame_.pushBack( q );
          if ( q->jump( q->holes_[i][j], q->holes_[i][j].se_, 
            q->holes_[i][j].se_->se_ ) )
          {
            play();
            numMoves_++;
            numMoves++;
          }
          // remove that last board position
          theGame_.popBack();
          delete q;
        }
      }

      #ifdef DEBUG
        cout << "checking E" << endl;
      #endif

      // east
      if ( p->holes_[i][j].e_ != NULL ) 
      {
        if ( p->holes_[i][j].e_->e_ != NULL )
        {
          // make copy of the board
          q = new Board ( *p );
          if ( q == NULL ) { cout << "failed alloc of board\n"; exit(0); }
          // add it to the list
          theGame_.pushBack( q );
          if ( q->jump( q->holes_[i][j], q->holes_[i][j].e_, 
            q->holes_[i][j].e_->e_ ) )
          {
            play();
            numMoves_++;
            numMoves++;
          }
          // remove that last board position
          theGame_.popBack();
          delete q;
        }
      }

      #ifdef DEBUG
        cout << "checking NE" << endl;
      #endif

      // northeast
      if ( p->holes_[i][j].ne_ != NULL ) 
      {
        if ( p->holes_[i][j].ne_->ne_ != NULL )
        {
          // make copy of the board
          q = new Board ( *p );
          if ( q == NULL ) { cout << "failed alloc of board\n"; exit(0); }
          // add it to the list
          theGame_.pushBack( q );
          if ( q->jump( q->holes_[i][j], q->holes_[i][j].ne_, 
            q->holes_[i][j].ne_->ne_ ) )
          {
            play();
            numMoves_++;
            numMoves++;
          }
          // remove that last board position
          theGame_.popBack();
          delete q;
        }
      }

      #ifdef DEBUG
        cout << "checking NW" << endl;
      #endif

      // northwest
      if ( p->holes_[i][j].nw_ != NULL ) 
      {
        if ( p->holes_[i][j].nw_->nw_ != NULL )
        {
          // make copy of the board
          q = new Board ( *p );
          if ( q == NULL ) { cout << "failed alloc of board\n"; exit(0); }
          // add it to the list
          theGame_.pushBack( q );
          if ( q->jump( q->holes_[i][j], q->holes_[i][j].nw_, 
            q->holes_[i][j].nw_->nw_ ) )
          {
            play();
            numMoves_++;
            numMoves++;
          }
          // remove that last board position
          theGame_.popBack();
          delete q;
        }
      }

      #ifdef DEBUG
        cout << "checking W" << endl;
      #endif

      // west
      if ( p->holes_[i][j].w_ != NULL ) 
      {
        if ( p->holes_[i][j].w_->w_ != NULL )
        {
          // make copy of the board
          q = new Board ( *p );
          if ( q == NULL ) { cout << "failed alloc of board\n"; exit(0); }
          // add it to the list
          theGame_.pushBack( q );
          if ( q->jump( q->holes_[i][j], q->holes_[i][j].w_, 
            q->holes_[i][j].w_->w_ ) )
          {
            play();
            numMoves_++;
            numMoves++;
          }
          // remove that last board position
          theGame_.popBack();
          delete q;
        }
      }

      #ifdef DEBUG
        cout << "checking SW" << endl;
      #endif

      // southwest
      if ( p->holes_[i][j].sw_ != NULL ) 
      {
        if ( p->holes_[i][j].sw_->sw_ != NULL )
        {
          // make copy of the board
          q = new Board ( *p );
          if ( q == NULL ) { cout << "failed alloc of board\n"; exit(0); }
          // add it to the list
          theGame_.pushBack( q );
          if ( q->jump( q->holes_[i][j], q->holes_[i][j].sw_, 
            q->holes_[i][j].sw_->sw_ ) )
          {
            play();
            numMoves_++;
            numMoves++;
          }
          // remove that last board position
          theGame_.popBack();
          delete q;
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
    if ( numPegsLeft > maxNumLeft_ )
      maxNumLeft_ = numPegsLeft;
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
