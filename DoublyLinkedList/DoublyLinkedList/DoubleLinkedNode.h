//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_DOUBLELINKEDNODE_H
#define LINKEDLIST_DOUBLELINKEDNODE_H
#include <iostream>

//the class that represents a node in the list

template<typename T>
class DoubleLinkedNode {
    public:
        T data;
        DoubleLinkedNode<T>* next;
        DoubleLinkedNode<T>* prev;
        DoubleLinkedNode(const T& ndata);

        };
template<typename T>
DoubleLinkedNode<T>::DoubleLinkedNode(const T& ndata):data(ndata), next(nullptr), prev(nullptr){
}

#endif //LINKEDLIST_DOUBLELINKEDNODE_H
