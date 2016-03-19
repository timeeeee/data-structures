all: main.o hashTable.o
	g++ main.o hashTable.o -o lab3

main.o: main.cpp
	g++ -c -g main.cpp

hashTable.o: hashTable.h hashTable.cpp
	g++ -c -g hashTable.cpp

clean:
	rm -rf *.o *~ lab3
