/*
 * =============================================================================
 *
 *       Filename:  ex_2023.cpp
 *
 *    Description:  Exercise 20.23 - Binary Tree Search
 *
 *        Version:  1.0
 *        Created:  07/02/18 18:58:04
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =============================================================================
 */
#include <iostream>
#include <cstdlib>
#include <random>

#include "Tree.hpp"

static const int HEIGHT = 30;
static const int LIMIT = 100;

std::random_device rd;
std::mt19937 gen(rd());

/**
 * Generates random number.
 * @param int
 * @param in
 */
int getRandomNumber(int min, int max) {
    return std::uniform_int_distribution<int>{min, max}(gen);
}  // end method getRandomNumber

/**
 * This is the main method.
 * @param argc.
 * @param argv[].
 * @return int.
 */
int main(int argc, char* argv[]) {
    Tree<int> intTree;

    for (int i = 0; i < HEIGHT; ++i) {
        intTree.insertNode(getRandomNumber(0, LIMIT));
    }

    intTree.inOrderTraversal();

    std::cout << "Depth: " << Tree<int>::depth(intTree) << std::endl;

    int query = getRandomNumber(0, LIMIT);

    TreeNode<int>* result = intTree.binaryTreeSearch(query);

    printf("%d%sfound in tree.\n", query, ((result == nullptr) ? " not " : " "));

    return 0;
}  // end method main
