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

int main(int argc, const char *argv[]) {
    long int value1 = 200000;
    long int value2;

    // a) declare a variable longPtr to be a pointer to a object of type long
    long int *longPtr;

    // b) assign the address of variable value1 to pointer variable long Ptr
    longPtr = &value1;

    // c) print the value of the object pointer to by longPtr
    std::cout << *longPtr << std::endl;

    // d) assign the value of the object pointed to by longPtr to variable
    // value2
    value2 = *longPtr;

    // e) print the value of value2
    std::cout << value2 << std::endl;

    // f) print the address of value1
    std::cout << &value1 << std::endl;

    // g) print the address sotred in longPtr
    std::cout << &longPtr << std::endl;

    return 0;
}
