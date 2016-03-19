all: main.o minMaxHeap.o
	g++ main.o minMaxHeap.o -o lab6

main.o: main.cpp
	g++ -c main.cpp

minFiveHeap.o: minMaxHeap.h minMaxHeap.cpp
	g++ -c minMaxHeap.cpp

clean:
	rm -rf lab6 *.o *~
