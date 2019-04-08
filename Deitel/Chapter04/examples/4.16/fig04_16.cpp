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
    int passes = 0;
    int failures = 0;
    int studentCounter = 1;
    int result;

    while (studentCounter <= 10) {
        std::cout << "Enter result (1 = pass, 2 = fail) ";
        std::cin >> result;

        if (result == 1) {
            passes++;
        } else {
            failures++;
        }

        studentCounter++;
    }

    std::cout << "Passed " << passes << "\nFailed " << failures << std::endl;

    // determine whether more than 8 students passed
    if (passes > 8) {
        std::cout << "Bonus to instructor!" << std::endl;
    }

    return 0;
}
