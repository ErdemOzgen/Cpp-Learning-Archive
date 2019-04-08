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
#include <iomanip>
#include <iostream>

const double BASE_HOURS = 3.0f;
const double MINIMUM_FEE = 2.00f;
const double PART_CHARGE = 0.50f;
const double MAXIMUM_FEE = 10.0f;

double calculateCharges(double);

int main(int argc, const char *argv[]) {
    double hours1;
    double hours2;
    double hours3;

    std::cout << "Program to calculate parking charges for 3 cars\n"
              << std::endl;

    std::cout << "Enter hours parked of 3 cars: ";
    std::cin >> hours1 >> hours2 >> hours3;

    std::cout << "Car" << std::setw(15) << "Hours" << std::setw(15) << "Charge"
              << std::endl;

    double charges1 = calculateCharges(hours1);
    double charges2 = calculateCharges(hours2);
    double charges3 = calculateCharges(hours3);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "1" << std::setw(17) << hours1 << std::setw(10) << "$" << charges1
              << std::endl;
    std::cout << "2" << std::setw(17) << hours2 << std::setw(10) << "$" << charges2
              << std::endl;
    std::cout << "3" << std::setw(17) << hours3 << std::setw(10) << "$" << charges3
              << std::endl;
    std::cout << "TOTAL" << std::setw(13) << hours1 + hours2 + hours3
              << std::setw(10) << "$" << charges1 + charges2 + charges3 << std::endl;

    return 0;
}
// calculates the parking charge for the given number of hours
double calculateCharges(double hours) {
    if (hours >= 24) {
        return MAXIMUM_FEE;
    }
    if (hours <= BASE_HOURS) {
        return MINIMUM_FEE;
    }
    // only charge for each hour/part hour after BASE_HOURS
    double charge = MINIMUM_FEE + ((ceil(hours - BASE_HOURS)) * PART_CHARGE);

    return (charge <= MAXIMUM_FEE) ? charge : MAXIMUM_FEE;
}
