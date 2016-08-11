CXX=g++
CXXFLAGS=-g -Wall

all: demo

demo: demo.o node.o linkedList.o hashTable.o
	$(CXX) $(CXXFLAGS) demo.o node.o linkedList.o hashTable.o -o demo

node.o: ../linkedList/node.h ../linkedList/node.cpp
	$(CXX) $(CXXFLAGS) -c ../linkedList/node.cpp

demo.o: demo.cpp
	$(CXX) $(CXXFLAGS) -c demo.cpp

linkedList.o: ../linkedList/linkedList.h ../linkedList/linkedList.cpp
	$(CXX) $(CXXFLAGS) -c ../linkedList/linkedList.cpp

hashTable.o: hashTable.h hashTable.cpp
	$(CXX) $(CXXFLAGS) -c hashTable.cpp

test.o: test.cpp
	$(CXX) $(CXXFLAGS) -c test.cpp

build_test: test.o linkedList.o node.o hashTable.o
	$(CXX) $(CXXFLAGS) test.o node.o linkedList.o hashTable.o -o test

test: build_test
	valgrind --leak-check=yes --track-origins=yes ./test

clean:
	rm -rf *.o *~ demo test

.PHONY: test clean all
