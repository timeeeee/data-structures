#include "Timer.cpp"
#include <stdlib.h>
#include <iostream>
#include "leftistHeap.h"
#include "skewHeap.h"

int main() {
  int seedCount = 5;
  int seeds [] = {2, 3, 4, 5, 6};
  int sizeCount = 4;
  int sizes [] = {50000, 100000, 200000, 400000};
  double leftistBuildTimes[4];
  double leftistOpTimes[4];
  double skewBuildTimes[4];
  double skewOpTimes[4];
  int sample [410000];
  double duration;

  for (int sizeIndex = 0; sizeIndex < sizeCount; sizeIndex++) {
    // total times, so we can compute the averages at the end.
    double leftistBuildTotal = 0;
    double leftistOpTotal = 0;
    double skewBuildTotal = 0;
    double skewOpTotal = 0;
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

      // -------------------- Leftist Heap --------------------
      MinLeftistHeap leftistHeap;
      Timer leftistHeapBuildTimer;
      Timer leftistHeapOpTimer;
      // reseed, so that we get the same values for operations on both data structures
      srand(sample[0]);

      // Build leftist heap
      leftistHeapBuildTimer.start();
      for (int index = 0; index < size; index++) {
	leftistHeap.insert(sample[index]);
      }
      duration = leftistHeapBuildTimer.stop();
      std::cout << "    leftist heap build time: " << duration << std::endl;
      leftistBuildTotal += duration;

      // Perform operations
      leftistHeapOpTimer.start();
      for (int index = 0; index < (size / 10); index++) {
	int operation = sample[index] % 2;
	// int min;
	if (operation) {
	  // min = leftistHeap.deletemin();
	  leftistHeap.deletemin();
	} else {
	  int insertValue = random() % (4 * size);
	  leftistHeap.insert(insertValue);
	}
      }
      duration = leftistHeapOpTimer.stop();
      std::cout << "    leftist heap operation time: " << duration << std::endl;
      leftistOpTotal += duration;

      // -------------------- Skew Heap --------------------
      MinSkewHeap skewHeap;
      Timer skewHeapBuildTimer;
      Timer skewHeapOpTimer;
      // reseed, so that we get the same values for operations on both data structures
      srand(sample[0]);

      // Build skew heap
      skewHeapBuildTimer.start();
      for (int index = 0; index < size; index++) {
	skewHeap.insert(sample[index]);
      }
      duration = skewHeapBuildTimer.stop();
      std::cout << "    skew heap build time: " << duration << std::endl;
      skewBuildTotal += duration;

      // Perform operations
      skewHeapOpTimer.start();
      for (int index = 0; index < (size / 10); index++) {
	int operation = sample[index] % 2;
	// int min;
	if (operation) {
	  // min = skewHeap.deletemin();
	  skewHeap.deletemin();
	} else {
	  int insertValue = random() % (4 * size);
	  skewHeap.insert(insertValue);
	}
      }
      duration = skewHeapOpTimer.stop();
      std::cout << "    skew heap operation time: " << duration << std::endl;
      skewOpTotal += duration;
    }
    leftistBuildTimes[sizeIndex] = leftistBuildTotal / seedCount;
    leftistOpTimes[sizeIndex] = leftistOpTotal / seedCount;
    skewBuildTimes[sizeIndex] = skewBuildTotal / seedCount;
    skewOpTimes[sizeIndex] = skewOpTotal / seedCount;
  }

  std::cout << "average build time for leftist heap:\n";
  for (int size = 0; size < sizeCount; size ++) {
    std::cout << "  " << sizes[size] << ": " << leftistBuildTimes[size] << std::endl;
  }
  std::cout << "average operation time for leftist heap:\n";
  for (int size = 0; size < sizeCount; size ++) {
    std::cout << "  " << sizes[size] << ": " << leftistOpTimes[size] << std::endl;
  }
  std::cout << "average build time for skew heap:\n";
  for (int size = 0; size < sizeCount; size ++) {
    std::cout << "  " << sizes[size] << ": " << skewBuildTimes[size] << std::endl;
  }
  std::cout << "average operation time for skew heap:\n";
  for (int size = 0; size < sizeCount; size ++) {
    std::cout << "  " << sizes[size] << ": " << skewOpTimes[size] << std::endl;
  }
  
  return 0;
}
