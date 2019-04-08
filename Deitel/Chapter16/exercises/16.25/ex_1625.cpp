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
#include <stdexcept>

class C1 {
 public:
    C1() { std::cout << "C1 Constructor" << std::endl; }
    ~C1() { std::cout << "C1 Destructor" << std::endl; }
};

class C2 {
 public:
    C2() { std::cout << "C2 Constructor" << std::endl; }
    ~C2() { std::cout << "C2 Destructor" << std::endl; }
};

class C3 {
 public:
    C3() {
        std::cout << "C3 Constructor" << std::endl;
        C1 c1;

        throw std::exception();

        C2 c2;
    }
    ~C3() { std::cout << "C3 Destructor" << std::endl; }
};

int main(int argc, const char *argv[]) {
    try {
        C3 c3;
    } catch (std::exception &e) {
        std::cout << "exception: " << e.what() << std::endl;
    }

    return 0;
}
