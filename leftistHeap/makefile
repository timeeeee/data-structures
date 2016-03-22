all: queue.o heap.o main.o
	g++ -o leftistHeap main.o queue.o heap.o

main.o: main.cpp
	g++ -c -o main.o main.cpp

queue.o: queue.h queue.cpp
	g++ -c -o queue.o queue.cpp

heap.o: heap.h heap.cpp
	g++ -c -o heap.o heap.cpp

clean:
	rm -f *~ *.o leftistHeap
