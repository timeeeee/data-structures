all: main.o bQueue.o
	g++ main.o bQueue.o -o lab10

main.o: main.cpp
	g++ -c main.cpp

bQueue.o: bQueue.h bQueue.cpp
	g++ -c bQueue.cpp

clean:
	rm -rf lab10 *.o *~
