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
    int b[] = {10, 20, 30, 40};
    int *bPtr = b;

    // output array b using array subscript notation
    std::cout << "Array b printed with:\n\nArray subscript notation\n";

    for (int i = 0; i < 4; ++i) {
        std::cout << "b[" << i << "] = " << b[i] << std::endl;
    }

    // output array b using the array name and pointer/offset notation
    std::cout
        << "\nPointer/offset notation where the pointer is the array name\n";

    for (int offset1 = 0; offset1 < 4; ++offset1) {
        std::cout << "*(b + " << offset1 << ") = " << *(b + offset1)
                  << std::endl;
    }

    // output array b using bPtr and array subs cript notation
    std::cout << "\nPointer subscript notation" << std::endl;

    for (int i = 0; i < 4; ++i) {
        std::cout << "bPtr[" << i << "] = " << bPtr[i] << std::endl;
    }

    // output array b using bPtr and pointer/offset notation
    std::cout << "\nPointer/offset notation" << std::endl;

    for (int offset2 = 0; offset2 < 4; ++offset2) {
        std::cout << "*(bptr * " << offset2 << ") = " << *(bPtr + offset2)
                  << std::endl;
    }

    return 0;
}
