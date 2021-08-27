//Post-lab 2
//Name: Gizella Wade
//ID; grw7b
//Due Date: 02/26/21

#include "ListItr.h"
#include "List.h"
#include "ListNode.h"
#include <iostream>


ListItr::ListItr(){
  current = nullptr;

}


ListItr::ListItr(ListNode* theNode){
  current = theNode;

}


bool ListItr:: isPastEnd() const{
  if ( current -> next == nullptr){
    
    return true;
    
  }
  
  return false;
}


bool ListItr::isPastBeginning() const{ 
  if (current->previous == nullptr){
    
    return true;
    
  }
  
  return false;

}


void ListItr:: moveForward(){
  if(isPastEnd()==false){
    current =  current->next;
  }
}


void ListItr:: moveBackward(){
  if (isPastBeginning()==false){
    current = current -> previous;
  }
}


int ListItr:: retrieve() const{
  
  return current->value;
  
}















