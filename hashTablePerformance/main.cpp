#include "Timer.cpp"
#include <stdlib.h>
#include <iostream>
#include "openHashTable.h"
#include "closedHashTable.h"

int main() {
  int tableSize = 600011;
  for (int loadFactor = 2; loadFactor < 6; loadFactor ++) {
    int keys = loadFactor * tableSize / 10;
    std::cout << "Load factor ." << loadFactor << ", keys = " << keys << ":\n";
    
    std::cout << "  Open hash table:\n    ";
    double totalTime = 0;
    for (int seed = 1; seed < 6 ; seed ++) {
      Timer timer;
      timer.start();
      srand(seed + 5 * loadFactor);
      OpenHashTable openTable(tableSize);
      for (int x = 0; x < keys; x++) {
        openTable.insert(rand());
      }
      double duration = timer.stop();
      std::cout << duration << " ";
      totalTime += duration;
    }
    std::cout << "\n    Average: " << totalTime / 5 << std::endl;

    totalTime = 0;
    std::cout << "  Closed hash table, linear probing:\n    ";
    totalTime = 0;
    for (int seed = 1; seed < 6 ; seed ++) {
      Timer timer;
      timer.start();
      srand(seed + 5 * loadFactor);
      ClosedHashTableLinearProbing linearTable(tableSize);
      for (int x = 0; x < keys; x++) {
        linearTable.insert(rand());
      }
      double duration = timer.stop();
      std::cout << duration << " ";
      totalTime += duration;
    }
    std::cout << "\n    Average: " << totalTime / 5 << std::endl;

    std::cout << "  Closed hash table, quadratic probing:\n    ";
    totalTime = 0;
    for (int seed = 1; seed < 6 ; seed ++) {
      Timer timer;
      timer.start();
      srand(seed + 5 * loadFactor);
      ClosedHashTableQuadraticProbing quadraticTable(tableSize);
      for (int x = 0; x < keys; x++) {
        quadraticTable.insert(rand());
      }
      double duration = timer.stop();
      std::cout << duration << " ";
      totalTime += duration;
    }
    std::cout << "\n    Average: " << totalTime / 5 << std::endl;
  }

  return 0;
}
