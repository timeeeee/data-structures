all: main.o minHeap.o queue.o bst.o
	g++ main.o minHeap.o queue.o bst.o -o lab7

main.o: main.cpp
	g++ -c main.cpp

minFiveHeap.o: minHeap.h minHeap.cpp
	g++ -c minHeap.cpp

queue.o: queue.h queue.cpp
	g++ -c queue.cpp

bst.o: bst.h bst.cpp
	g++ -c bst.cpp

clean:
	rm -rf *~ lab7 *.o
