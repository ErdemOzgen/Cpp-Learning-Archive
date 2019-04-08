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
#include <iomanip>
#include <iostream>
#include <vector>

void outputVector(const std::vector<int>&);
void inputVector(std::vector<int>&);

int main(int argc, const char* argv[]) {
    std::vector<int> integers1(7);
    std::vector<int> integers2(10);

    // print integer1 size and contents
    std::cout << "Size of vector integers1 is " << integers1.size()
              << "\nvector after initialisation:" << std::endl;

    outputVector(integers1);

    // print integer2 size and contents
    std::cout << "\nSize of vector integer2 is " << integers2.size()
              << "\nvector after initialisation:" << std::endl;

    outputVector(integers2);

    // input and print integers1 and integers2
    std::cout << "\nEnter 17 integers: " << std::endl;
    inputVector(integers1);
    inputVector(integers2);

    std::cout << "\nAfter input, the vectors contain:\n"
              << "integers1:" << std::endl;
    outputVector(integers1);

    std::cout << "integers2:" << std::endl;
    outputVector(integers2);

    // use inequality operator with vector objects
    std::cout << "\nEvaluating: integers1 != integers2" << std::endl;

    if (integers1 != integers2) {
        std::cout << "integers1 and integers2 are not equal" << std::endl;
    }

    // create vector integers3 using integers1 as an initialiser; print size and
    // contents
    std::vector<int> integers3(integers1);

    std::cout << "\nSize of vector integers3 is " << integers3.size()
              << "\nvector after initialisation: " << std::endl;
    outputVector(integers3);

    // use overloaded assignment operator
    std::cout << "\nAssigning integers2 to integers1:" << std::endl;
    integers1 = integers2;

    std::cout << "integers1:" << std::endl;
    outputVector(integers1);

    std::cout << "integers2:" << std::endl;
    outputVector(integers2);

    // user equality operator with vector objects
    std::cout << "\nEvaluating: integers1 == integers2" << std::endl;

    if (integers1 == integers2) {
        std::cout << "integers1 and integers2 are equal" << std::endl;
    }

    // use square brackets to create rvalue
    std::cout << "\nintegers1[5] is " << integers1[5];

    // use square brackets to create lvalue
    std::cout << "\n\nAttempt to display integers1.at(15)" << std::endl;
    integers1[5] = 1000;
    std::cout << "integers1:" << std::endl;
    outputVector(integers1);

    // attempt to use out of range subscript
    try {
        std::cout << "\nAttempt to display integers1.at(15)" << std::endl;
        std::cout << integers1.at(15) << std::endl;
    } catch (std::out_of_range& ex) {
        std::cout << "An exception occured: " << ex.what() << std::endl;
    }

    return 0;
}
// output vector contents
void outputVector(const std::vector<int>& array) {
    size_t i;  // constrol variable

    for (i = 0; i < array.size(); ++i) {
        std::cout << std::setw(12) << array[i];

        if ((i + 1) % 4 == 0) { std::cout << std::endl; }
    }

    if (i % 4 != 0) { std::cout << std::endl; }
}
// input vector contents
void inputVector(std::vector<int>& array) {
    for (size_t i = 0; i < array.size(); ++i) {
        std::cin >> array[i];
    }
}
