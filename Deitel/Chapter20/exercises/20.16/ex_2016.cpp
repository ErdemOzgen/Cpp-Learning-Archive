/*
 * =====================================================================================
 *
 *       Filename:  ex_2016.cpp
 *
 *    Description:  Exercise 20.16 - Allowing Duplicates in Binary Trees.
 *
 *        Version:  1.0
 *        Created:  18/07/17 12:49:48
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <iostream>
#include <iomanip>

#include "Tree.hpp"

/**
 * This is the main method.
 * @param argc.
 * @param argv[].
 * @return int.
 */
int main(int argc, const char* argv[]) {
    Tree<int> intTree;

    int intValue;

    std::cout << "Enter 10 integer values: ";

    // insert 10 integers to intTree
    for (int i = 0; i < 10; ++i) {
        std::cin >> intValue;
        intTree.insertNode(intValue);
    }

    std::cout << "\nPreorder traversal\n";
    intTree.preOrderTraversal();

    std::cout << "\nInorder traversal\n";
    intTree.inOrderTraversal();

    std::cout << "\nPostorder traversal\n";
    intTree.postOrderTraversal();

    return 0;
}
