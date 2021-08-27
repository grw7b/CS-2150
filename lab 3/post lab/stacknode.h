//stacknode.h
//Lab 3
//Name: Gizella Wade
//ID: grw7b
//Due Date: 03/05/21

#ifndef STACKNODE_H
#define STACKNODE_H

#include <iostream>


class StackNode {
public:
    StackNode();         // Constructor

private:
  int value;
  StackNode* next;
    
    friend class Stack;

};

#endif
