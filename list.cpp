#include "list.hpp"

// class list node
ListNode::~ListNode()
{
}

// class list

List::List(): len_(0)
{
}

List::~List()
{
}

void List::pushFront ( Board *d )
{
  ListNode *p = new ListNode( d );
  if ( p == NULL )
  {
    cerr << "Error allocating memory for a list node." << endl;
    exit(0);
  }

  p->next_ = head_.next_;
  head_.next_ = p;
  p->prev_ = &head_;
  p->next_->prev_ = p;
  len_++;
}

void List::pushBack ( Board *d )
{
  ListNode *p = new ListNode( d );

  #ifdef DEBUG2
    cout << "in list::pushBack" << endl;
  #endif

  if ( p == NULL )
  {
    cerr << "Error allocating memory for a list node." << endl;
    exit(0);
  }

  p->prev_ = head_.prev_;
  head_.prev_ = p;
  p->next_ = &head_;
  p->prev_->next_ = p;
  len_++;

  #ifdef DEBUG2
    cout << "leaving list::pushBack" << endl;
  #endif

}

void List::popBack ( )
{
  ListNode *p = head_.prev_;

  #ifdef DEBUG2
    cout << "entering list::popBack" << endl;
  #endif

  if ( head_.prev_ == &head_ )
    return;

  head_.prev_ = p->prev_;
  head_.prev_->next_ = &head_;
  delete p;
  len_--;

  #ifdef DEBUG2
    cout << "leaving list::popBack" << endl;
  #endif
}

void List::popFront ( )
{
  ListNode *p = head_.next_;

  if ( head_.next_ == &head_ )
    return;

  head_.next_ = p->next_;
  head_.next_->prev_ = &head_;
  delete p;
  len_--;
}
