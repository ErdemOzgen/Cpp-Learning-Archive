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

#include "CommissionEmployee.hpp"

// constructor
CommissionEmployee::CommissionEmployee(const std::string& first,
                                       const std::string& last,
                                       const std::string& ssn, Date dob,
                                       double sales, double rate)
    : Employee(first, last, ssn, dob) {
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
