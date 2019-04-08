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

bool function3() {
    std::cout << "function3 called" << std::endl;
    return (true != true) ? true : throw std::runtime_error("function3");
}
bool function2() {
    std::cout << "function2 called" << std::endl;
    return false;
}
bool function1() {
    std::cout << "function1 called" << std::endl;
    return function2() == function3();
}

int main(int argc, const char *argv[]) {
    try {
        function1();
    } catch (std::runtime_error &e) {
        std::cout << "Exception occured: " << e.what() << std::endl;
    }

    return 0;
}
