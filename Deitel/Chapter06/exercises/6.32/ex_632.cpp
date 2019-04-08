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

int qualityPoints(int);

int main(int argc, const char *argv[]) {
    int average = 0;

    std::cout << "Input student average: ";
    std::cin >> average;

    std::cout << "Quality Point: " << qualityPoints(average) << std::endl;

    return 0;
}
// returns int representation of a students average
int qualityPoints(int average) {
    if (average >= 90) {
        return 4;
    } else if (average >= 80) {
        return 3;
    } else if (average >= 70) {
        return 2;
    } else if (average >= 60) {
        return 1;
    } else {
        return 0;
    }
}
