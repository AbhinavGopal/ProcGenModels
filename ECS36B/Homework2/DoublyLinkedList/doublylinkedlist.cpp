//
// Created by Abhinav Gopal on 2019-02-17.
//

#include "doublylinkedlist.h"
Node(T data, Node next, Node prev) data(data), next(next),prev(prev){}
Node(T data){
    data=data;
    next=nullptr;
    prev=nullptr;
}
Doublylinkedlist()