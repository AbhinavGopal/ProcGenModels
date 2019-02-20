//
// Created by Abhinav Gopal on 2019-02-17.
//
#include <iostream>
#ifndef HOMEWORK2_DOUBLYLINKEDLIST_H
#define HOMEWORK2_DOUBLYLINKEDLIST_H
template class<T>

class Node{
    T data;
    Node next;
    Node prev;
    Node(T data, Node next, Node prev);
    Node(T data);
};


class Doublylinkedlist{
    //has head, tail
    Node head;
    Node tail;
    Doublylinkedlist()
};

#endif //HOMEWORK2_DOUBLYLINKEDLIST_H