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

//look BMI https://www.nhlbi.nih.gov/health/educational/lose_wt/BMI/bmicalc.htm
#include <iomanip>
#include <iostream>

#define BMI(w, h) ((w * 703) / (h * h))

// function declarations
void print_BMI_info();

int main(int argc, const char *argv[]) {
    double weight, height;

    std::cout << "Enter you weight in pounds: ";
    std::cin >> weight;

    std::cout << "Enter your height in inches: ";
    std::cin >> height;

    std::cout << std::setprecision(2) << std::fixed
              << "\nBMI: " << BMI(weight, height) << std::endl;

    print_BMI_info();

    return 0;
}
void print_BMI_info() {
    std::cout << "\nBMI VALUES" << std::endl;
    std::cout << "Underweight: less than 18.5" << std::endl;
    std::cout << "Normal:      between 18.5 and 24.9" << std::endl;
    std::cout << "Overweight:  between 25 and 29.9" << std::endl;
    std::cout << "Obese:       30 or greater\n" << std::endl;
}
