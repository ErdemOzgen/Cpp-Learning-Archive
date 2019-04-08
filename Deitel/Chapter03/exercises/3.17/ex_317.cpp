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
#include <string>

#include "HealthProfile.hpp"

int main(int argc, const char *argv[]) {
    std::string fName, lName, gender;
    int month, day, year;
    double weight, height;

    std::cout << "Enter your first and last name: ";
    std::cin >> fName >> lName;
    std::cout << "Enter your gender (Male/Female): ";
    std::cin >> gender;
    std::cout << "Enter your date of birth (mm dd yyyy): ";
    std::cin >> month >> day >> year;
    std::cout << "Enter your weight in pounds: ";
    std::cin >> weight;
    std::cout << "Enter your height in inches: ";
    std::cin >> height;

    HealthProfile hp(fName, lName, gender, month, day, year, height, weight);
    hp.showHealthProfile();

    return 0;
}
