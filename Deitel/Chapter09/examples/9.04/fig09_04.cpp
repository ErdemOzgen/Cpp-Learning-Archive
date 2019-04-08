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

// class Count definition
class Count {
 private:
    int x;

 public:
    void setX(int value) { x = value; }
    void print() { std::cout << x << std::endl; }
};

int main(int argc, const char *argv[]) {
    Count counter;
    Count *counterPtr = &counter;
    Count &counterRef = counter;

    std::cout << "Set x to 1 and print using the object's name: ";
    counter.setX(1);
    counter.print();

    std::cout << "Set x to 2 and print using a reference to an object: ";
    counterRef.setX(2);
    counterRef.print();

    std::cout << "Set x to 3 and print using a pointer to an object: ";
    counterPtr->setX(3);
    counterPtr->print();

    return 0;
}
