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
#include "BasePlusCommissionEmployee.hpp"

#include <iostream>

BasePlusCommissionEmployee::BasePlusCommissionEmployee(
    const std::string& first, const std::string& last, const std::string& ssn,
    double sales, double rate, double salary) {
    firstName = first;
    lastName = last;
    socialSecurityNumber = ssn;
    setGrossSales(sales);
    setCommissionRate(rate);
    setBaseSalary(salary);
}
// first name
void BasePlusCommissionEmployee::setFirstName(const std::string& first) {
    firstName = first;
}
std::string BasePlusCommissionEmployee::getFirstName() const {
    return firstName;
}
// last name
void BasePlusCommissionEmployee::setLastName(const std::string& last) {
    lastName = last;
}
std::string BasePlusCommissionEmployee::getLastName() const { return lastName; }
// social security number
void BasePlusCommissionEmployee::setSocialSecurityNumber(
    const std::string& ssn) {
    socialSecurityNumber = ssn;
}
std::string BasePlusCommissionEmployee::getSocialSecurityNumber() const {
    return socialSecurityNumber;
}
// gross sales
void BasePlusCommissionEmployee::setGrossSales(double sales) {
    if (sales >= 0.0f) {
        grossSales = sales;
    } else {
        throw std::invalid_argument("Gross sales muse be >= 0.0f");
    }
}
double BasePlusCommissionEmployee::getGrossSales() const { return grossSales; }
// commission rate
void BasePlusCommissionEmployee::setCommissionRate(double rate) {
    if (rate > 0.0f && rate < 1.0f) {
        commissionRate = rate;
    } else {
        throw std::invalid_argument(
            "Commission rate must be > 0.0f and < 1.0f");
    }
}
double BasePlusCommissionEmployee::getCommissionRate() const {
    return commissionRate;
}
// base salary
void BasePlusCommissionEmployee::setBaseSalary(double salary) {
    if (salary >= 0.0f) {
        baseSalary = salary;
    } else {
        throw std::invalid_argument("Salary must be >= 0.0f");
    }
}
double BasePlusCommissionEmployee::getBaseSalary() const { return baseSalary; }
// earnings
double BasePlusCommissionEmployee::earnings() const {
    return baseSalary + (commissionRate * grossSales);
}
// print
void BasePlusCommissionEmployee::print() const {
    std::cout << "base-salaried commission employee: " << firstName << ' '
              << lastName
              << "\nsocial security number: " << socialSecurityNumber
              << "\ngross sales: " << grossSales
              << "\ncommission rate: " << commissionRate
              << "\nbase salary: " << baseSalary;
}
