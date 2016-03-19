#include "Timer.cpp"
#include <stdlib.h>
#include <iostream>
#include "bst.h"
#include "minHeap.h"

int main() {
  int seedCount = 5;
  int seeds [] = {2, 3, 4, 5, 6};
  int sizeCount = 3;
  int sizes [] = {50000, 100000, 200000, 400000};
  int sample [410000];
  double duration;

  for (int sizeIndex = 0; sizeIndex < sizeCount; sizeIndex++) {
    int size = sizes[sizeIndex];
    std::cout << "Sample size " << size << ": \n";
    for (int seedIndex = 0; seedIndex < seedCount; seedIndex++) {
      int seed = seeds[seedIndex];
      std::cout << "  Seed = " << seed << ": \n";

      // Generate random data
      srand(seed);
      for (int index = 0; index < size; index++) {
	sample[index] = rand() % (4 * size) + 1;
      }

      // -------------------- BST --------------------
      BST bst;
      Timer bstBuildTimer;
      Timer bstOperationTimer;
      // reseed, so that we get the same values for operations on both data structures
      srand(sample[0]);

      // Build BST
      bstBuildTimer.start();
      for (int index = 0; index < size; index++) {
	bst.insert(sample[index]);
      }
      duration = bstBuildTimer.stop();
      std::cout << "    BST Build: " << duration << std::endl;
      
      // Perform operations
      bstOperationTimer.start();
      for (int index = 0; index < (size / 10); index++) {
	int operation = sample[index] % 4;
	int min, max;
	switch (operation) {
	case 0:
	  min = bst.deletemin();
	  break;
	case 1:
	  max = bst.deletemax();
	  break;
	case 2:
	  bst.remove(rand());
	  break;
	case 3:
	  bst.insert(rand());
	  break;
	}
      }
      duration = bstOperationTimer.stop();
      std::cout << "    BST operations: " << duration << std::endl;

      // -------------------- MinHeap --------------------
      MinHeap heap(5);
      Timer heapBuildTimer;
      Timer heapOperationTimer;
      // reseed, so that we get the same values for operations on both data structures
      srand(sample[0]);
      
      heapBuildTimer.start();
      heap.build(sample, size);
      duration = heapBuildTimer.stop();
      std::cout << "    Heap Build: " << duration << std::endl;

      // Perform operations
      heapOperationTimer.start();
      for (int index = 0; index < (size / 10); index++) {
	int operation = sample[index] % 4;
	int min, max;
	switch (operation) {
	case 0:
	  min = heap.deletemin();
	  break;
	case 1:
       	  max = heap.deletemax();
	  break;
	case 2:
	  heap.remove(rand());
	  break;
	case 3:
	  heap.insert(rand());
	  break;
	}
      }
      duration = heapOperationTimer.stop();
      std::cout << "    Heap operations: " << duration << std::endl;
    }
  }

  return 0;
}
