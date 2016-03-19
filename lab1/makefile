all: main.o node.o linkedList.o
	g++ main.o node.o linkedList.o -o lab1

node.o: node.h node.cpp
	g++ -c node.cpp

main.o: main.cpp
	g++ -c main.cpp

linkedList.o: linkedList.h linkedList.cpp
	g++ -c linkedList.cpp

clean:
	rm -rf *.o *~ lab1
