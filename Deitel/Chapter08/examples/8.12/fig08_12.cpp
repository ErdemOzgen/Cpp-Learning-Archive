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
    int x = 5, y;

    // ptr is a constant pointer to a constant integer.
    // ptr always points to the same location; the integer at that location
    // cannot be modified
    const int *const ptr = &x;

    std::cout << *ptr << std::endl;

    *ptr = 7;  // error: *ptr is const; cannot assign new value
    ptr = &y;  // error: ptr is const; cannot assign new address.

    return 0;
}
