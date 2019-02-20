//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_DOUBLYLINKEDLIST_H
#define LINKEDLIST_DOUBLYLINKEDLIST_H

#include <vector>
#include <memory>
#include "DoubleLinkedNode.h"
#include "DoublyLinkedListIterator.h"
#include "ReverseDoublyLinkedListIterator.h"
#include "ConstDoublyLinkedListIterator.h"
#include "ConstReverseDoublyLinkedListIterator.h"

template<typename T>
class DoublyLinkedList {
 public:
  using Node_Ptr = DoubleLinkedNode<T>*;

  using iterator =  DoublyLinkedListIterator<T>*;
  using const_iterator =  ConstDoublyLinkedListIterator<T>*;
  using reverse_iterator = ReverseDoublyLinkedListIterator<T>*;
  using const_reverse_iterator = ConstReverseDoublyLinkedListIterator<T>*;

  //create a Doubly Linked List that has the same values
  //as in the vector and in the same order
  explicit DoublyLinkedList(const std::vector<T>& values){
      int i=0;
      Node_Ptr temp= nullptr;
      while (i<values.length()){
          if (i==0){
              auto head=Node_Ptr(values[i]);
              temp= head;
              temp->prev=nullptr;
          }
          if (i==values.length()-1){
              auto tail=Node_Ptr(values[i]);
              temp->next=tail;
              temp=temp->next;
          }
          else{
              temp->next=Node_Ptr(values[i]);
              temp->next->prev=temp;
              temp=temp->next;
          }
          i++;
      }
      len=i;
  }

  //create an empty DoublyLinkedList
  DoublyLinkedList(){
      Node_Ptr temp=nullptr;
      head=temp;
      tail=temp;
      len=0;
  }

    DoublyLinkedList(const DoubleLinkedNode<T> *head);


    virtual ~DoublyLinkedList();

  //remove all of the elements from your list
  void clear(){
  }

  //get a reference to the front element in the list
  const T& front() const{
      return head->data;
  }
  T& front();

  //get a reference to the last element in the list
  const T& back() const{
      return tail->data;
  }
  T& back();

  //add a value to the front of the list
  void push_front(const T& value){
      this->head->prev=DoubleLinkedNode<T>(*value);
      this->head->prev->next=this->head;
      this->head=this->head->prev;
  }

  //add a value to the back of the list
  void push_back(const T& value){
      this->tail->next=DoubleLinkedNode<T>(*value);
      this->tail->next->prev=this->tail;
      this->tail=this->tail->next;
  }

  //is the list empty?
  bool empty() const{
      return (this->head==nullptr);
  }

  //return the number of elements in the list
  int size() const{
      int i=0;
      auto temp=this->head;
      while (temp!=nullptr){
          i++;
          temp=temp->next;
      }
      return i;
  }

  //return a constant bidirectional iterator to the front of the list
  const_iterator begin() const;
  const_iterator end() const;

  //return a nonconstant bidirectional iterator to the front of the list
  iterator begin();
  iterator end();

  const_reverse_iterator crbegin() const;
  const_reverse_iterator crend() const;

  reverse_iterator rbegin();
  reverse_iterator rend();

  //insert the value at the position in the list
  //I promise not to use the iterator again after the insertion is done
  //An example if we had the list 1 <-> 9 <-> 17
  //And the iterator was pointing to the 9 and we wanted to
  //insert -22 the result would be
  //1 <-> 22 <-> 9 <-> 17
  void insert(iterator& position, const T& value);

  //remove the element at the position pointed to
  //by the iterator.
  //I promise not to use the iterator again after the erase is done
  //An example if we had the list 1 <-> 9 <-> 17
  //And when the wanted to erase the iterator was at the 9
  //1 <-> 17
  void erase(iterator& position);

 private:
  Node_Ptr head;
  Node_Ptr tail;
  int len;
};

//write to the stream each element in the list in order
//with a space in between them
template<typename T>
std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& doublyLinkedList);

//read elements from the stream as long as it is good
// or until a newline (\n) is encountered
//if a newline is encontered it should be consumed
template<typename T>
std::istream& operator>>(std::istream& in, DoublyLinkedList<T>& doublyLinkedList);


#endif //LINKEDLIST_DOUBLYLINKEDLIST_H
