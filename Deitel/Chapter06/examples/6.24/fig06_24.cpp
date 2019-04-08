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

int square(int x) {
    std::cout << "square of integer " << x << " is ";
    return x * x;
}
double square(double y) {
    std::cout << "square of double " << y << " is ";
    return y * y;
}
int main(int argc, const char *argv[]) {
    std::cout << square(7);
    std::cout << std::endl;

    std::cout << square(7.5);
    std::cout << std::endl;
    return 0;
}
