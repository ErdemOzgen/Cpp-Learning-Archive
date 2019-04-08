/*
 * =====================================================================================
 *
 *       Filename:  ex_2015.cpp
 *
 *    Description:  Exercise 20.15 - Supermarket Simulation.
 *
 *        Version:  1.0
 *        Created:  13/07/17 15:34:57
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <iostream>
#include <random>

#include "Queue.hpp"

std::random_device rd;
std::mt19937 gen(rd());

/**
 * Returns random n + random int (1-4)
 * @param n.
 * @return result.
 */
int getTime(int n) {
    return n + std::uniform_int_distribution<int>{1, 4}(gen);
}

/**
 * This is the main method.
 * @param argc.
 * @param argv[].
 * @return int.
 */
int main(int argc, const char* argv[]) {
    Queue<int> checkout;

    // 1 - Choose a random int 1 - 4 to determine the minute at which the first
    // customer arrives.
    int arrivalTime = getTime(0);
    int maxQueueSize = 0;  // maximum number of customer's in queue

    // run for 720 minutes
    for (int m = 1; m <= 720; ++m) {
        static int serviceTime = 0;  // time to service current customer.

        // 2 - At arrival time
        if (m == arrivalTime) {
            static int customer = 0;     // number of customers

            // enqueue customer
            checkout.enqueue(++customer);

            printf("%3d - Customer %3d arrived\n", m, customer);

            // first customer service time
            if (serviceTime == 0) { serviceTime = getTime(m); }

            // schedule arrival of next customer.
            arrivalTime = getTime(m);
        }

        // if service completed for last customer
        if (m == serviceTime) {
            printf("%3d - Customer %3d serviced\n", m, checkout.queueFront());

            // dequeue customer.
            checkout.dequeue(checkout.queueFront());

            // schedule service time if more customers
            if (!checkout.isQueueEmpty()) {
                serviceTime = getTime(m);
            } else {
                serviceTime = 0;
            }
        }

        // get max queue size
        if (maxQueueSize == 0 || checkout.queueSize() > maxQueueSize) {
            maxQueueSize = checkout.queueSize();
        }
    }

    printf("Max queue size: %d\n", maxQueueSize);

    // TODO(me): figure out a way of getting longs wait times easily.

    return 0;
}
