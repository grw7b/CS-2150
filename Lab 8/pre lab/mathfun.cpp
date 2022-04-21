// mathfun.cpp
//Lab 8: Pre-Lab
//Name: Gizella Wade
//ID; grw7b
#include <iostream>
#include <cstdlib>

using namespace std;

extern "C" int product(int, int);
extern "C" int power(int, int);


int  main () {

    int x, y, prod, powr;

    cout << "Enter integer 1: ";
    cin >> x;
    cout<< x << endl;

    cout << "Enter integer 2: ";
    cin >> y;
    cout<< y << endl;

    prod = product(x, y);
    powr = power(x, y);
    cout << "Product: " << prod << endl;
    cout << "Power: " << powr << endl;

    return 0;
}