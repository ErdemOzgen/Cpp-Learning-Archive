/*
 * =====================================================================================
 *
 *       Filename:  HourlyWorker.cpp
 *
 *    Description:  Exercise 13.17 - Payroll System Modification
 *
 *        Version:  1.0
 *        Created:  01/09/16 21:48:29
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <string>

#include "HourlyWorker.hpp"

HourlyWorker::HourlyWorker(const std::string& first, const std::string& last,
                           const std::string& ssn, double hours, double wage)
    : Employee(first, last, ssn) {
    setHours(hours);
    setWage(wage);
}
// set hours
void HourlyWorker::setHours(double h) {
    if (h >= 0.0f) {
        hours = h;
    } else {
        throw std::invalid_argument("Hours must be >= 0.0f");
    }
}
// get hours
double HourlyWorker::getHours() const { return hours; }
// set wage
void HourlyWorker::setWage(double w) {
    if (w > 0.0f) {
        wage = w;
    } else {
        throw std::invalid_argument("Wage must be > 0.0f");
    }
}
// get wage
double HourlyWorker::getWage() const { return wage; }
// calculate earnings
double HourlyWorker::earnings() const {
    return ((getHours() < BASE_HOURS)
                ? (getHours() * getWage())
                : ((BASE_HOURS * getWage()) +
                   ((getHours() - BASE_HOURS) * (getWage() * OVERTIME_RATE))));
}
// print HourlyWorker's information
void HourlyWorker::print() const {
    std::cout << "Hourly Worker: ";
    Employee::print();
    std::cout << "\nHourly Rate: $" << getWage() << "\nHours: " << getHours()
              << std::endl;
}
