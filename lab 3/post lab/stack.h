//stack.cpp
//Lab 3
//Name: Gizella Wade
//ID: grw7b
//Due Date: 03/05/21

#ifndef STACK_H
#define STACK_H

#include "stacknode.h"
#include <string>
#include <iostream>
using namespace std;

class Stack{

 public:
  
  Stack();

  void push (int e);

  int  top();
  
  void pop();

  bool empty();

  int size();

 private:
  StackNode* start;
  int count;

};

#endif

