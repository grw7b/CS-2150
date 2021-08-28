#This is a comment    
#Lab 11: In-Lab
#Name: Gizella Wade
#ID: grw7b  
#middleearth.o: middleearth.cpp middleearth.h
#traveling.o: traveling.cpp middleearth.h

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2  # Enable all warnings
OBJECTS=middleearth.o traveling.o

.SUFFIXES: .o .cpp

pizza: middleearth.o traveling.o
	$(CXX) middleearth.o traveling.o
	doxygen	

middleearth.o: middleearth.cpp middleearth.h
	$(CXX) -c middleearth.cpp

traveling.o: traveling.cpp middleearth.h
	$(CXX) -c traveling.cpp

.PHONY: clean
clean:
	-rm -f *.o *~ a.out