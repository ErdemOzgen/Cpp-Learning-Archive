/*
 * =============================================================================
 *
 *       Filename:  ex_2027.cpp
 *
 *    Description:  Exercise 20.27 - List and Queues without Tail Pointers.
 *
 *        Version:  1.0
 *        Created:  20/02/18 16:14:58
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =============================================================================
 */
#include <iostream>
#include <random>

#include "Queue.hpp"

/**
 * This is the main method.
 * @param argc.
 * @param argv[].
 * @return int.
 */
int main(int argc, char* argv[]) {
    Queue<int> q;

    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = 0; i < 30; ++i) {
        q.enqueue(std::uniform_int_distribution<int>{1, 100}(rd));
    }

    q.printQueue();

    return 0;
}  // end method main
