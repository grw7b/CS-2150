//testPostfixCalculator.cpp
//Pre-lab 3
//Name: Gizella Wade
//ID: grw7b
//Due Date: 03/02/21

#include "postfixCalculator.h"
#include <iostream>
#include <stack>
using namespace std;

int main(){

  Calculator* c = new Calculator();

  string s;

  stack <int> numbers;

  int result = 0;

  while (cin >> s) {
    if(s != "+" && s != "-" && s!= "*" && s!= "/" && s != "~"){
       
      numbers.push(stoi(s));

       
     }
    else if (s.length()>=2 && s[0] == '-'){
      int x = stoi(s.substr(1,s.length()));
      
      numbers.push(-x);

    }
    else if (s == "~"){
      int m = numbers.top();
      numbers.pop();
      int n = m * -1;
      numbers.push(n);

      //cout << numbers.top() <<  endl;
      

    }
    else if (s == "+" || s == "-" || s == "*"|| s == "/"){
      while (numbers.size()>=2){
	
	int a = numbers.top();
	
	numbers.pop();
	
	int b = numbers.top();
	
	numbers.pop();
	
	c->operation(s,b,a);
	
	numbers.push(c->getValue());

	result = numbers.top();
	  	 
      }

       
    }  
  
    
    
  }

 
  cout<< numbers.top()  << endl;



}
