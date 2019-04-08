/*
 * =====================================================================================
 *
 *       Filename:  ex_2010.cpp
 *
 *    Description:  Exercise 20.10 - Printing a Sentence in Reverse Order With
 *                  a Stack
 *
 *        Version:  1.0
 *        Created:  13/06/17 13:29:49
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <iostream>
#include <stack>
#include <string>

int main(int argc, const char* argv[]) {
    std::string cData;

    std::cout << "Enter a sentence: ";
    std::getline(std::cin, cData);

    std::stack<char> cStack;

    // add data to stack
    for (char& c : cData) { cStack.push(c); }

    // read stack in reverse order
    while (!cStack.empty()) {
        std::cout << cStack.top();
        cStack.pop();
    }

    std::cout << std::endl;

    return 0;
}
