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

template <typename T>
T maximum(T num1, T num2) {
    return (num1 > num2) ? num1 : num2;
}

int main(int argc, const char *argv[]) {
    std::cout << "Template testing using int, float and char" << std::endl;

    // int
    std::cout << "maximum(58, 78): " << maximum(58, 78) << std::endl;
    // char
    std::cout << "maximum('A', '#'): " << maximum('A', '#') << std::endl;
    // double
    std::cout << "maximum(1.359, 1.3598): " << maximum(1.359, 1.3598)
              << std::endl;

    return 0;
}
