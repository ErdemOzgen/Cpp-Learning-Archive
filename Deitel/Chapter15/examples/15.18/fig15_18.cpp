
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
    double x = 0.001234567;
    double y = 1.946e9;

    // display x and y in default format
    std::cout << "Displayed in default format:" << std::endl
              << x << '\t' << y << std::endl;

    // display x and y in scientific format
    std::cout << "\nDisplayed in scientific format:" << std::endl
              << std::scientific << x << '\t' << y << std::endl;

    // display x and y in fixed format
    std::cout << "\nDisplayed in fixed format:" << std::endl
              << std::fixed << x << '\t' << y << std::endl;

    return 0;
}
