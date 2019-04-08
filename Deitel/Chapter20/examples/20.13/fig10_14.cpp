/*
 * =====================================================================================
 *
 *       Filename:  fig10_14.cpp
 *
 *    Description:  Fig. 20.14 - Template Stack class test program.
 *
 *        Version:  1.0
 *        Created:  14/03/17 12:49:35
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include "Stack.hpp"

#include <iostream>

int main(int argc, const char* argv[]) {
    Stack<int> intStack;

    std::cout << "Processing an integer stack" << std::endl;

    // push integers onto intStack
    for (int i = 0; i < 3; ++i) {
        intStack.push(i);
        intStack.printStack();
    }

    int popInteger;  // store int popped from stack

    // pop integers from intStack
    while (!intStack.isStackEmpty()) {
        intStack.pop(popInteger);
        std::cout << popInteger << " popped from stack" << std::endl;
        intStack.printStack();
    }

    Stack<double> doubleStack;
    double value = 1.1f;

    std::cout << "Processing a double stack" << std::endl;

    // push floating-point values onto doubleStack
    for (int i = 0; i < 3; ++i) {
        doubleStack.push(value);
        doubleStack.printStack();
        value += 1.1f;
    }

    double popDouble;  // store double popped from stack

    // pop floating-point values from doubleStack
    while (!doubleStack.isStackEmpty()) {
        doubleStack.pop(popDouble);
        std::cout << popDouble << " popped from stack." << std::endl;
        doubleStack.printStack();
    }

    return 0;
}
