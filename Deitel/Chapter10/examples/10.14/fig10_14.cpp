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

class Test {
 public:
    Test(int = 0);

    void print() const;

 private:
    int x;
};

// constructor
Test::Test(int value) : x(value) {}

void Test::print() const {
    // implicitly use the this pointer to access the member x
    std::cout << "        x = " << x;

    // explicitly use the this pointer and the arrow operator
    // to access the member x
    std::cout << "\n  this->x = " << this->x;

    // explicitly use the dereferences this pointer and
    // the dot operator to access the member x
    std::cout << "\n(*this).x = " << (*this).x << std::endl;
}

int main(int argc, const char *argv[]) {
    Test testObject(12);

    testObject.print();
    return 0;
}
