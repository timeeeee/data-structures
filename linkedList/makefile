CXX=g++
CXXFLAGS=-g -Wall

all: demo

demo: demo.o node.o linkedList.o
	$(CXX) $(CXXFLAGS) demo.o node.o linkedList.o -o demo

node.o: node.h node.cpp
	$(CXX) $(CXXFLAGS) -c node.cpp

demo.o: demo.cpp
	$(CXX) $(CXXFLAGS) -c demo.cpp

linkedList.o: linkedList.h linkedList.cpp
	$(CXX) $(CXXFLAGS) -c linkedList.cpp

test.o: test.cpp
	$(CXX) $(CXXFLAGS) -c test.cpp

build_test: test.o linkedList.o node.o
	$(CXX) $(CXXFLAGS) test.o node.o linkedList.o -o test

test: build_test
	valgrind --leak-check=yes --track-origins=yes ./test

clean:
	rm -rf *.o *~ demo test
