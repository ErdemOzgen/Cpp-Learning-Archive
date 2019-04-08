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

// detemine the smallest of two arguments
template <typename T>
T minimum(T num1, T num2) {
    return (num1 < num2) ? num1 : num2;
}

int main(int argc, const char *argv[]) {
    std::cout << "Template testing using int, char and float" << std::endl;

    // int
    std::cout << "minimum(91,78): " << minimum(91, 78) << std::endl;
    // char
    std::cout << "minimum(x, G): " << minimum('x', 'G') << std::endl;
    // float
    std::cout << "minimum(61.25, 68.5): " << minimum(61.25, 68.5) << std::endl;

    return 0;
}
