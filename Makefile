CXX = g++
CXXFLAGS = -g -std=c++11 -Wall

SRCS = $(wildcard *.hpp)
OBJECTS = $(SRCS: .hpp=.o)

all: Matrix Vanilla

clean:
	rm -rf *.dSYM
	$(RM) *.o *.gc* test/*.o Vanilla Matrix core main

Matrix: $(OBJECTS) testMatrix.cpp Matrix.cpp Matrix.hpp
	$(CXX) $(CXXFLAGS) -o $@ $^

Vanilla: $(OBJECTS) testVanilla.cpp Vanilla.cpp Vanilla.hpp Matrix.cpp Matrix.hpp
	$(CXX) $(CXXFLAGS) -o $@ $^