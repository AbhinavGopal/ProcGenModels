//
// Created by mfbut on 2/11/2019.
//
#include "DoublyLinkedList.h"
#include "DoubleLinkedNode.h"

#ifndef LINKEDLIST_GENERICDOUBLYLINKEDLISTITERATOR_H
#define LINKEDLIST_GENERICDOUBLYLINKEDLISTITERATOR_H

template <typename T>
class DoublyLinkedList;
template<typename T>
class DoublyLinkedListIterator {
  //you must implement at least the methods below
  //you are free to add (and will likely need to add)
  //more members and methods

 public:
    //Change to pointers if references fail
    DoublyLinkedList<T>* nodelist;
    DoubleLinkedNode<T>& pos;
  DoublyLinkedListIterator(const DoublyLinkedListIterator& orig){
      this->nodelist = orig->nodelist;
      this->pos = orig->pos;
  }

  int getSizeBefore() {
      int size = 0;
      auto tmp = this->pos->prev;
      while (tmp != nullptr) {
          size++;
          tmp = tmp -> prev;
      }
      return size;
  }

  int getSizeAfter() {
      int size = 0;
      auto tmp = this->pos->next;
      while (tmp != nullptr) {
          size++;
          tmp = tmp -> next;
      }
      return size;
  }

  //are the two iterators equal?
  //they are if they are over the same doubly linked list
  //and (they are referring to the same element in the list
  //or they are out of bounds)
  bool operator==(const DoublyLinkedListIterator<T>& rhs) const{
      if (!((getSizeBefore() == rhs.getSizeBefore()) && getSizeAfter() == rhs.getSizeAfter())) {
          return false;
      }
      if (*(this->pos->data) != *(rhs->pos->data)){
          return false;
      }
      auto tmp1 = this->getHead();
      auto tmp2 = rhs->getHead();
      while (tmp1 != nullptr) {
          if (*(tmp1->data) != *(tmp2->data)) {
              return false;
          }
          tmp1 = tmp1->next;
          tmp2 = tmp2->next;
      }
      return true;
  }

  //are the two iterators different?
  bool operator!=(const DoublyLinkedListIterator<T>& rhs) const{
      return(!(this==rhs));
  }

  //is the iterator safe to dereference?
  operator bool() const{
      if (this->nodelist->getHead()==nullptr){
          return false;
      }
      return true;
  } //check if not null

    DoublyLinkedListIterator<T>& operator++(){
        pos=pos->next;
        return *this;
    } //pre
    // pre
  //go to the next element
  const DoublyLinkedListIterator<T> operator++(int ){
      auto copy(*this);
      ++(*this);
      return copy;
  }


  //go to the previous element
  DoublyLinkedListIterator<T>& operator--(){
      pos=pos->prev;
      return *this;
  } //pre
  const DoublyLinkedListIterator<T> operator--(int) {
      auto copy(*this);
      --(*this);
      return copy;
  }    //post


  //get a const reference to the value
  const T& operator*() const{
      return this->pos->data;
  }

  //get a non const iterator
  T& operator*(){
      return this->pos->data;
  }

};

//check for null

#endif //LINKEDLIST_GENERICDOUBLYLINKEDLISTITERATOR_H
