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

inline int AVERAGE(int a, int b) { return (a / b); };

static const int EXIT = 9999;

int main(int argc, const char *argv[]) {
    int counter = 0;
    int sum = 0;

    std::cout
        << "Enter a list of space separated integers for average calculation. "
        << EXIT << " ends input\n> ";
    std::cin >> sum;

    // set i as input to ensure exit condition
    // increment counter as opposed i
    for (int i = 0; i != EXIT; counter++) {
        sum += i;
        std::cin >> i;
    }

    std::cout << "Average: " << AVERAGE(sum, counter) << std::endl;
    return 0;
}
