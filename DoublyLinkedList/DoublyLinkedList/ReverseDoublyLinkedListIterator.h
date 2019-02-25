//
// Created by mfbut on 2/13/2019.
//


#ifndef LINKEDLIST_GENERICREVERSEDOUBLYLINKEDLISTITERATOR_H
#define LINKEDLIST_GENERICREVERSEDOUBLYLINKEDLISTITERATOR_H
#include "DoublyLinkedList.h"
#include "DoubleLinkedNode.h"


template <typename T>
class DoublyLinkedList;

template<typename T>
class ReverseDoublyLinkedListIterator {
public:
    DoublyLinkedList<T>* nodelist;
    DoubleLinkedNode<T>* pos;
    //you must implement at least the methods below
    //you are free to add (and will likely need to add)
    //more members and methods


    //copy constructor
    ReverseDoublyLinkedListIterator(const ReverseDoublyLinkedListIterator& orig){
        this->nodelist = orig.nodelist;
        this->pos = orig.pos;
    }

    ReverseDoublyLinkedListIterator(DoubleLinkedNode<T> *pos, DoublyLinkedList<T> *list){
        this->nodelist = list;
        this->pos = pos;
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
    bool operator==(const ReverseDoublyLinkedListIterator<T>& rhs) const{
        if (this->nodelist!= rhs.nodelist){
            return false;
        }
        else if (this->pos==nullptr && rhs.pos==nullptr){
            return true;
        }
        else if (this->pos != rhs.pos){
            return false;
        }
        return true;}

    //are the two iterators different?
    bool operator!=(ReverseDoublyLinkedListIterator<T>& rhs) const{
        return(!(this==rhs));
    }

    //is the iterator safe to dereference?
    operator bool() const{
        if (this->nodelist->getHead()==nullptr){
            return false;
        }
        return true;
    }

    //go to the next element
    ReverseDoublyLinkedListIterator<T>& operator++(){
        pos=pos->prev;
        return *this;
    } //pre
    const ReverseDoublyLinkedListIterator<T> operator++(int){
        auto copy(*this);
        ++(*this);
        return copy;

    }//post
    ReverseDoublyLinkedListIterator<T>& operator+=(int rhs){
        for (int i = 0; i < rhs; ++i) {
            pos=pos->prev;
            return *this;
        }
    }

    ReverseDoublyLinkedListIterator<T>& operator-=(int rhs){
        for (int i = 0; i < rhs; ++i) {
            pos=pos->next;
            return *this;
        }
    }
    //go to the previous element
    ReverseDoublyLinkedListIterator<T>& operator--(){
        pos=pos->next;
        return *this;
    } //pre
    const ReverseDoublyLinkedListIterator<T> operator--(int){
        auto copy(*this);
        --(*this);
        return copy;
    }//post

    //get a const reference to the value
    const T& operator*() const{
        return this->pos->data;
    }

    //get a non-const reference to the value
    T& operator*(){
        return this->pos->data;
    }

};

#endif //LINKEDLIST_GENERICREVERSEDOUBLYLINKEDLISTITERATOR_H