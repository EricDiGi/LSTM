CXX = g++
CXXFLAGS = -g -std=c++11 -Wall

SRCS = $(wildcard *.hpp)
OBJECTS = $(SRCS: .hpp=.o)

all: Matrix Vanilla

Matrix: $(OBJECTS) testMatrix.cpp Matrix.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

Vanilla: $(OBJECTS) testVanilla.cpp Vanilla.cpp Matrix.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf *.dSYM
	$(RM) *.o *.gc* test/*.o core main