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
    int limit, num, total = 0;

    std::cout << "Enter number of values to be summed followed by values: ";
    std::cin >> limit;

    for (int i = 1; i <= limit; i++) {
        std::cin >> num;
        total += num;
    }

    std::cout << "Total = " << total << std::endl;
    return 0;
}
