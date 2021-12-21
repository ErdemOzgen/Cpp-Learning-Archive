#include <iostream>
#include "Queue.hpp"

int main() {
  // Initialize:
  LinkedQueue<int> LQ;
  std::cout << LQ << std::endl;

  // Get front value
  try{LQ.front();}
  catch(QueueEmpty) {
    std::cout << "\"The queue is empty\" error is here!" << std::endl;
  }

  // Dequeue front value
  try{LQ.dequeue();}
  catch(QueueEmpty) {
    std::cout << "\"The queue is empty\" error is here!" << std::endl;
  }

  // Push some values into "zero-size" queue
  try{LQ.enqueue(1);}
  catch(QueueFull& qfe) {	// There is no such thing in LinkedQueue
    std::cout << "Error says: ";
    std::cout << qfe.getMessage() << std::endl;
  }

  // Redefine queue:
  LQ = LinkedQueue<int>();
  std::cout << LQ << std::endl;

  // Push some values:
  for (int i = 0; i < 10; i++) {
    LQ.enqueue(i*3);
  }
  std::cout << LQ << std::endl;

  // Pop some values:
  for (int i = 0; i < 4; i++) {
    LQ.dequeue();
  }
  std::cout << LQ << std::endl;

  // Push some values:
  LQ.enqueue(42);
  LQ.enqueue(24);
  LQ.dequeue();
  std::cout << LQ << std::endl;
}
