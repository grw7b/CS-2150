//Post-lab 2
//Name: Gizella Wade
//ID; grw7b
//Due Date: 02/26/21

#include  "List.h"
#include <iostream>


List::List(){
  head=new ListNode();
  tail= new ListNode();
  head->next = tail;
  tail->previous = head;
  count=0;

}

List::List(const List& source) {
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}


List::~List(){
  makeEmpty();
  delete head;
  delete tail;
}

// Copy assignment operator
// Called when the code looks something like list2 = list1;
// (In other words, it is called when you are trying to set an **existing** list equal to another one)
List& List::operator=(const List& source) {
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}


bool List:: isEmpty() const{

  if (count==0){

    return true;
    
  }

  return false;
  
}


void List::makeEmpty(){
  ListNode* afterHead = new ListNode();
  head->next = afterHead;
  ListNode* afterAfterHead = new ListNode();
  afterHead-> next = afterAfterHead;
  ListNode* nodeDel = new ListNode();
  ListNode* temp = new ListNode();
  
  while (isEmpty()==false){
    afterAfterHead = temp;
    nodeDel = afterHead;
    afterHead = nullptr;
    afterHead = temp;
    afterHead -> next = afterAfterHead;
    count--;
  }

  
 

}


ListItr List:: first(){

  ListItr x (head->next);
  
  return x;

}


ListItr List:: last(){

  ListItr x (tail->previous);
 
  return x;



  
}


void List::insertAfter(int x, ListItr position){
  ListNode* p  = new ListNode();
  p = position.current;
  ListNode* c = new ListNode();
  c->value = x;
  c->next = p->next;
  c->previous = p;
  p->next->previous = c;
  p->next = c;
  count++;

}


void List::insertBefore(int x, ListItr position){
  ListNode* p  = new ListNode();
  p = position.current;
  ListNode* c = new ListNode();
  c->value = x;   
  c->previous = p->previous;
  c->next = p;
  p->previous->next = c;
  p->previous = c;
  count++;

}


void List:: insertAtTail(int x){
  ListNode* atTail = new ListNode();
  atTail->value = x; 
  atTail->previous = tail->previous;
  atTail->next = tail;
  tail->previous->next = atTail;
  tail->previous = atTail;
  count++;
 
}


ListItr List:: find(int x){
  ListNode* current = new ListNode();
  current = head->next;
  ListNode* beforeCurrent  = new ListNode();
  beforeCurrent = head;
  ListNode* afterCurrent = new ListNode();
  afterCurrent = current->next;

  int a = 0;
  int c = 0;
  while(current!=nullptr && a < count  && c < 1){
    if (current->value != x){
      beforeCurrent = current;
      current = current->next;
      a++;
  
    }else if (current->value == x){
      c++;
      ListItr i (current);
      return i;
    
    }
    
  }
  
  ListItr t (tail);
  return t;

  //delete current;
  //delete beforeCurrent;
  // delete afterCurrent;
  
}


void List::remove(int x){
  ListNode* current = new ListNode();
  current = head->next; 
  ListNode* beforeCurrent  = new ListNode();
  beforeCurrent = current -> previous;
  ListNode* afterCurrent = new ListNode();
  afterCurrent = current -> next;

  int c = 0;
  int a = 0;
  
  while(current!=nullptr && c < 1){
    if (current->value != x){
      beforeCurrent = current;
      current = current->next;
      afterCurrent = current-> next;
      a++;
  
    }else if (current->value == x){
      beforeCurrent->next = afterCurrent;
      afterCurrent->previous = beforeCurrent;
      c++;
      count--;

    }
    
  }
  //delete current;
  //delete beforeCurrent;
  //delete afterCurrent;
  
}


int List:: size() const{
  
  return count;
  
}



void printList(List& source, bool forward){
  List* c = new List();
  c = &source;
  int a  = 0;
  
  if(c->isEmpty()==true){
      cout<< "List empty" << endl;
  }
  
  if (forward==true){
    ListItr i (c->first());
    
    while (a <  c->size()){
     int q = i.retrieve();
     cout << q << endl;
     i.moveForward();
     a++;
     
    } 
  }

  if (forward==false){
     ListItr i (c->last());

      while (a<c->size()){
       int q = i.retrieve();
       cout << q << endl;
       i.moveBackward();
       a++;
     }

  }
  
  cout<< "done listing" << endl;

  //delete c;
    

}
