/*
 * =====================================================================================
 *
 *       Filename:  ex_2011.cpp
 *
 *    Description:  Exercise 20.11 - Palindrome Testing with Stacks
 *
 *        Version:  1.0
 *        Created:  13/06/17 13:44:42
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <ctype.h>
#include <iostream>
#include <stack>
#include <string>

int main(int argc, const char* argv[]) {
    std::string cData;
    std::string cSanitised;

    std::stack<char> cStack;

    std::cout << "Enter a string for palindrome test: ";
    std::getline(std::cin, cData);

    // sanitise data - remove spaces and punctuation
    for (char& c : cData) {
        if (isspace(c) || ispunct(c)) { continue; }

        cSanitised += tolower(c);
        cStack.push(tolower(c));
    }

    // build comparison string from stack
    std::string rData;

    while (!cStack.empty()) {
        rData += cStack.top();
        cStack.pop();
    }

    std::cout << cData << " is"
              << (rData == cSanitised ? " " : " not ")
              << "a palindrome" << std::endl;

    return 0;
}
