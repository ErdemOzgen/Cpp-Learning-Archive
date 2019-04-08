/*
 * =====================================================================================
 *
 *       Filename:  fig20_22.cpp
 *
 *    Description:  Fig. 20.22 - Tree class test program
 *
 *        Version:  1.0
 *        Created:  14/03/17 16:05:34
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include "Tree.hpp"

#include <iomanip>
#include <iostream>

int main(int argc, const char* argv[]) {
    Tree<int> intTree;

    int intValue;

    std::cout << "Enter 10 integer values:\n";

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

    Tree<double> doubleTree;

    double doubleValue;

    std::cout << std::fixed << std::setprecision(1)
              << "\n\n\nEnter 10 double values:\n";

    // insert 10 doubleegers to doubleTree
    for (int i = 0; i < 10; ++i) {
        std::cin >> doubleValue;
        doubleTree.insertNode(doubleValue);
    }

    std::cout << "\nPreorder traversal\n";
    doubleTree.preOrderTraversal();

    std::cout << "\nInorder traversal\n";
    doubleTree.inOrderTraversal();

    std::cout << "\nPostorder traversal\n";
    doubleTree.postOrderTraversal();

    std::cout << std::endl;

    return 0;
}
