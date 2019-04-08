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
#include <math.h>
#include <iostream>

int roundToInteger(double);
int roundToTenths(double);
int roundToHundreths(double);
int roundToThousandths(double);

int main(int argc, const char *argv[]) {
    double num = 0.0f;

    std::cout << "Program to round numbers to int, 10s, 100 and 1000"
              << std::endl;

    while (num != -1) {
        std::cout << "Enter number to round (-1 to exit): ";
        std::cin >> num;

        std::cout << "Original: " << num
                  << "\nroundToInteger: " << roundToInteger(num)
                  << "\nroundToTenths: " << roundToTenths(num)
                  << "\nroundToHundredths: " << roundToHundreths(num)
                  << "\nroundToThousandths: " << roundToThousandths(num)
                  << std::endl;
    }
    return 0;
}
int roundToInteger(double num) { return floor(num + .5); }
int roundToTenths(double num) { return floor(num * 10 + .5) / 10; }
int roundToHundreths(double num) { return floor(num * 100 + .5) / 100; }
int roundToThousandths(double num) { return floor(num * 1000 + .5) / 1000; }
