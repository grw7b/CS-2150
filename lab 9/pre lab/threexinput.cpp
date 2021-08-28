// threexplusone.cpp
// Lab 9: Pre-Lab
// Name: Gizella Wade
// ID: grw7b

#include <iostream>
#include <cstring>
#include "timer.h"
using namespace std;

extern "C"  int threexplusone(int);

int main(){
	int x;
	int n;

    cout << "Enter a number: ";
    cin >> x;
    if (x <= 0){
    	cout << "invalid input" << endl;	
    }

    else {
    	cout << x << endl;

    	cout << "Enter iterations of subroutine: ";
    	cin >> n;
    	cout << n << endl;
    	
    	int output = 0;


    	// run input n times
        timer t;
        t.start();

    	for(int i = 0; i < n; i++) {

    		threexplusone(x);
    	}
        
        t.stop();
        

        output = threexplusone(x);

        cout << "Steps: " << output << endl;
        
    	

       if (n > 0){
    
          t.getTime()*1000/n;
        }
    

    }
    
    /*
    // timing tests
    timer t;
    t.start();
    for(int i = 0; i < n; i++){
        collatz(x);
    }
    t.stop();

    if (n > 0){
    
        cout << "Average time " << t.getTime()*1000/n << "ms" << endl;

    }

    
    */

    return 0;

}