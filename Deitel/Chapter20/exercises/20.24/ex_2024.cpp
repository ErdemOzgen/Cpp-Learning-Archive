/*
 * =============================================================================
 *
 *       Filename:  ex_2024.cpp
 *
 *    Description:  Exercise 20.24 - Level-Order Binary Tree Traversal.
 *
 *        Version:  1.0
 *        Created:  19/02/18 15:37:49
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
        intTree.insertNode(std::uniform_int_distribution<int>{0, 20}(gen));
    }

    std::cout << "\nPre Order Traversal:" << std::endl;
    intTree.preOrderTraversal();

    std::cout << "\nLevel Order Traversal:" << std::endl;
    intTree.levelOrderTraversal();

    return 0;
}  // end method main
