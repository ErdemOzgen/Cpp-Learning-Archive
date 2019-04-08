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
#include "Array.hpp"

#include <iostream>

int main(int argc, const char* argv[]) {
    Array integers1(7);  // 7 element array
    Array integers2;     // 10 element array by default

    // print integers1 size and contents
    std::cout << "Size of Array integers1 is " << integers1.getSize()
              << "\nArray after initialisation:\n"
              << integers1;

    // print integers2 size and contents
    std::cout << "Size of Array integers2 is " << integers2.getSize()
              << "\nArray after initialisation:\n"
              << integers2;

    // input and print integers1 and integers2
    std::cout << "\nEnter 17 integers:" << std::endl;
    std::cin >> integers1 >> integers2;

    std::cout << "\nAfter input, the Arrays contain:\n"
              << "integers1:\n"
              << integers1 << "integers2:\n"
              << integers2;

    // use overloaded inequality (!=) operator
    std::cout << "\nEvaluating: integers1 != integers2" << std::endl;

    if (integers1 != integers2) {
        std::cout << "integers1 and integers2 are not equal" << std::endl;
    }

    // create Array integers3 using integers1 as an
    // initialiser; print size and contents
    Array integers3(integers1);  // invokes copy constructor

    std::cout << "\nSize of Array integers3 is " << integers3.getSize()
              << "\nArray after initialisation:\n"
              << integers3;

    // use overloaded assignment (=) operator
    std::cout << "\nAssigning integers2 to integers1:" << std::endl;
    integers1 = integers2;  // note target Array is smaller

    std::cout << "integers1:\n" << integers1 << "integers2:\n" << integers2;

    // use overloaded equality (==) operator
    std::cout << "\nEvaluating: integers1 == integers2" << std::endl;

    if (integers1 == integers2) {
        std::cout << "integers1 and integers2 are equal" << std::endl;
    }

    // use overloaded subscript operator to create rvalue
    std::cout << "\nintegers1[5] is " << integers1[5];

    // use overloaded subscript operator to create lvalue
    std::cout << "\n\nAssigning 1000 to integers1[5]" << std::endl;
    integers1[5] = 1000;
    std::cout << "integers1:\n" << integers1;

    // attempt to use out-of-range subscript
    try {
        std::cout << "\nAttempt to assign 1000 to integers1[15]" << std::endl;
        integers1[15] = 1000;  // ERROR: subscript out of range
    } catch (std::out_of_range& ex) {
        std::cout << "An exception occured: " << ex.what() << std::endl;
    }

    return 0;
}
