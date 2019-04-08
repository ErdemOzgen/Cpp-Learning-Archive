/*
 * =====================================================================================
 *
 *       Filename:  ex_2019.cpp
 *
 *    Description:  Exercise 20.19 - Depth of a Binary Tree.
 *
 *        Version:  1.0
 *        Created:  18/07/17 16:55:12
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <iostream>

#include "Tree.hpp"

/**
 * This is the main method.
 * @param argc.
 * @param argv[].
 * @return int.
 */
int main(int argc, const char* argv[]) {
    static const int LIMIT = 10;

    Tree<int> intTree;

    std::cout << "Enter " << LIMIT << " integers: ";

    int value;
    for (int i = 0; i < LIMIT; ++i) {
        std::cin >> value;
        intTree.insertNode(value);
    }

    std::cout << "Depth of tree: " << Tree<int>::depth(intTree) << std::endl;

    return 0;
}  // end method main
