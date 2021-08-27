//stack.cpp                                                                     
//Lab 3                                                                         
//Name: Gizella Wade                                                            
//ID: grw7b                                                                     
//Due Date: 03/05/21                                                            

#include "stack.h"
#include "stacknode.h"
#include <iostream>
using namespace std;



Stack::Stack(){
 start = nullptr;
 count = 0;

}


void Stack::push(int e){
  StackNode* newNode = new StackNode();
  newNode->value = e;
  newNode->next = start;
  start = newNode;
  count ++;



}


int Stack::top(){
  if(empty() == false){
    return start->value;
  }
}


void Stack::pop(){
  if (empty() == false){
    start = start->next;
    count--;
    
 }

}



bool Stack::empty(){
  if (count == 0){
    return true;
  }

  return false;

}



int Stack::size(){
  return count;

}

