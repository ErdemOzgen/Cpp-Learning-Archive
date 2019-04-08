/*
 * =====================================================================================
 *
 *       Filename:  ex_20.17.cpp
 *
 *    Description:  Exercise 20.17 - Binary Tree of Strings.
 *
 *        Version:  1.0
 *        Created:  18/07/17 13:26:50
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>
#include <sstream>

#include "Tree.hpp"

/**
 * This is the main method.
 * @param argc.
 * @param argv[].
 * @return int.
 */
int main(int argc, const char* argv[]) {
    Tree<std::string> strTree;

    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    std::istringstream ss(input);
    std::string parsed;

    while (ss >> parsed) { strTree.insertNode(parsed); }

    std::cout << std::endl;
    strTree.inOrderTraversal();
    std::cout << std::endl;
    strTree.preOrderTraversal();
    std::cout << std::endl;
    strTree.postOrderTraversal();
    std::cout << std::endl << std::endl;

    return 0;
}
