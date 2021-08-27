//postfixCalculator.h
//Pre-lab 3
//Name: Gizella Wade
//ID: grw7b
//Due Date: 03/02/21

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H


#include <stack>
#include <string>
#include <iostream>
using namespace std;

class Calculator{

 public:
  
  Calculator();

  Calculator (double v);

  void operation (string  o, int x, int y);

  int  negation (int x);
  
  int  getValue() const;

  void setValue(const int& v);

 private:
  int value;

};

#endif

