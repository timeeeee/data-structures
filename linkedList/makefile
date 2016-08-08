CXX=g++
CXXFLAGS=-g -Wall

all: main.o node.o linkedList.o
	$(CXX) $(CXXFLAGS) main.o node.o linkedList.o -o lab1

node.o: node.h node.cpp
	$(CXX) $(CXXFLAGS) -c node.cpp

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

linkedList.o: linkedList.h linkedList.cpp
	$(CXX) $(CXXFLAGS) -c linkedList.cpp

test.o: test.cpp
	$(CXX) $(CXXFLAGS) -c test.cpp

test_binary: test.o linkedList.o node.o
	$(CXX) $(CXXFLAGS) test.o node.o linkedList.o -o test

test: test_binary
	valgrind --leak-check=yes --track-origins=yes ./test

clean:
	rm -rf *.o *~ lab1 test
