#ifndef _LIST_HPP_
#define _LIST_HPP_

#include "g.hpp"
#include "board.hpp"

class ListNode
{
 public:
  ListNode(): next_(this), prev_(this), data_(0) {}
  ListNode( Board&d ): next_(this), prev_(this), data_(&d) {}
  ~ListNode();
  
  Board *data_; 
  ListNode *next_;
  ListNode *prev_;
};

class List
{
 public:
  List();
  ~List();

  int empty(){return !len_; }
  int length() const { return len_; } 
  Board &front() const{ return *(head_.next_->data_); }
  Board &back() const{ return *(head_.prev_->data_); }
  void popFront();
  void popBack();
  void pushFront( Board& );
  void pushBack( Board& );
  const ListNode&getHead() const { return head_; }

 private:
  List ( const List & ){}
  void operator=( const List & ){}

  int len_;
  ListNode head_;
};

#endif // _LIST_HPP_
