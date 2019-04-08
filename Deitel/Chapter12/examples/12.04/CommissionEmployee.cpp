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
#include "CommissionEmployee.hpp"

#include <iostream>

CommissionEmployee::CommissionEmployee(const std::string& first,
                                       const std::string& last,
                                       const std::string& ssn, double sales,
                                       double rate) {
    firstName = first;
    lastName = last;
    socialSecurityNumber = ssn;
    setGrossSales(sales);
    setCommissionRate(rate);
}
// first name
void CommissionEmployee::setFirstName(const std::string& first) {
    firstName = first;
}
std::string CommissionEmployee::getFirstName() const { return firstName; }
// last name
void CommissionEmployee::setLastName(const std::string& last) {
    lastName = last;
}
std::string CommissionEmployee::getLastName() const { return lastName; }
// social security number
void CommissionEmployee::setSocialSecurityNumber(const std::string& ssn) {
    socialSecurityNumber = ssn;
}
std::string CommissionEmployee::getSocialSecurityNumber() const {
    return socialSecurityNumber;
}
// gross sales
void CommissionEmployee::setGrossSales(double sales) {
    if (sales >= 0.0f) {
        grossSales = sales;
    } else {
        throw std::invalid_argument("Gross sales must be >= 0.0f");
    }
}
double CommissionEmployee::getGrossSales() const { return grossSales; }
// commission rate
void CommissionEmployee::setCommissionRate(double rate) {
    if (rate > 0.0f && rate < 1.0f) {
        commissionRate = rate;
    } else {
        throw std::invalid_argument(
            "Commission rate must be > 0.0f and < 1.0f");
    }
}
double CommissionEmployee::getCommissionRate() const { return commissionRate; }
// calculate earnings
double CommissionEmployee::earnings() const {
    return commissionRate * grossSales;
}
// print CommissionEmployee object
void CommissionEmployee::print() const {
    std::cout << "commission employee: " << firstName << ' ' << lastName
              << "\nsocial security number: " << socialSecurityNumber
              << "\ngross sales: " << grossSales
              << "\ncommission rate: " << commissionRate;
}
