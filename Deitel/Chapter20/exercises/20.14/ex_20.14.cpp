/*
 * =====================================================================================
 *
 *       Filename:  ex_20.14.cpp
 *
 *    Description:  Exercise 20.14 - Postfix Evaluation Enhanced
 *
 *        Version:  1.0
 *        Created:  13/07/17 13:12:37
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
 * Calculates the expression x op y and returns the result.
 * @param x.
 * @param op.
 * @param y.
 * @return result.
 */
int calculate(const int& x, const char& op, const int& y) {
    switch (op) {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            return x / y;
        case '^':
            return x ^ y;
        case '%':
            return x % y;
        default:
            return 0;
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
 * Evaluates a postfix expression.
 * @param postfix.
 * @return result.
 */
int evaluatePostfixExpression(std::string& postfix) {
    Stack<int> postfixStack;

    // 1 - Read postfix from left to right
    for (std::string::iterator it = postfix.begin(); it != postfix.end(); ++it) {
        char& c = *it;

        // if char is digit.
        // add its integer value to temp and push onto the stack.
        // (value - value of '0')
        static int temp = 0;

        if (isdigit(c)) {
            temp = temp * 10 + (*it - '0');
        }
        // push temp onto stack and reset temp
        if (!isdigit(c) && temp > 0) {
            postfixStack.push(temp);
            temp = 0;
        }
        // if char is operator
        if (isOperator(c)) {
        // pop top two elements of the stack into x and y
        // calculate y operator x.
        // push results onto stack
            int x = postfixStack.stackTop();
            postfixStack.pop(postfixStack.stackTop());

            int y = postfixStack.stackTop();
            postfixStack.pop(postfixStack.stackTop());

            // swap x and y to avoid negative values
            if ((c == '/' || c == '-') && y > x) {
                    postfixStack.push(calculate(y, c, x));
            } else {
                postfixStack.push(calculate(x, c, y));
            }
        }
    }

    // 2 - On reaching end of postfix pop the top value of the stack.
    // this is the result of the postfix expression.
    return postfixStack.stackTop();
}

/**
 * This is the main method.
 * @param argc.
 * @param argv[].
 * @return int.
 */
int main(int argc, const char* argv[]) {
    std::string postfix;          // original expression

    std::cout << "Enter postfix expression: ";
    std::getline(std::cin, postfix);

    std::cout << evaluatePostfixExpression(postfix) << std::endl;

    return 0;
}
