#This is a comment    
#Lab 11: Pre-Lab
#Name: Gizella Wade
#ID: grw7b  

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2  # Enable all warnings
OBJECTS=topologicalsort.o

.SUFFIXES: .o .cpp

pizza: topologicalsort.o
	$(CXX) topologicalsort.o
	doxygen

.PHONY: clean
clean:
	-rm -f *.o *~ a.out