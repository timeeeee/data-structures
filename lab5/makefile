all: main.o queue.o bst.o
	g++ main.o queue.o bst.o -o lab5

main.o: main.cpp
	g++ -c main.cpp

queue.o: queue.h queue.cpp
	g++ -c queue.cpp

bst.o: bst.h bst.cpp
	g++ -c bst.cpp

clean:
	rm -rf *~ lab5 *.o
