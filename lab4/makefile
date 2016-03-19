all: main.o Timer.o openHashTable.o closedHashTable.o linkedList.o node.o
	g++ main.o Timer.o openHashTable.o closedHashTable.o linkedList.o node.o -o lab4

main.o: main.cpp
	g++ -c main.cpp

Timer.o: Timer.cpp
	g++ -c Timer.cpp

openHashTable.o: openHashTable.h openHashTable.cpp
	g++ -c openHashTable.cpp

closedHashTable.o: closedHashTable.h closedHashTable.cpp
	g++ -c closedHashTable.cpp

linkedList.o: linkedList.h linkedList.cpp
	g++ -c linkedList.cpp

node.o: node.h node.cpp
	g++ -c node.cpp

clean:
	rm -rf lab4 *.o *~
