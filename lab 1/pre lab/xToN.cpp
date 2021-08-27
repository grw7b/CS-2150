//Pre-lab 1: xToN
//Name: Gizella Wade
//ID; grw7b
//Due Date: 02/16/21

#include <iostream>
using namespace std;

int xton(int a, int b){
  int expon;
  
  if (b==0)
     return 1;

  if (b==1)
    expon =  a;
  else
    expon = a * xton(a,b-1);

  return expon;    
}

int main(){
  int x, y,z;
  cin >> x;
  cin >> y;
  z = xton(x,y);
  cout << "x  to the y  power  =  " << z << endl;

  return 0;
}
    
