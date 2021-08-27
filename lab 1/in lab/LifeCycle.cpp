//In-lab 1
//Name: Gizella Wade
//ID; grw7b
//Due Date: 02/16/21

#include "LifeCycle.h"
#include <iostream>
using namespace std;

// Constructors and destructors - no return types
MyObject::MyObject() {
    // Important: notice how we don't define 'name' or 'id' here
    // Instead, we're setting the variables that we declared in MyObject
    name = "--default--";
    id = ++numObjs;
    cout << "MyObject Default constructor:   " << *this << endl;
}

MyObject::MyObject(std::string n) {
    name = n;
    id = ++numObjs;
    cout << "MyObject Parameter constructor: " << *this << endl;
}

MyObject::MyObject(const MyObject& rhs) {
    name = rhs.name;
    id = ++numObjs;
    cout << "MyObject Copy constructor:      " << *this << endl;
}

MyObject::~MyObject() {
    cout << "MyObject Destructor:            " << *this << endl;
}


// Regular methods, with return types
std::string MyObject::getName() const {
    return name;
}

void MyObject::setName(const std::string& newName) {
    name = newName;
}

// Let cout know how to print MyObjects
std::ostream& operator<<(std::ostream& output, const MyObject& obj) {
    // output in format: ("object name", id)
    return output << "(\"" << obj.name << "\", " << obj.id << ")";
}


// Static variables
int MyObject::numObjs = 0;  // static member for all objects in class
static MyObject staticObj("I'm static, outside of main");


