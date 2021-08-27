//postfixCalculator.cpp
//Pre-lab 3
//Name: Gizella Wade
//ID: grw7b
//Due Date: 03/02/21

#include "postfixCalculator.h"
#include <string>
#include <iostream>
using namespace std;


Calculator::Calculator(){
  value = 0;
}


Calculator::Calculator (double v){
  value = v;
}



void  Calculator::operation (string  o, int x, int y){
  if (o == "+"){
    
     value  = x + y;
     
     
   }else if ( o == "-"){
    
     value = x - y;
    
  }else if (o == "*"){
    value = x*y;

  }else if (o == "/"){
    value = x/y;

  }


}
 


int  Calculator:: negation(int x){
  x = -x;
  return x;
}

int Calculator:: getValue() const{
  return value;

}
void Calculator::setValue(const int& v){
    value = v;

}
