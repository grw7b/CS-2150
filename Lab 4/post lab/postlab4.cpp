//Lab 4
//Name: Gizella Wade
//ID; grw7b
//Due Date: 03/19/21

#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <cmath>
#include <iostream>
using namespace std;


int bitCounter(int x){
  int count = 0;

  if (x==0){
    return 0;
  }

  if (x==1){
    return 1;
  }
  if(x%2 != 0){
    return 1 + bitCounter(x/2);
  }
  
  if (x%2==0){
    return bitCounter(x/2);
  }

 
}


void baseConverter( string numberToConvert, int startBase, int endBase){
  string letters = {'A','B','C','D','E','F'};
   
  string numbers = {'1','2','3','4','5','6','7','8','9'};
 
  int sq = 0;
  int result = 0;
  int num = 0;

  int w = 0;
  string z = "";

  char wS;
  

   
  if (startBase == endBase){
    cout<< numberToConvert <<  " (base " << startBase << ") = " << numberToConvert << "(base " <<  endBase << ")"<< endl;
   
  }
  else{
    for (int i = numberToConvert.size(); i >= 0; i--){
      if (letters.find(numberToConvert[i])){
	if (numberToConvert[i] == 'A'){
	  result += 10 * pow(startBase,sq);
	}
	if (numberToConvert[i] == 'B'){
	  result += 11 * pow(startBase,sq);
	}
	if (numberToConvert[i] == 'C'){
	  result += 12 * pow(startBase,sq);
	}
	if (numberToConvert[i] == 'D'){
	  result += 13 *  pow(startBase,sq);
	}
	if (numberToConvert[i] == 'E'){
	  result += 14 * pow(startBase,sq);
	}
	if (numberToConvert[i] == 'F'){
	  result += 15 *  pow(startBase,sq);
	}


      }
      else if(numbers.find(numberToConvert[i])){
	num = int(numberToConvert[i]); result += num * pow(startBase,sq);

    }
     sq++;
	
  }


    while ((result / endBase) >= 1){
      if (result % endBase != 0){
        w = result % endBase;
	wS = (char) w;
        z+= wS;

      }	
      else{
	result = (result % endBase) * 10;

      }	

    }

    reverse(z.begin(),z.end());
   
    cout<< numberToConvert <<  " (base " << startBase << ") = " << z << "(base " <<  endBase << ")"<< endl;
  }

}



int main (int argc, char **argv){
  
  int c = 0;
  c = atoi(argv[1]);
  string nums = "";
  nums+= argv[2];
  int sB = 0;
  sB = atoi(argv[3]);
  int eB = 0;
  eB= atoi(argv[4]);

    
  int y = 0;
  y = bitCounter(c);

  cout<< c << " has " << y << " bit(s) " << endl;
 
  baseConverter (nums, sB, eB);

  return 0;
}
