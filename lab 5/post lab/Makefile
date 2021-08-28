# This is a comment      
# AVLNode.o: AVLNode.cpp AVLNode.h
# AVLPathTest.o: AVLPathTest.cpp AVLTree.h AVLNode.h
# AVLTree.o: AVLTree.cpp AVLNode.h AVLTree.h      
# /Users/gizellawade/Desktop/CS 2150/lab 5/post lab                                             

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
OBJECTS=AVLNode.o AVLTree.o AVLPathTest.o

pizza: AVLNode.o AVLTree.o AVLPathTest.o
	$(CXX) AVLNode.o AVLTree.o AVLPathTest.o

AVLNode.o: AVLNode.cpp AVLNode.h
	$(CXX) -c AVLNode.cpp 

AVLTree.o: AVLTree.cpp AVLNode.h AVLTree.h
	$(CXX) -c AVLTree.cpp 

AVLPathTest.o: AVLPathTest.cpp AVLTree.h AVLNode.h
	$(CXX) -c AVLPathTest.cpp 


.PHONY: clean
clean:
	-rm -f *.o *~ a.out
