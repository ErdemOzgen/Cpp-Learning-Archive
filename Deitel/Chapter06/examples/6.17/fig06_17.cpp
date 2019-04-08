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

void function1();
void function2(void);

int main(int argc, const char *argv[]) {
    function1();
    function2();

    return 0;
}
// function1 uses an empty paramter list to specify that the function receives
// no arguments
void function1() { std::cout << "function1 takes no arguments" << std::endl; }
// function2 uses a void paramter list to specify that the function receives
// no arguments
void function2(void) {
    std::cout << "function2 also takes no arguments" << std::endl;
}
