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
 */
#include <iostream>

// triples and returns n by value
inline int tripleByValue(int n) { return n * n * n; }
// triples and returns n by reference
inline int tripleByReference(const int& n) { return n * n * n; }

int main(int argc, const char* argv[]) {
    std::cout << "Demonstrating passing parameters by reference and value\n";

    int count = 3;

    std::cout << "tripleByValue = " << tripleByValue(count) << std::endl;
    std::cout << "tripleByReference = " << tripleByReference(count) << std::endl;

    return 0;
}
