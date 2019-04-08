/*
 * =============================================================================
 *
 *       Filename:  ex_2026.cpp
 *
 *    Description:  Exercise 20.26 - Insert/Delete Anywhere in a Linked List.
 *
 *        Version:  1.0
 *        Created:  20/02/18 14:28:45
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

#include "List.hpp"

/**
 * This is the main method.
 * @param argc.
 * @param argv[].
 * @return int.
 */
int main(int argc, char* argv[]) {
    List<int> intList;

    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = 0; i < 30; ++i) {
        intList.insertAtBack(std::uniform_int_distribution<int>{1, 100}(gen));
    }

    std::cout << "Before remove: " << std::endl;
    intList.print();
    std::cout << "size: " << intList.size() << std::endl;

    if (intList.remove(30)) {
        std::cout << "After Remove 30: " << std::endl;
        intList.print();
        std::cout << "size: " << intList.size() << std::endl;
    }

    ListNode<int>* nodePtr = intList.begin();

    intList.insert(nodePtr, 99);
    intList.insert(nodePtr->next(), 100);
    intList.insert(nodePtr, 69);
    intList.print();
    std::cout << "size: " << intList.size() << std::endl;

    return 0;
}  // end method main
