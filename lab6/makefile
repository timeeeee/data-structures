all: main.o minHeap.o
	g++ main.o minHeap.o -o lab6

main.o: main.cpp
	g++ -c main.cpp

minFiveHeap.o: minHeap.h minHeap.cpp
	g++ -c minHeap.cpp

clean:
	rm -rf lab6 *.o *~
