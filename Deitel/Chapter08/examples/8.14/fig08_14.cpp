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

size_t getSize(double *);

int main(int argc, const char *argv[]) {
    double array[20];

    std::cout << "The number of bytes in the array is " << sizeof(array);

    std::cout << "\nThe number of bytes return by getSize() is "
              << getSize(array) << std::endl;

    return 0;
}
// return size of ptr
size_t getSize(double *ptr) { return sizeof(ptr); }
