//Pre-lab 2
//Name: Gizella Wade
//ID; grw7b
//Due Date: 02/23/21

#include  "List.h"
#include <iostream>


List::List(){
   head=new ListNode();
   tail=new ListNode();
   head->next=tail;
   tail->previous=head;
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
  // h = new List();
  ListNode*  afterHead = new ListNode();
  head->next = afterHead;
  ListNode*  beforeTail = new ListNode();
  tail->previous = beforeTail;

  if (afterHead == NULL  & beforeTail == NULL){
    return true;
  }

  return false;
  
}

void List::makeEmpty(){
  int i = 0;
  ListNode* afterHead = new ListNode();
  afterHead = head->next;
  ListNode* afterAfterHead = new ListNode();
  afterHead-> next = afterAfterHead;
  

  while (i < count + 1){
    afterHead = NULL;
    afterHead = afterAfterHead;
    afterHead -> next = afterAfterHead;
    i++;
    

  }

}

ListItr List:: first(){
  // ListNode* nodeAfterHead = (head -> next);

  // ListItr result = new ListItr(head->next);

  return ListItr(head->next);
}

ListItr List:: last(){
  //ListNode beforeTail =  tail -> previous;

  //ListItr result = new ListItr(beforeTail);

  return ListItr(tail->previous);
}

void List::insertAfter(int x, ListItr position){
  ListItr result;
  ListNode* headNext = new ListNode();
  head->next = headNext;
  ListItr* afterHead = new ListItr (headNext);
  ListItr* point_position = &position;
  

  if (afterHead == point_position){
    headNext -> next -> value  = x;
    
  }
  else {
    headNext-> next = headNext;
    afterHead = new  ListItr(headNext);
    
  }

  
}

void List::insertBefore(int x, ListItr position){
  ListItr result;
  ListNode* headNext = new ListNode();
  head->next = headNext;
  ListItr* afterHead = new ListItr(headNext);
  ListItr* point_position = &position;
  if (afterHead == point_position){
     headNext -> previous -> value = x;
   
    
  }

  else {
     headNext-> next = headNext;
      
    
  }
  
}


void List:: insertAtTail(int x){
  ListNode* afterTail = new ListNode();
  tail -> next = afterTail;
  afterTail->value = x;
}

ListItr List:: find(int x){
  ListItr result;
  int i = 0;
  ListNode* headNext = new ListNode();
  head->next = headNext;
  

  if (i != x && i < count + 1){
    headNext-> next = headNext;
    i++;
  }

  else{
    
    cout<< "Done!" << endl;
  }

  return ListItr(headNext);

}


void List::remove(int x){

  int i = 0;
  ListNode* afterHead = new ListNode();
  head->next = afterHead;
  

  if (i != x && i < count + 1){
    afterHead -> next = afterHead;
    i++;
  }

  else{
    afterHead = NULL;

  }
  
}

int List:: size() const{
  int i = 0;
  ListNode* a = new ListNode();
  head->next = a;
  while(a != NULL){
    i++;
    a->next = a;
    }
  return i;
}


void printList(List& source, bool forward){
  
  /* List* x = new List();
  x = &source;
  ListNode* i = new ListNode();
  for (i : x){
    if (i != NULL){
      cout << i << endl;
    }
  }
  ListNode* h = NULL;
  ListNode* t = NULL;
  ListItr* tail = new ListItr(t);
  ListItr* head = new ListItr(h);

  ListNode* headNext = new ListNode();
  headNext = insertAfter(0, head);
  ListNode* tailBefore = new ListNode();
  tailBefore = insertAfter(0,headNext)

  ListNode* currentNode = headNext;
  ListNode* lastNode = tailBefore;
  int currentNodeValue = currentNode->value; 
   
  while (currentNode != lastNode){
    cout << currentNodeValue << endl;
    currentNode = currentNode-> next;
    currentNodeValue = currentNode-> value;


  List* start = new List();
  this -> start = source;
  start = (source.head);
  ListItr iter(source);
  ListItr stop(source.);
  while (iter != stop) {
       start = iter.moveForward();
       cout << start << endl;
    }
  
  
  int n;
  int i = 0;
  int x;
  
  List* s = new List();
  s = &source;
  ListNode* h = new ListNode;

  s.size() = n;
  
  if(i < n + 1){
    n = s -> h -> value;
    cout<< x << endl;
  }
  */
  List* h = new List();

  h = &source;

  // h-> retrieve() = n;

  cout << h << endl;

}
