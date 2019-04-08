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
#include "SalesCommissionCalculator.hpp"

SalesCommissionCalculator::SalesCommissionCalculator() {}
SalesCommissionCalculator::~SalesCommissionCalculator() {}

// SETTERS
void SalesCommissionCalculator::setWeeklySales(double sales) {
    weeklySales = sales;
}
void SalesCommissionCalculator::setWeeklyEarnings() {
    weeklyEarnings = BASEPAY + (getWeeklySales() * COMMISSION);
}
// GETTERS
double SalesCommissionCalculator::getWeeklySales() const { return weeklySales; }
double SalesCommissionCalculator::getWeeklyEarnings() const { return weeklyEarnings; }
void SalesCommissionCalculator::run() {
    double dtmp = 0.0f;

    std::cout << "Enter sales in dollars (-1 to end): ";
    std::cin >> dtmp;

    setWeeklySales(dtmp);

    if (getWeeklySales() != -1) {
        setWeeklyEarnings();

        std::cout << "Salary is: $" << getWeeklyEarnings() << std::endl;
    }
}
