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
    int x = 12345;

    // display x right justified (default)
    std::cout << "Default is right justified:" << std::endl
              << std::setw(10) << x;

    // use left manipulator to display x left justified
    std::cout << "\n\nUse std::left to left justify x:\n"
              << std::left << std::setw(10) << x;

    // use right manipulator to display x right justified
    std::cout << "\n\nUse std::right to right justify:\n"
              << std::right << std::setw(10) << x << std::endl;
    return 0;
}
