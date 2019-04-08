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
    const int SIZE = 5;

    // a) declare array unsigned int 'values' with 5 elements
    //    and initialise the elements to even ints from 2 - 10.
    unsigned int values[SIZE] = {2, 4, 6, 8, 10};

    // b) declare a pointe 'vPtr' that points to an object of type unsigned int
    unsigned int *vPtr;

    // c) Use a for statement to print the elements of 'values' using array
    //    subscript notation
    for (int i = 0; i < SIZE; ++i) {
        std::cout << std::setw(4) << values[i];
    }

    std::cout << std::endl;

    // d) write two separate statments that assign the starting address of array
    //    'values' to pointer variable 'vPtr'
    vPtr = values;
    vPtr = &values[0];

    // e) use a for statement to print the elements of array 'values' using
    //    pointer/offset notation
    for (int i = 0; i < SIZE; ++i) {
        std::cout << std::setw(4) << *(vPtr + i);
    }

    std::cout << std::endl;

    // f) use a for statement to print the elements of array values using
    //    pointer/offset notation with the array name as the pointer
    for (int i = 0; i < SIZE; ++i) {
        std::cout << std::setw(4) << *(values + i);
    }

    std::cout << std::endl;

    // g) use a for statement to ptint the elements of array 'values' by
    //    subscripting the pointer to the array.
    for (int i = 0; i < SIZE; ++i) {
        std::cout << std::setw(4) << vPtr[i];
    }

    std::cout << std::endl;

    // h) refer to the 5th element of 'values' using array subscript notation,
    //    pointer/offset notation with the array name as the pointer.
    // values[4];
    // *(values + 4);

    // i) what address is referenced by vPtr + 3?
    //    what value is stored at that location
    std::cout << &*(vPtr + 3) << "\n" << *(vPtr + 3) << std::endl;

    // j) assuming that vPtr point to values[4]
    //    what address is referenced by vPtr -= 4?
    //    what value is stored at that location
    vPtr = &values[4];
    vPtr -= 4;

    std::cout << *vPtr << std::endl;

    return 0;
}
