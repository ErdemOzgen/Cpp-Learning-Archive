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
#include "SalaryCalculator.hpp"

static const int QUIT = -1;

int main(int argc, const char *argv[]) {
    SalaryCalculator sc;

    while (sc.getHoursWorked() != QUIT) {
        sc.run();
    }
    return 0;
}
