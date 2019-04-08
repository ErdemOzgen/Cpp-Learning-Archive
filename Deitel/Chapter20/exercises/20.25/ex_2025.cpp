/*
 * =============================================================================
 *
 *       Filename:  ex_2025.cpp
 *
 *    Description:  Exercise 20.25 - Printing Trees
 *
 *        Version:  1.0
 *        Created:  20/02/18 13:33:36
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

#include "Tree.hpp"

/**
 * This is the main method.
 * @param argc.
 * @param argv[].
 * @return int.
 */
int main(int argc, char* argv[]) {
    Tree<int> intTree;

    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = 0; i < 10; ++i) {
        intTree.insertNode(std::uniform_int_distribution<int>{1, 100}(gen));
    }

    intTree.levelOrderTraversal();

    std::cout << std::endl;

    intTree.outputTree();

    return 0;
}  // end method main
