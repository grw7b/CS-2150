# This is a comment      
#BSTSearchTree.o: BSTSearchTree.cpp BinarySearchTree.h BinaryNode.h
#BinaryNode.o: BinaryNode.cpp BinaryNode.h
#BinarySearchTree.o: BinarySearchTree.cpp BinaryNode.h BinarySearchTree.h 
#/Users/gizellawade/Desktop/CS 2150/lab 5                                                     

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
OBJECTS=BinaryNode.o BinarySearchTree.o BSTSearchTree.o

pizza: BinaryNode.o BinarySearchTree.o BSTSearchTree.o
	$(CXX) BinaryNode.o BinarySearchTree.o BSTSearchTree.o

BinaryNode.o: BinaryNode.cpp BinaryNode.h
	$(CXX) -c BinaryNode.cpp 

BinarySearchTree.o: BinarySearchTree.cpp BinaryNode.h BinarySearchTree.h
	$(CXX) -c BinarySearchTree.cpp 

BSTSearchTree.o: BSTSearchTree.cpp BinarySearchTree.h BinaryNode.h
	$(CXX) -c BSTSearchTree.cpp 


.PHONY: clean
clean:
	-rm -f *.o *~ a.out
