/*
 * =====================================================================================
 *
 *       Filename:  
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thanks to github you know it
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author: Mahmut Erdem ÖZGEN   m.erdemozgen@gmail.com
 *   
 *
 * =====================================================================================
 */#include <exception>
#include <iostream>

// throw, catch and rethrow exception
void throwException() {
    // throw exception and catch it immediately
    try {
        std::cout << "  Function throwException throws an exception\n";
        throw std::exception();
    } catch (std::exception &) {
        std::cout << "  Exception handled in function throwException"
                  << "\n  Function throwException rethrows exception";
        throw;  // rethrow exception for further processing
    }

    std::cout << "This also should not print\n";
}

int main(int argc, const char *argv[]) {
    // throw exception
    try {
        std::cout << "\nmain invokes function throwException\n";
        throwException();
        std::cout << "This should not print\n";
    } catch (std::exception &) {
        std::cout << "\n\nException handled in main\n";
    }

    std::cout << "Program control continues after catch in main\n";
    return 0;
}
