#include <iostream>
#include "Queue.hpp"

int main() {
  // Initialize:
  ArrayQueue<int> AQ(0);
  std::cout << AQ << std::endl;

  // Get front value
  try{AQ.front();}
  catch(QueueEmpty) {
    std::cout << "\"The queue is empty\" error is here!" << std::endl;
  }

  // Dequeue front value
  try{AQ.dequeue();}
  catch(QueueEmpty) {
    std::cout << "\"The queue is empty\" error is here!" << std::endl;
  }

  // Push some values into "zero-size" queue
  try{AQ.enqueue(1);}
  catch(QueueFull& qfe) {
    std::cout << "Error says: ";
    std::cout << qfe.getMessage() << std::endl;
  }

  // Redefine queue:
  AQ = ArrayQueue<int>(10);
  std::cout << AQ << std::endl;

  // Push some values:
  for (int i = 0; i < 10; i++) {
    AQ.enqueue(i*3);
  }
  std::cout << AQ << std::endl;

  // Pop some values:
  for (int i = 0; i < 4; i++) {
    AQ.dequeue();
  }
  std::cout << AQ << std::endl;

  // Push some values:
  AQ.enqueue(42);
  AQ.enqueue(24);
  AQ.dequeue();
  std::cout << AQ << std::endl;
}
