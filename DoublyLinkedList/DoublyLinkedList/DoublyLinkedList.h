//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_DOUBLYLINKEDLIST_H
#define LINKEDLIST_DOUBLYLINKEDLIST_H

#include <cstdlib>
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
      while (i<values.size()){
          if (i==0){
              Node_Ptr head=Node_Ptr(values[i]);
              temp= head;
              temp->prev=nullptr;
          }
          if (i==values.size()-1){
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

    const DoubleLinkedNode<T> *getHead() const {
        return head;
    }

    const DoubleLinkedNode<T> *getTail() const {
        return tail;
    }

    int getLen() const {
        return len;
    }


    virtual ~DoublyLinkedList(){
        auto temp=this->getTail();
        while (temp!=nullptr){
            temp=temp->prev;
            free(temp->next);
        }
        free(this->getHead());
    }

  //remove all of the elements from your list
  void clear(){
      auto tmp = this->getTail();
      while (tmp->prev!=nullptr){
          tmp=tmp->prev;
          free(tmp->next);
      }
          free(tmp);
  }

  //get a reference to the front element in the list
  const T& front() const{
      return &(this->getHead()->data);
  }
  T& front(){
      return &(this->getHead()->data);
  }

  //get a reference to the last element in the list
  const T& back() const{
      return &(this->getTail()->data);
  }
  T& back(){
      return &(this->getTail()->data);
  }

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
  const_iterator begin() const{
      return const_iterator(this->getHead());
  }
  const_iterator end() const{
      return const_iterator(this->getTail());
  }

  //return a nonconstant bidirectional iterator to the front of the list
  iterator begin(){
      return iterator(this->getHead());
  }
  iterator end(){
      return iterator(this->getTail());
  }

  const_reverse_iterator crbegin() const{
      return const_reverse_iterator(this->getTail());
  }
  const_reverse_iterator crend() const{
      return const_reverse_iterator(this->getHead());
  }

  reverse_iterator rbegin(){
      return reverse_iterator(this->getHead());
  }
  reverse_iterator rend(){
      return reverse_iterator(this->getTail());
  }

  //insert the value at the position in the list
  //I promise not to use the iterator again after the insertion is done
  //An example if we had the list 1 <-> 9 <-> 17
  //And the iterator was pointing to the 9 and we wanted to
  //insert -22 the result would be
  //1 <-> 22 <-> 9 <-> 17
  void insert(iterator& position, const T& value){
      auto toadd=DoubleLinkedNode<T>(*value);
      auto tmp=position->pos;
      tmp->next->prev=toadd;
      tmp->next->prev->next=tmp->next;
      tmp->next=toadd;
      tmp->next->prev=tmp;
  }

  //remove the element at the position pointed to
  //by the iterator.
  //I promise not to use the iterator again after the erase is done
  //An example if we had the list 1 <-> 9 <-> 17
  //And when the wanted to erase the iterator was at the 9
  //1 <-> 17
  void erase(iterator& position){
      int index=position->getSizeBefore();
      auto tmp=this->getHead();
      for (int i=0;i<index;i++){
          tmp=tmp->next;
      }
      tmp->prev->next=tmp->next;
      tmp->next->prev=tmp->prev;
      free(tmp);
  }

 private:
  Node_Ptr head;
  Node_Ptr tail;
  int len;
};

//write to the stream each element in the list in order
//with a space in between them
template<typename T>
std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& doublyLinkedList){
    for(DoublyLinkedListIterator<T>* itr = doublyLinkedList->cbegin(); itr !=itr->cend(); ++itr){
        std::cout << itr->pos->data <<" ";
    }


}

//read elements from the stream as long as it is good
// or until a newline (\n) is encountered
//if a newline is encontered it should be consumed
template<typename T>
std::istream& operator>>(std::istream& in, DoublyLinkedList<T>& doublyLinkedList);


#endif //LINKEDLIST_DOUBLYLINKEDLIST_H
