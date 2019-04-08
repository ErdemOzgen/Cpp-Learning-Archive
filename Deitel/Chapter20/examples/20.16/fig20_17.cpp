/*
 * =====================================================================================
 *
 *       Filename:  fig20_17.cpp
 *
 *    Description:  Fig. 20.17 - Template Queue class test program
 *
 *        Version:  1.0
 *        Created:  14/03/17 15:02:57
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include "Queue.hpp"

#include <iostream>

int main(int argc, const char* argv[]) {
    Queue<int> intQueue;

    std::cout << "processing an integer Queue" << std::endl;

    // enqueue integers onto intQueue
    for (int i = 0; i < 3; ++i) {
        intQueue.enqueue(i);
        intQueue.printQueue();
    }

    int dequeueInteger;  // store dequeued integer

    // dequeue integers from intQueue
    while (!intQueue.isQueueEmpty()) {
        intQueue.dequeue(dequeueInteger);
        std::cout << dequeueInteger << " dequeued" << std::endl;
        intQueue.printQueue();
    }

    Queue<double> doubleQueue;

    double value = 1.1f;

    std::cout << "processing a double queue" << std::endl;

    // enqueue floating-point values onto doubleQueue
    for (int i = 0; i < 3; ++i) {
        doubleQueue.enqueue(value);
        doubleQueue.printQueue();
        value += 1.1f;
    }

    double dequeueDouble;  // store dequeued double

    // dequeue floating-point values from doubleQueue
    while (!doubleQueue.isQueueEmpty()) {
        doubleQueue.dequeue(dequeueDouble);
        std::cout << dequeueDouble << " dequeued" << std::endl;
        doubleQueue.printQueue();
    }

    return 0;
}
