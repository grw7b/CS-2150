//In-lab 1
//Name: Gizella Wade
//ID; grw7b
//Due Date: 02/16/21

#ifndef LIFECYCLE_H
#define LIFECYCLE_H

#include <string>
#include <iostream>
using namespace std;

// Declare the MyObject class
class MyObject {
public:
    static int numObjs;

    MyObject();                    // default constructor
   MyObject(std::string n);            // constructor with name parameter
    MyObject(const MyObject& rhs); // copy constructor
    ~MyObject();                   // destructor

  std::string getName() const;
    void setName(const string& newName);

  friend std:: ostream& operator<<(std::ostream& output, const MyObject& obj);
private:
  std::string name;
    int id;


};

#endif




