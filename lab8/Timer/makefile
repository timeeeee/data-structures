all: leftistHeap.o leftistQueue.o skewHeap.o skewQueue.o main.o timer.o
	g++ -o lab8 leftistHeap.o leftistQueue.o skewHeap.o skewQueue.o main.o timer.o

main.o: main.cpp
	g++ -c -o main.o main.cpp

leftistHeap.o: leftistHeap.h leftistHeap.cpp
	g++ -c -o leftistHeap.o leftistHeap.cpp

leftistQueue.o: leftistQueue.h leftistQueue.cpp
	g++ -c -o leftistQueue.o leftistQueue.cpp

skewHeap.o: skewHeap.h skewHeap.cpp
	g++ -c -o skewHeap.o skewHeap.cpp

skewQueue.o: skewQueue.h skewQueue.cpp
	g++ -c -o skewQueue.o skewQueue.cpp

timer.o: Timer.cpp
	g++ -c -o timer.o Timer.cpp

clean:
	rm -f *~ *.o \#*\# lab8
