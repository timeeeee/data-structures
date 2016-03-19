all: main.o disjointSet.o minHeap.o
	g++ main.o disjointSet.o minHeap.o -o lab11

main.o: main.cpp
	g++ -c main.cpp

disjointSet.o: disjointSet.h disjointSet.cpp
	g++ -c disjointSet.cpp

minHeap.o: minHeap.h minHeap.cpp
	g++ -c minHeap.cpp

clean:
	rm -f *.o *~ lab11
