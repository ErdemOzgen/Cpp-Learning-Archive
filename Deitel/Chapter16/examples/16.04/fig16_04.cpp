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

// function3 throws runtime error
void function3() throw(std::runtime_error) {
    std::cout << "In function 3" << std::endl;

    // no try block, stack unwinding occurs, return control to function2
    throw std::runtime_error("runtime_error in function 3");
}
// function2 invokes function 3
void function2() throw(std::runtime_error) {
    std::cout << "Function3 is called inside function2" << std::endl;
    function3();  // stack unwinding occurs, return control to function1
}
// function1 invokes function2
void function1() throw(std::runtime_error) {
    std::cout << "Function2 is called inside function1" << std::endl;
    function2();  // stack unwinding occurs, return control to main
}
// demonstrate stack unwinding
int main(int argc, const char *argv[]) {
    // invoke function1
    try {
        std::cout << "function1 is called inside main" << std::endl;
        function1();  // call function1 which throws runtime_error
    } catch (std::runtime_error &error) {
        std::cout << "Exception occured: " << error.what() << std::endl;
        std::cout << "Exception handled in main" << std::endl;
    }

    return 0;
}
