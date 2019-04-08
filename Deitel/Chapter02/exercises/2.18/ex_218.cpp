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

inline int MAX(int a, int b) { return (a > b) ? a : b; }//http://www.cplusplus.com/articles/2LywvCM9/

int main(int argc, const char *argv[]) {
    int num1, num2;

    std::cout << "Enter two integers: ";
    std::cin >> num1 >> num2;//http://www.cplusplus.com/reference/iostream/cin/?kw=cin

    if (num1 == num2) {
        std::cout << "These numbers are equal" << std::endl;
    } else {
        std::cout << MAX(num1, num2) << " is Larger." << std::endl;
    }
    return 0;
}
