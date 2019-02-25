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
//    friend std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& doublyLinkedList);
//    friend std::istream& operator>>(std::istream& in, DoublyLinkedList<T>& doublyLinkedList);
    void setHead(const DoubleLinkedNode<T> *head) {
        DoublyLinkedList::head = head;
    }

    void setTail(const DoubleLinkedNode<T> *tail) {
        DoublyLinkedList::tail = tail;
    }

    using Node_Ptr = DoubleLinkedNode<T>*;

    using iterator =  DoublyLinkedListIterator<T>;
    using const_iterator =  ConstDoublyLinkedListIterator<T>;
    using reverse_iterator = ReverseDoublyLinkedListIterator<T>;
    using const_reverse_iterator = ConstReverseDoublyLinkedListIterator<T>;

    //create a Doubly Linked List that has the same values
    //as in the vector and in the same order
    explicit DoublyLinkedList(const std::vector<T>& values){
        int i=0;
        Node_Ptr temp;//= nullptr;
        for (const auto value : values){
            if (head==nullptr){
                temp=new DoubleLinkedNode<T>(value);
                head=temp;
                temp->prev=nullptr;
                temp->next=nullptr;
            }
            else{
                auto t1=new DoubleLinkedNode<T>(value);
                tail=t1;
                temp->next=tail;
                tail->prev=temp;
                temp=tail;
                temp->next=nullptr;
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

    DoubleLinkedNode<T> *getHead() {
        return head;
    }

    DoubleLinkedNode<T> *getTail() {
        return tail;
    }

    const DoubleLinkedNode<T> *constGetHead() const {
        return head;
    }

    const DoubleLinkedNode<T> *constGetTail() const {
        return tail;
    }

    int getLen() const {
        return len;
    }

    virtual ~DoublyLinkedList(){
        auto temp=this->getTail();
        while (temp!=nullptr){
            temp=temp->prev;
            delete(temp->next);
        }
        delete(this->getHead());
    }

    //remove all of the elements from your list
    void clear(){
        auto tmp = this->getTail();
        while (tmp->prev!=nullptr){
            tmp=tmp->prev;
            delete(tmp->next);
        }
        delete(tmp);
    }

    //get a reference to the front element in the list
    const T& front() const{
        return head->data;
    }
    T& front(){
        return head->data;
    }

    //get a reference to the last element in the list
    const T& back() const{
        return tail->data;
    }
    T& back(){
        return tail->data;
    }

    //add a value to the front of the list
    void push_front(const T& value){
        this->head->prev=new DoubleLinkedNode<T>(value);
        this->head->prev->next=this->head;
        this->head=this->head->prev;
    }

    //add a value to the back of the list
    void push_back(const T& value){
        this->tail->next=new DoubleLinkedNode<T>(value);
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
        return const_iterator(this->constGetHead(), this);
    }
    const_iterator end() const{
        return const_iterator(this->constGetTail(), this);
    }

    //return a nonconstant bidirectional iterator to the front of the list
    iterator begin(){
        return iterator(this->getHead(), this);
    }
    iterator end(){
        return iterator(this->getTail(), this);
    }

    const_reverse_iterator crbegin() const{
        return const_reverse_iterator(this->constGetTail(), this);
    }
    const_reverse_iterator crend() const{
        return const_reverse_iterator(this->constGetHead(), this);
    }

    reverse_iterator rbegin(){
        return reverse_iterator(this->getHead(), this);
    }
    reverse_iterator rend(){
        return reverse_iterator(this->getTail(), this);
    }

    //insert the value at the position in the list
    //I promise not to use the iterator again after the insertion is done
    //An example if we had the list 1 <-> 9 <-> 17
    //And the iterator was pointing to the 9 and we wanted to
    //insert -22 the result would be
    //1 <-> 22 <-> 9 <-> 17
    void insert(iterator& position, const T& value){
        auto toadd=new DoubleLinkedNode<T>(value);
        auto tmp=position.pos;
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
        int index=position.getSizeBefore();
        auto tmp=this->getHead();
        for (int i=0;i<index;i++){
            tmp=tmp->next;
        }
        tmp->prev->next=tmp->next;
        tmp->next->prev=tmp->prev;
        delete(tmp);
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
        std::cout << *(itr->pos->data) <<" ";
    }

    return out;

}

//read elements from the stream as long as it is good
// or until a newline (\n) is encountered
//if a newline is encountered it should be consumed
template<typename T>
std::istream& operator>>(std::istream& in, DoublyLinkedList<T>& doublyLinkedList){
    T first;
    in>>first;
    doublyLinkedList->setHead(new DoubleLinkedNode<T>*(first));
    DoubleLinkedNode<T>* temp=doublyLinkedList->head;
    in>>first;
    while (first!=EOF){
        temp->next=&(new DoubleLinkedNode<T>*(first));
        temp->next->prev=temp;
        temp=temp->next;
        in>>first;
    }
    doublyLinkedList->setTail(temp);
    return in;
}


#endif //LINKEDLIST_DOUBLYLINKEDLIST_H