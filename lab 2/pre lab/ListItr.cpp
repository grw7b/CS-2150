//Pre-lab 2
//Name: Gizella Wade
//ID; grw7b
//Due Date: 02/23/21

#include "ListItr.h"
#include "List.h"
#include "ListNode.h"
#include <iostream>

ListItr::ListItr(){

 current = NULL;

}


ListItr::ListItr(ListNode* theNode){

  current = theNode;

}


bool ListItr:: isPastEnd() const{
  ListNode*  t = new ListNode();
  t = NULL;
  if ( current == t->next){
    return true;
  }

  return false;
}

bool ListItr::isPastBeginning() const{
  ListNode*  h = new ListNode();
  h = NULL;
  if (current == h->next){
    return true;
  }

  return false;

}



void ListItr:: moveForward(){
  current -> next = current;

}




void ListItr:: moveBackward(){

  current -> previous = current;

}



int ListItr:: retrieve() const{
  int nodevalue = current->value;

  return nodevalue;

}
















