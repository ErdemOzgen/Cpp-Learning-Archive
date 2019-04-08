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

int main(int argc, const char *argv[]) {
    int a;
    int *aPtr;

    a = 7;
    aPtr = &a;

    std::cout << "The address of &a is " << &a << "\nThe value of aPtr is "
              << aPtr;

    std::cout << "\n\nThe value of a is " << a << "\nThe value of *aPtr is "
              << *aPtr;

    std::cout << "\n\nShowing that * and & are inverses of each other."
              << "\n&*aPtr = " << &*aPtr << "\n*&aPtr = " << *&aPtr
              << std::endl;
    return 0;
}
