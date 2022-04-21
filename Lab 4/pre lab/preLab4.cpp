
//Lab 4
//Name: Gizella Wade
//ID; grw7b
//Due Date: 03/16/21

#include <limits.h>
#include <iostream>
#include <cmath>
using namespace std;


void sizeOfTest(){

  cout << "Size of int: " << sizeof(int) << endl;

  cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;

  cout << "Size of float: " << sizeof(float) << endl;

  cout << "Size of double: " << sizeof(double) << endl;

  cout << "Size of char: " << sizeof(char) << endl;

  cout << "Size of bool: " << sizeof(bool) << endl;

  cout << "Size of int*: " << sizeof(int*) << endl;

  cout << "Size of char*: " << sizeof(char*) << endl;

  cout << "Size of double*: " << sizeof(double*) << endl;


}





void overflow(){

  unsigned int x;

  x = UINT_MAX;

  int result = x + 1;

  cout << x << " + 1 = " << result << endl;

}






void outputBinary(unsigned int x){

  string num = "";

  

  for (int i = 31; i >= 0; i--){
    int y = pow(2,i);
      
    if((i+1)%4==0 && i!=31){
      num+= " ";

    }
    if(x/y!=0){
      num+="1";
      x = x - y;
    }
    else{
        num+="0";

    }

  }
  cout<<  num << endl;

}







int main(){
 int x;
 
 cin >> x;

 sizeOfTest();

 overflow();

 outputBinary(x);

 return 0;

}
