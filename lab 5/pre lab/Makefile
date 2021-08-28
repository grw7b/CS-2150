# This is a comment   
#TreeCalc.o: TreeCalc.cpp TreeCalc.h TreeNode.h
#TreeCalcTest.o: TreeCalcTest.cpp TreeCalc.h TreeNode.h
#TreeNode.o: TreeNode.cpp TreeNode.h                                                        

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
OBJECTS=TreeNode.o TreeCalc.o TreeCalcTest.o

pizza: TreeNode.o TreeCalc.o TreeCalcTest.o 
	$(CXX) TreeNode.o TreeCalc.o TreeCalcTest.o 

TreeNode.o: TreeNode.cpp TreeNode.h
	$(CXX) -c TreeNode.cpp 

TreeCalc.o: TreeCalc.cpp TreeCalc.h TreeNode.h
	$(CXX) -c TreeCalc.cpp 

TreeCalcTest.o: TreeCalcTest.cpp TreeCalc.h TreeNode.h
	$(CXX) -c TreeCalcTest.cpp 


.PHONY: clean
clean:
	-rm -f *.o *~ a.out
