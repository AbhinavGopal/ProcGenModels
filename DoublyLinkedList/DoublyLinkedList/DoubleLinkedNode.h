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
        T* data;
        DoubleLinkedNode* next;
        DoubleLinkedNode* prev;
        explicit DoubleLinkedNode(T ndata){
                *data=ndata;
                next= nullptr;
                prev= nullptr;
            }

        };



#endif //LINKEDLIST_DOUBLELINKEDNODE_H
