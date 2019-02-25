//
// Created by mfbut on 2/16/2019.
//
#include "DoublyLinkedList.h"
#include "DoubleLinkedNode.h"

#ifndef TESTDOUBLELINKEDLIST_CONSTDOUBLYLINKEDLISTITERATOR_H
#define TESTDOUBLELINKEDLIST_CONSTDOUBLYLINKEDLISTITERATOR_H

template<typename T>
class ConstDoublyLinkedListIterator {
//you must implement at least the methods below
    //you are free to add (and will likely need to add)
    //more members and methods

public:
    const DoublyLinkedList<T> *nodelist;
    const DoubleLinkedNode<T> *pos;

    ConstDoublyLinkedListIterator(const ConstDoublyLinkedListIterator &orig) {
        this->pos = orig.pos;
        this->nodelist = orig.nodelist;
    }

    ConstDoublyLinkedListIterator(const DoubleLinkedNode<T> *pos, const DoublyLinkedList<T> *list){
        this->nodelist = list;
        this->pos = pos;
    }
    int getSizeBefore()const  {
        int size = 0;
        auto tmp = this->pos->prev;
        while (tmp != nullptr) {
            size++;
            tmp = tmp->prev;
        }
        return size;
    }

    int getSizeAfter() const {
        int size = 0;
        auto tmp = this->pos->next;
        while (tmp != nullptr) {
            size++;
            tmp = tmp->next;
        }
        return size;
    }

    //are the two iterators equal?
    //they are if they are over the same doubly linked list
    //and (they are referring to the same element in the list
    //or they are out of bounds)
    bool operator==(const ConstDoublyLinkedListIterator<T> &rhs) const {
            if (this->nodelist!= rhs.nodelist){
                return false;
            }
            else if (this->pos==nullptr && rhs.pos==nullptr){
                return true;
            }
            else if (this->pos != rhs.pos){
                return false;
            }
            return true;
    }

    //are the two iterators different?
    bool operator!=(const ConstDoublyLinkedListIterator<T> &rhs) const {
        return (!(*this == rhs));
    }

    //is the iterator safe to dereference?
    operator bool() const {
        if (this->nodelist->getHead()==nullptr) {
            return false;
        }
        return true;
    }

    //go to the next element
    ConstDoublyLinkedListIterator<T> &operator++() {
        pos = pos->next;
        return *this;
    } //pre
    const ConstDoublyLinkedListIterator<T> operator++(int ) {
        auto copy(*this);
        ++(*this);
        return copy;
    }//post

    //go to the previous element
    ConstDoublyLinkedListIterator<T> &operator--() {
        pos = pos->prev;
        return *this;
    } //pre
    const ConstDoublyLinkedListIterator<T> operator--(int ) {
        auto copy(*this);
        --(*this);
        return copy;


    };
    //get a const reference to the value
    const T &operator*() const {
        return this->pos->data;
    }

};
#endif //TESTDOUBLELINKEDLIST_CONSTDOUBLYLINKEDLISTITERATOR_H