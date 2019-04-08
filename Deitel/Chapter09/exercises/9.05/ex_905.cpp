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
#include "Complex.hpp"

int main(int argc, const char *argv[]) {
    Complex c1;
    Complex c2(123, 456);

    Complex c3 = (c1 + c2);

    std::cout << "c1: " << c1 << "\nc2: " << c2 << "\nc3: " << c3 << std::endl;

    return 0;
}
