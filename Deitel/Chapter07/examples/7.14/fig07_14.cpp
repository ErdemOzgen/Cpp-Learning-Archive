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

void tryToModifyArray(const int[]);

int main(int argc, const char *argv[]) {
    int a[] = {10, 20, 30};

    tryToModifyArray(a);

    std::cout << a[0] << ' ' << a[1] << ' ' << a[2] << std::endl;

    return 0;
}
// In function tryToModifyArray, "b" cannot be used to modify the original array
// "a" in main
void tryToModifyArray(const int b[]) {
    b[0] /= 2;  // compilation error
}
