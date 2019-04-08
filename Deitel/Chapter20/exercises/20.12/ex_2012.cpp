/*
 * =====================================================================================
 *
 *       Filename:  ex_2012.cpp
 *
 *    Description:  Exercise 20.12 - Infix-to-Postfix Conversion
 *
 *        Version:  1.0
 *        Created:  13/06/17 15:24:42
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

#include "Stack.hpp"

/*
 * Tests whether given character is a valid arithmetic operation
 * @param   char        character to test
 * @return  bool        result
 */
bool isOperator(const char& c) {
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '%':
            return true;
            break;
        default:
            return false;
            break;
    }
}

/**
 * Checks whether the precedence of a is greater than b.
 * @param operator1.
 * @param operator2.
 * @return result.
 */
bool precedence(const char& operator1, const char& operator2) {
    switch (operator1) {
        case '+':
        case '-':
            return ((operator2 == '-') || (operator2 == '+'));
        case '*':
        case '/':
        case '%':
            return ((operator2 == '*') || (operator2 == '/') ||
                    (operator2 == '%') || (operator2 == '+') ||
                    (operator2 == '-'));
        case '^':
            return true;
        default:
            return false;
    }
}

/**
 * Converts the given expression to postfix notation.
 * @param infix.
 * @return postfix.
 */
std::string convertToPostfix(std::string& infix) {
    std::string postfix;        // final expression
    Stack<char> postfixStack;

    // 1 - push a left parenthesis onto the stack.
    postfixStack.push('(');

    // 2 - append a right parenthesis to the end of infix.
    infix += ')';

    // 3 - while stack is not empty, read infix from left to right
    for (char& c : infix) {
        // if the current char in infix is a digit, copy to next element in
        // postfix.
        if (isdigit(c)) { postfix += c; }

        // if the current char in infix is a left parenthesis, push it onto the
        // stack.
        if (c == '(') { postfixStack.push(c); }

        // if current char in infix is an operator.
        if (isOperator(c)) {
            // pop operators (if there are any) at the top of the stack while they
            // have equal or higher precedence than the current operator, and insert
            // popped operators in postfix.
            while (isOperator(postfixStack.stackTop())
                   && precedence(postfixStack.stackTop(), c)) {
                postfix += postfixStack.stackTop();
                postfixStack.pop(postfixStack.stackTop());
            }
            // push the current char in infix onto the stack.
            postfixStack.push(c);
        }
        // if current character in infix is a right parenthesis.
        // pop operators from the top of the stack and insert them in postfix
        // until a left parenthesis is at the top of the stack.
        if (c == ')') {
            while (postfixStack.stackTop() != '(') {
                postfix += postfixStack.stackTop();
                postfixStack.pop(postfixStack.stackTop());
            }
            // Pop (and discard) the left parenthesis from the stack
            postfixStack.pop(')');
        }
    }

    return postfix;
}
/**
 * This is the main method.
 * @param argc.
 * @param argv[].
 * @return int.
 */
int main(int argc, const char* argv[]) {
    std::string infix;          // original expression

    std::cout << "Enter infix expression: ";
    std::getline(std::cin, infix);

    std::cout << convertToPostfix(infix) << std::endl;

    return 0;
}
