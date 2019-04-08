/*
 * =====================================================================================
 *
 *       Filename:  Queue.hpp
 *
 *    Description:  Fig. 20.16 - Template Queue class definition derived from
 *                  class List
 *
 *        Version:  1.0
 *        Created:  14/03/17 14:58:18
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#pragma once

#include "List.hpp"

template <typename QUEUETYPE>
class Queue : private List<QUEUETYPE> {
 public:
    // enqueue class List member function insertAtBack
    void enqueue(const QUEUETYPE &data) { this->insertAtBack(data); }
    // dequeue calls List member function removeFromFront
    bool dequeue(QUEUETYPE data) { return this->removeFromFront(data); }
    // isQueueEmpty calls List member function isEmpty
    bool isQueueEmpty() const { return this->isEmpty(); }
    // printQueue calls List member function print
    void printQueue() const { this->print(); }
    // queueFront returns the value at the front of the queue
    QUEUETYPE queueFront() const { return this->begin()->getData(); }
    // queueSize returns the length of the queue
    int queueSize() const { return this->size(); }
};
