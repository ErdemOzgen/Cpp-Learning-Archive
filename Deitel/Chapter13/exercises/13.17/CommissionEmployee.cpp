/*
 * =====================================================================================
 *
 *       Filename:  CommissionEmployee.cpp
 *
 *    Description:  Fig. 13.14: CommissionEmployee class member-function
 *                  definition.
 *
 *        Version:  1.0
 *        Created:  12/08/16 19:53:53
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>

#include "CommissionEmployee.hpp"

// constructor
CommissionEmployee::CommissionEmployee(const std::string& first,
                                       const std::string& last,
                                       const std::string& ssn, double sales,
                                       double rate)
    : Employee(first, last, ssn) {
    setGrossSales(sales);
    setCommissionRate(rate);
}
// set gross sales amount
void CommissionEmployee::setGrossSales(double sales) {
    if (sales >= 0.0f) {
        grossSales = sales;
    } else {
        throw std::invalid_argument("Gross sales must be >= 0.0f.");
    }
}
// return gross sales amount
double CommissionEmployee::getGrossSales() const { return grossSales; }
// set commission rate
void CommissionEmployee::setCommissionRate(double rate) {
    if (rate > 0.0f && rate < 1.0f) {
        commissionRate = rate;
    } else {
        throw std::invalid_argument(
            "Commission rate must be > 0.0f and < 1.0f.");
    }
}
// return commission rate
double CommissionEmployee::getCommissionRate() const { return commissionRate; }
// calculate earnings:
// override pure virtual function earnings in Employee
double CommissionEmployee::earnings() const {
    return getCommissionRate() * getGrossSales();
}
// print CommissionEmployee's information
void CommissionEmployee::print() const {
    std::cout << "commission employee: ";
    Employee::print();  // code reuse
    std::cout << "\ngross sales: " << getGrossSales()
              << ": commission rate: " << getCommissionRate();
}
