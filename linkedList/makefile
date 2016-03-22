all: main.o node.o linkedList.o
	g++ main.o node.o linkedList.o -o lab1

node.o: node.h node.cpp
	g++ -c node.cpp

main.o: main.cpp
	g++ -c main.cpp

linkedList.o: linkedList.h linkedList.cpp
	g++ -c linkedList.cpp

test.o: test.cpp
	g++ -c test.cpp

test_binary: test.o linkedList.o node.o
	g++ test.o node.o linkedList.o -o test

test: test_binary
	./test

clean:
	rm -rf *.o *~ lab1 test
