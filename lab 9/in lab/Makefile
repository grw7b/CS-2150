#Lab 9: In-Lab
#Name: Gizella Wade
#ID; grw7b
#/Users/gizellawade/Desktop/CS 2150/lab 9/in lab
# Defines the C compiler we'll be using
CXX = clang

# Defines the flags we'll be passing to the C compiler
CXXFLAGS = -Wall


.SUFFIXES: .o .c


# All of the .o files for our program
OBJECTS = linkedlist.o

# Compile our files into a.out
a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)

# This will clean up (remove) all our object files.  The -f option
# tells rm to forcily remove the files (i.e. don't ask if they should
# be removed or not).  This removes object files (*.o) and Emacs
# backup files (*~)
clean:
	-rm -f *.o *~