all: main.o node.o linkedList.o hashTable.o
	g++ main.o node.o linkedList.o hashTable.o -o lab2

node.o: node.h node.cpp
	g++ -c -g node.cpp

main.o: main.cpp
	g++ -c -g main.cpp

linkedList.o: linkedList.h linkedList.cpp
	g++ -c -g linkedList.cpp

hashTable.o: hashTable.h hashTable.cpp
	g++ -c -g hashTable.cpp

clean:
	rm -rf *.o *~ lab2
