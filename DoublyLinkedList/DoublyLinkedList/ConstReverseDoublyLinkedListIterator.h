//
// Created by mfbut on 2/16/2019.
//
#include "DoublyLinkedList.h"
#include "DoubleLinkedNode.h"
#ifndef TESTDOUBLELINKEDLIST_CONSTREVERSEDOUBLYLINKEDLISTITERATOR_H
#define TESTDOUBLELINKEDLIST_CONSTREVERSEDOUBLYLINKEDLISTITERATOR_H



template<typename T>
class ConstReverseDoublyLinkedListIterator {
//you must implement at least the methods below
  //you are free to add (and will likely need to add)
  //more members and methods
public:
    DoubleLinkedNode<T>* nodelist;
    DoubleLinkedNode<T>& pos;
  //copy constructor
  ConstReverseDoublyLinkedListIterator(const ConstReverseDoublyLinkedListIterator& orig) {
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
  bool operator==(const ConstReverseDoublyLinkedListIterator<T>& rhs) const {
      if (!((getSizeBefore() == rhs.getSizeBefore()) && getSizeAfter() == rhs.getSizeAfter())) {
          return false;
      }
      if (this->pos->data != rhs->pos->data){
          return false;
      }
      auto tmp1 = this->head;
      auto tmp2 = rhs->head;
      while (tmp1 != nullptr) {
          if (tmp1->data != tmp2->data) {
              return false;
          }
          tmp1 = tmp1->next;
          tmp2 = tmp2->next;
      }
      return true;
  }

  //are the two iterators different?
  bool operator!=(ConstReverseDoublyLinkedListIterator<T>& rhs) const {
      return(!(this==rhs));
  }

  //is the iterator safe to dereference?
  operator bool() const {
      if (this->nodelist->head->data==nullptr){
          return false;
      }
      return true;
  }

  //go to the next element
  ConstReverseDoublyLinkedListIterator<T>& operator++() {
      pos=pos->prev;
  } //pre
  const ConstReverseDoublyLinkedListIterator<T> operator++(int a) {
      auto temp = this;
      for (int i = 0; i < a; i++) {
          this++;
      }
      return temp;
  }//post

  //go to the previous element
  ConstReverseDoublyLinkedListIterator<T>& operator--() {
      pos=pos->next;
  } //pre
  const ConstReverseDoublyLinkedListIterator<T> operator--(int a){
      auto temp = this;
      for (int i = 0; i < a; i++) {
          this++;
      }
      return temp;
  }//post

  //get a const reference to the value
  const T& operator*() const{
      return &(this->pos->data);
  }

};

#endif //TESTDOUBLELINKEDLIST_CONSTREVERSEDOUBLYLINKEDLISTITERATOR_H
