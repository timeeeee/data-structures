#include <iostream>
#include <fstream>
#include "disjointSet.h"
#include "minHeap.h"

int main() {
  std::ifstream infile;
  infile.open("data.txt");

  // First number in the file is the number of graphs given.
  int setCount;
  infile >> setCount;  
  for (int x = 0; x < setCount; x++) {
    int size;
    infile >> size;
    
    // Get lines and add them to heap
    // MinHeap(...) takes array of lines to build from, so create list first
    //   maximum number of lines is size * (siz - 1) but probably there will be less
    //   MinHeap(...) also takes size of array so it will just ignore empty lines
    Line *lines = new Line[size * (size - 1)];
    int count = 0;
    for (int start = 0; start < size; start++) {
      for (int end = 0; end < size; end++) {
	int length;
	infile >> length;
	// Only add lines if start < end so that we don't add the same line twice
	if (start < end && length > 0) {
	  lines[count] = Line(start, end, length);
	  count ++;
	}
      }
    }
    MinHeap heap(lines, count);
    delete [] lines;

    // For each line in heap, try to add it to the disjoint set
    // Count how many are added- once we hit count = size - 1, we can stop.
    DisjointSet set(size);
    Line *results = new Line[size - 1];
    count = 0;
    while (!heap.isEmpty() && count < size - 1) {
      // Get lowest priority (length) line and try to add it to disjoint set
      Line line = heap.deletemin();
      if (set.join(line.start, line.end)) {
	results[count] = line;
	count ++;
      }
    }

    std::cout << "Graph " << x + 1 << ":\n";
    for (int index = 0; index < count; index++) {
      std::cout << results[index];
      if (index < count - 1) std::cout << ", ";
    }
    std::cout << std::endl;

    delete [] results;
  }

  return 0;
}
